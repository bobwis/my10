
/*CODE_BLOCK_BEGIN[LMM001.h]*/



// ----------------------------------------------------------------------------
// umm_malloc.h - a memory allocator for embedded systems (microcontrollers)
//
// See copyright notice in LICENSE.TXT
// ----------------------------------------------------------------------------

/**************************************************************************//**
 *
 * Copyright (C) 2011 Infineon Technologies AG. All rights reserved.
 *
 * Infineon Technologies AG (Infineon) is supplying this software for use with
 * Infineon�s microcontrollers.
 * This file can be freely distributed within development tools that are
 * supporting such microcontrollers.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
********************************************************************************/
#ifndef UMM_MALLOC_H
#define UMM_MALLOC_H


/*******************************************************************************
**                      INCLUDE FILES                           			  **
*******************************************************************************/
#include <DAVE3.h>
#include "lmm001_debuglog.h"
#include "string.h"

// ----------------------------------------------------------------------------
// A couple of macros to make packing structures less compiler dependent

#define UMM_H_ATTPACKPRE
#define UMM_H_ATTPACKSUF __attribute__((__packed__))

// ----------------------------------------------------------------------------
// A couple of macros to make it easier to protect the memory allocator
// in a multitasking system. You should set these macros up to use whatever
// your system uses for this purpose. You can disable interrupts entirely, or
// just disable task switching - it's up to you
//
// NOTE WELL that these macros MUST be allowed to nest, because umm_free() is
// called from within umm_malloc()


#define LMM001_CRITICAL_ENTRY() __disable_irq()
#define LMM001_CRITICAL_EXIT()__enable_irq()

// ----------------------------------------------------------------------------
#ifdef LMM001_DEBUG
typedef struct LMM001_HEAPINFOType {
  uint16_t totalEntries;
  uint16_t usedEntries;
  uint16_t freeEntries;

  uint16_t totalBlocks;
  uint16_t usedBlocks;
  uint16_t freeBlocks;
  }
  LMM001_HEAPINFOType;
#endif

UMM_H_ATTPACKPRE typedef struct LMM001_ptr {
  uint16_t next;
  uint16_t prev;
} UMM_H_ATTPACKSUF LMM001_ptr;


/**
 * @ingroup LMM001_publicparam
 * @{
 */

#if   defined ( __CC_ARM )
UMM_H_ATTPACKPRE typedef struct LMM001_BlockType {
/**
 * This stores the information for used blocks.
 */
 __packed union {
	  LMM001_ptr used;
  } header;

/**
* This stores the information for free blocks.
*/
 __packed union {
	  LMM001_ptr free;
    uint8_t data[4];
  } body;
} UMM_H_ATTPACKSUF LMM001_BlockType;
#else
UMM_H_ATTPACKPRE typedef struct LMM001_BlockType {
/**
 * This stores the information for used blocks.
 */
 union {
	  LMM001_ptr used;
  } header;

/**
* This stores the information for free blocks.
*/
 union {
	  LMM001_ptr free;
    uint8_t data[4];
  } body;
} UMM_H_ATTPACKSUF LMM001_BlockType;
#endif

/**
 * This structure contains the control parameters for the memory manager instance.
 * It contains heap and size of heap.
 */
UMM_H_ATTPACKPRE typedef struct LMM001_HandleType{
#ifdef LMM001_DEBUG
  LMM001_HEAPINFOType heapInfo;
#endif
/**
 * Heap : The structure of type LMM001_BlockType
 */
  LMM001_BlockType *umm_heap;
/**
 * Size of Heap in number of blocks
 */
  uint16_t umm_numblocks;
  } UMM_H_ATTPACKSUF LMM001_HandleType;
/**
* @}
*/

#ifdef LMM001_DEBUG
extern LMM001_HEAPINFOType heapInfo;
#endif

/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/
/**
 * @ingroup LMM001_apidoc
 * @{
 */
/**
 * @brief The function deallocates the memory pointed by Memptr.
 * @param[in]   HandlePtr  Pointer to LMM001_HandleType Structure.
 * @param[in]   MemPtr  Memory pointer
 * @return void
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 * #include <DAVE3.h>
 * #include "string.h"
 * int main(void)
 * {
 *   void * MemPointer = 0;
 *   LMM001_HandleType LMM001_handle;
 *   LMM001_BlockType _umm_heap_1[256];
 *   LMM001_handle.umm_heap = &_umm_heap_1[0];
 *   LMM001_handle.umm_numblocks = 256;
 *   memset (_umm_heap_1, 0, sizeof(_umm_heap_1));
 *   uint32_t Startheap = (uint32_t)_umm_heap_1;
 *   uint32_t Endheap = (((uint32_t)_umm_heap_1) + (256 * sizeof(LMM001_BlockType)));
 *   
 *   DAVE_Init();
 *   MemPointer = LMM001_malloc(&LMM001_handle, 64);
 *
 *  if (((uint32_t)MemPointer >= Startheap) && ((uint32_t)MemPointer <= Endheap) && (MemPointer != NULL))
 *  {
 *    LMM001_free(&LMM001_handle, MemPointer);
 *  }
 *   return 0;
 * }
 * @endcode<BR> </p>
 */
void LMM001_free( LMM001_HandleType *HandlePtr,void *MemPtr );

/**
 * @brief The function allocates memory of 'size'number of bytes.
 * @param[in]   HandlePtr  Pointer to LMM001_HandleType Structure.
 * @param[in]   size  size in number of bytes
 * @return void
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 * #include <DAVE3.h>
 * #include "string.h"
 * int main(void)
 * {
 *   void * MemPointer = 0;
 *   LMM001_HandleType LMM001_handle;
 *   LMM001_BlockType _umm_heap_1[256];
 *   LMM001_handle.umm_heap = &_umm_heap_1[0];
 *   LMM001_handle.umm_numblocks = 256;
 *   memset (_umm_heap_1, 0, sizeof(_umm_heap_1));
 *   uint32_t Startheap = (uint32_t)_umm_heap_1;
 *   uint32_t Endheap = (((uint32_t)_umm_heap_1) + (256 * sizeof(LMM001_BlockType)));
 *
 *  DAVE_Init(); 
 *  MemPointer = LMM001_malloc(&LMM001_handle, 64);
 *
 *  if (((uint32_t)MemPointer >= Startheap) && ((uint32_t)MemPointer <= Endheap) && (MemPointer != NULL))
 *  {
 *    LMM001_free(&LMM001_handle, MemPointer);
 *  }
 *   return 0;
 * }
 * @endcode<BR> </p>
*/
void *LMM001_malloc( LMM001_HandleType *HandlePtr, uint32_t size );

/**
 * @brief  This function changes the size of a block of memory that was previously allocated with malloc().
 * @param[in]   HandlePtr  Pointer to LMM001_HandleType Structure.
 * @param[in]   MemPtr  Pointer to the original block of memory.
 * @param[in]   size  new size in number of bytes
 * @return void
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 * #include <DAVE3.h>
 * #include "string.h"
 * int main(void)
 * {
 *   void * MemPointer = 0;
 *   LMM001_HandleType LMM001_handle;
 *   LMM001_BlockType _umm_heap_1[256];
 *   LMM001_handle.umm_heap = &_umm_heap_1[0];
 *   LMM001_handle.umm_numblocks = 256;
 *   memset (_umm_heap_1, 0, sizeof(_umm_heap_1));
 *   uint32_t Startheap = (uint32_t)_umm_heap_1;
 *   uint32_t Endheap = (((uint32_t)_umm_heap_1) + (256 * sizeof(LMM001_BlockType)));
 *
 *   DAVE_Init();
 *   MemPointer = LMM001_realloc(&LMM001_handle, MemPointer, 64);
 *
 *  if (((uint32_t)MemPointer >= Startheap) && ((uint32_t)MemPointer <= Endheap) && (MemPointer != NULL))
 *  {
 *    LMM001_free(&LMM001_handle, MemPointer);
 *  }
 *   return 0;
 * }
 * @endcode<BR> </p>
 */
void *LMM001_realloc(LMM001_HandleType *HandlePtr, void * MemPtr, uint32_t size );

/**
 * @}
 */

#endif // UMM_MALLOC_H
/*CODE_BLOCK_END*/
