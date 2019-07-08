/* ===================================================================================
 * Copyright (c) <2009> Synopsys, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of 
 * this software annotated with this license and associated documentation files 
 * (the "Software"), to deal in the Software without restriction, including without 
 * limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the Software is 
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all 
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION 
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * =================================================================================== */
/* =========================================================================== * 
 * Copyright (c) 2011, Infineon Technologies AG                                *
 * All rights reserved.                                                        * 
 *                                                                             *
 * Redistribution and use in source and binary forms, with or without          *
 * modification, are permitted provided that the following conditions are met: *
 * Redistributions of source code must retain the above copyright notice, this *
 * list of conditions and the following disclaimer. Redistributions in binary  *
 * form must reproduce the above copyright notice, this list of conditions and *
 * the following disclaimer in the documentation and/or other materials        *
 * provided with the distribution. Neither the name of the copyright holders   * 
 * nor the names of its contributors may be used to endorse or promote         *
 * products derived from this software without specific prior written          * 
 * permission.                                                                 *
 *                                                                             *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" *
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,       *
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR      *
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR           *
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,       *
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,         * 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; *
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,    *
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR     *
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF      *
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                                  *
 * To improve the quality of the software, users are encouraged to share       *
 * modifications, enhancements or bug fixes with                               *
 * Infineon Technologies AG (dave@infineon.com).                               *
 *                                                                             *
 * ==========================================================================  *
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4000 Series                                         **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR : DAVE App Developer                                                **
**                                                                            **
** MAY BE CHANGED BY USER [Yes/No]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Dec 29, 2011                                           **
**                                                                            **
*******************************************************************************/
 
/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** JRP          DAVE App Developer                                            **
*******************************************************************************/
/**\file
 *  This file defines the wrapper for the platform/OS related functions
 *  The function definitions needs to be modified according to the platform 
 *  and the Operating system used.
 *  This file should be handled with greatest care while porting the driver
 *  to a different platform running different operating system other than
 *  Linux 2.6.xx.
 * \internal
 * ----------------------------REVISION HISTORY-----------------------------
 * Synopsys			01/Aug/2007			Created
 */
 
#include <DAVE3.h>

/**
 * @cond INTERNAL_DOCS
 */

/**
 * The Low level function to read register contents from Hardware.
 *
 * @param[in] pointer to the base of register map
 * @param[in] Offset from the base
 * \return  Returns the register contents
 */
u32 synopGMACReadReg(u32 *RegBase, u32 RegOffset)
{
  u32 data;
  data = (*(u32 *) ((u32)RegBase + RegOffset));
  return data;

}

/**
 * The Low level function to write to a register in Hardware.
 *
 * @param[in] pointer to the base of register map
 * @param[in] Offset from the base
 * @param[in] Data to be written
 * \return  void
 */
void  synopGMACWriteReg(u32 *RegBase, u32 RegOffset, u32 RegData)
{
  * (u32 *) ((u32)RegBase + RegOffset) = RegData;
  return;
}

/**
 * The Low level function to set bits of a register in Hardware.
 *
 * @param[in] pointer to the base of register map
 * @param[in] Offset from the base
 * @param[in] Bit mask to set bits to logical 1
 * \return  void
 */
void synopGMACSetBits(u32 *RegBase, u32 RegOffset, u32 BitPos)
{
  u32 data;

  /* Read data from the register */
  data = (*(u32 *) ((u32)RegBase + RegOffset));

  /* Set the bits */
  data |= BitPos;

  /* Write back into the register */
  * (u32 *) ((u32)RegBase + RegOffset) = data;
  return;
}


/**
 * The Low level function to clear bits of a register in Hardware.
 *
 * @param[in] pointer to the base of register map
 * @param[in] Offset from the base
 * @param[in] Bit mask to clear bits to logical 0
 * \return  void
 */
void synopGMACClearBits(u32 *RegBase, u32 RegOffset, u32 BitPos)
{
  u32 data;
  /* Read data from the register */
  data = (*(u32 *) ((u32)RegBase + RegOffset));

  /*Clear the bits */
  data &= (~BitPos);

  /* Write back into the register */
  * (u32 *) ((u32)RegBase + RegOffset) = data;

  return;
}

/**
 * The Low level function to Check the setting of the bits.
 *
 * @param[in] pointer to the base of register map
 * @param[in] Offset from the base
 * @param[in] Bit mask to set bits to logical 1
 * \return  returns TRUE if set to '1' returns FALSE if set to '0'. Result undefined there are no bit set in the BitPos argument.
 *
 */
bool synopGMACCheckBits(u32 *RegBase, u32 RegOffset, u32 BitPos)
{
  u32 data;
  u32 addr = (u32)RegBase + RegOffset;
  data = (*(u32 *)addr);
  data &= BitPos;
  if(data)  return TRUE;
  else	    return FALSE;

}

#ifdef LINUX_CODE
/**
  * This is a wrapper function for Memory allocation routine. In linux Kernel 
  * it it kmalloc function
  * @param[in] bytes in bytes to allocate
  */

void *plat_alloc_memory(u32 bytes) 
{
	return kmalloc((size_t)bytes, GFP_KERNEL);
}

/**
  * This is a wrapper function for consistent dma-able Memory allocation routine. 
  * In linux Kernel, it depends on pci dev structure
  * @param[in] bytes in bytes to allocate
  */

void *plat_alloc_consistent_dmaable_memory(struct pci_dev *pcidev, u32 size, u32 *addr) 
{
 return (pci_alloc_consistent (pcidev,size,addr));
}

/**
  * This is a wrapper function for freeing consistent dma-able Memory.
  * In linux Kernel, it depends on pci dev structure
  * @param[in] bytes in bytes to allocate
  */

void plat_free_consistent_dmaable_memory(struct pci_dev *pcidev, u32 size, void * addr,u32 dma_addr) 
{
 pci_free_consistent (pcidev,size,addr,dma_addr);
 return;
}

/**
  * This is a wrapper function for Memory free routine. In linux Kernel 
  * it it kfree function
  * @param[in] buffer pointer to be freed
  */
void plat_free_memory(void *buffer) 
{
	kfree(buffer);
	return ;
}


/**
  * This is a wrapper function for platform dependent delay 
  * Take care while passing the argument to this function 
  * @param[in] delay
  */
void plat_delay(u32 delay)
{
	while (delay > 0)
	{
	  delay--;
	}
	return;
}
#endif

/**
 * @endcond
 */



