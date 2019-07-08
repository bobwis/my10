
/*CODE_BLOCK_BEGIN[gmm001.c]*/
/*******************************************************************************
 Copyright (c) 2011, Infineon Technologies AG                                 **
 All rights reserved.                                                         **
                                                                              **
 Redistribution and use in source and binary forms, with or without           **
 modification,are permitted provided that the following conditions are met:   **
                                                                              **
 *Redistributions of source code must retain the above copyright notice,      **
 this list of conditions and the following disclaimer.                        **
 *Redistributions in binary form must reproduce the above copyright notice,   **
 this list of conditions and the following disclaimer in the documentation    **
 and/or other materials provided with the distribution.                       **
 *Neither the name of the copyright holders nor the names of its contributors **
 may be used to endorse or promote products derived from this software without** 
 specific prior written permission.                                           **
                                                                              **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  **
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **
 ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **
 LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **
 SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **
 CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **
 POSSIBILITY OF SUCH DAMAGE.                                                  **
                                                                              **
 To improve the quality of the software, users are encouraged to share        **
 modifications, enhancements or bug fixes with Infineon Technologies AG       **
 dave@infineon.com).                                                          **
                                                                              **
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4000 Series                           			  **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR : App Developer                                         		      **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Dec 27, 2011                                           **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials   Name                                                            **
** ---------------------------------------------------------------------------**
** kks        App Developer                                                   **
*******************************************************************************/

/**
 * @file GMM001.c
 *
 * @brief This file implements the APIs for GMM001 App.
 *
 */

/*******************************************************************************
**                      Include Files                                         **
*******************************************************************************/
#include <DAVE3.h>
#include "../../inc/LMM001/LMM001.h"
#include "../../inc/DBG001/DBG001.h"
#include "../../inc/GMM001/GMM001.h"

/*******************************************************************************
**                      Global Variable declarations                          **
*******************************************************************************/
/**
 * Heap Banks : Defined in Linker script
 */
extern unsigned char Heap_Bank1_Start[];
extern unsigned char Heap_Bank2_Start[];
extern unsigned char Heap_Bank3_Start[];

/**
  * Sizes of Heap Banks : Defined in Linker script
  */
extern unsigned int Heap_Bank1_Size;
extern unsigned int Heap_Bank2_Size;
extern unsigned int Heap_Bank3_Size;

const uint32_t LENGTH1 = (unsigned int)( & Heap_Bank1_Size);
const uint32_t LENGTH2 = (unsigned int)( & Heap_Bank2_Size);
const uint32_t LENGTH3 = (unsigned int)( & Heap_Bank3_Size);

/**
 * These are the LMM001 handles per RAM section.
*/
LMM001_HandleType GMM001_handle0;
LMM001_HandleType GMM001_handle1;
LMM001_HandleType GMM001_handle2;

/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/
/*<<<DD_GMM001_API_1>>>*/
/* This function configures LMM001 handles using different RAM sections available
 * depending on the heap requirement.
 */
void GMM001_Init (void)
{
  FUNCTION_ENTRY(GID_GMM001, (uint32_t)GMM001_FUNCTION_ENTRY);
  
  memset ((void *)Heap_Bank1_Start, 0, LENGTH1);
  memset ((void *)Heap_Bank2_Start, 0, LENGTH2);
  memset ((void *)Heap_Bank3_Start, 0, LENGTH3);

/* Allocate Heap from RAM1 and RAM2 and RAM3*/  
/*<<<DD_GMM001_API_1_6>>>*/  
  GMM001_handle0.umm_heap = ((LMM001_BlockType *)Heap_Bank1_Start);
  GMM001_handle0.umm_numblocks = (uint32_t)LENGTH1 / (sizeof(LMM001_BlockType));
  GMM001_handle1.umm_heap = ((LMM001_BlockType *)Heap_Bank2_Start);
  GMM001_handle1.umm_numblocks = (uint32_t)LENGTH2 / (sizeof(LMM001_BlockType));
  GMM001_handle2.umm_heap = ((LMM001_BlockType *)Heap_Bank3_Start);
  GMM001_handle2.umm_numblocks = (uint32_t) LENGTH3/ (sizeof(LMM001_BlockType));

  FUNCTION_EXIT(GID_GMM001, (uint32_t)GMM001_FUNCTION_EXIT);
}

/*<<<DD_GMM001_API_2>>>*/
/*
 * The function allocates memory of 'size' number of bytes.
 */
void * GMM001_malloc (uint32_t size)
{
  void * MemPtr = NULL;
  FUNCTION_ENTRY(GID_GMM001, (uint32_t)GMM001_FUNCTION_ENTRY);

/*<<<DD_GMM001_API_2_1>>>*/  
  MemPtr = LMM001_malloc(&GMM001_handle0, size);
  if (MemPtr == NULL)
  {
    MemPtr = LMM001_malloc(&GMM001_handle1, size);
	if (MemPtr == NULL)
	{
		MemPtr = LMM001_malloc(&GMM001_handle2, size);
	}
  }

  FUNCTION_EXIT(GID_GMM001, (uint32_t)GMM001_FUNCTION_EXIT);
  return MemPtr;
}

/*<<<DD_GMM001_API_3>>>*/ 
/*
 * This function changes the size of a block of memory that was previously allocated with malloc().
 */
void * GMM001_realloc (uint32_t size, void * MemPtr)
{
  void * MemPtr1 = NULL;
  FUNCTION_ENTRY(GID_GMM001, (uint32_t)GMM001_FUNCTION_ENTRY);

  if (MemPtr == NULL)
  {
    return(GMM001_malloc(size));
  }

/*<<<DD_GMM001_API_3_1>>>*/   
  if (((uint32_t)MemPtr >= (uint32_t)Heap_Bank1_Start) && ((uint32_t)MemPtr <= ((uint32_t)Heap_Bank1_Start + LENGTH1)))
  {
    MemPtr1 = LMM001_realloc(&GMM001_handle0, MemPtr, size);
  }

/*<<<DD_GMM001_API_3_2>>>*/   
  else if (((uint32_t)MemPtr >= (uint32_t)Heap_Bank2_Start) && ((uint32_t)MemPtr <= ((uint32_t)Heap_Bank2_Start + LENGTH2)))
  {
 	MemPtr1 = LMM001_realloc(&GMM001_handle1, MemPtr, size);
  }

/*<<<DD_GMM001_API_3_3>>>*/   
  else if (((uint32_t)MemPtr >= (uint32_t)Heap_Bank3_Start) && ((uint32_t)MemPtr <= ((uint32_t)Heap_Bank3_Start + LENGTH3)))
  {
    MemPtr1 = LMM001_realloc(&GMM001_handle2, MemPtr, size);
  }
  FUNCTION_EXIT(GID_GMM001, (uint32_t)GMM001_FUNCTION_EXIT);
  return MemPtr1;
}

/*<<<DD_GMM001_API_4>>>*/ 
/*
 *  The function deallocates the memory pointed by Memptr.
 */
void GMM001_free (void * MemPtr)
{
  FUNCTION_ENTRY(GID_GMM001, (uint32_t)GMM001_FUNCTION_ENTRY);

/*<<<DD_GMM001_API_4_1>>>*/   
  if (((uint32_t)MemPtr >= (uint32_t)Heap_Bank1_Start) && ((uint32_t)MemPtr <= ((uint32_t)Heap_Bank1_Start + LENGTH1)))
  {
    LMM001_free(&GMM001_handle0, MemPtr);
  }

/*<<<DD_GMM001_API_4_2>>>*/   
  else if (((uint32_t)MemPtr >= (uint32_t)Heap_Bank2_Start) && ((uint32_t)MemPtr <= ((uint32_t)Heap_Bank2_Start + LENGTH2)))
  {
    LMM001_free(&GMM001_handle1, MemPtr);
  }

/*<<<DD_GMM001_API_4_3>>>*/   
  else if (((uint32_t)MemPtr >= (uint32_t)Heap_Bank3_Start) && ((uint32_t)MemPtr <= ((uint32_t)Heap_Bank3_Start + LENGTH3)))
  {
    LMM001_free(&GMM001_handle2, MemPtr);
  }
  FUNCTION_EXIT(GID_GMM001, (uint32_t)GMM001_FUNCTION_EXIT);
}
