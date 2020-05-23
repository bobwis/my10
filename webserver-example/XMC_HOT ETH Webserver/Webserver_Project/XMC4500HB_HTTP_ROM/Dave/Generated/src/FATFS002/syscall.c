
/* CODE_BLOCK_BEGIN[syscall.c] */
/*------------------------------------------------------------------------*/
/* Sample code of OS dependent controls for FatFs R0.08b                  */
/* (C)ChaN, 2011                                                          */
/*------------------------------------------------------------------------*/
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
** PLATFORM : Infineon XMC4000 Series                                         **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR : App Developer                                                     **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Oct 1, 2012                                            **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials    Name                                                           **
** ---------------------------------------------------------------------------**
** SK          App Developer                                                  **
*******************************************************************************/

#include <stdlib.h>		/* ANSI memory controls */
#include <DAVE3.h>


#if _FS_REENTRANT

extern FATFS002_MutexInfoType FATFS002_MutexInfo[FATFS002_MAX_LOGICAL_DRIVES];


extern volatile osMutexId FATFS002_MutexProtectId;
/*------------------------------------------------------------------------*/
/* Create a Synchronization Object                                        */
/*------------------------------------------------------------------------*/
/* This function is called in f_mount function to create a new
/  synchronization object, such as semaphore and mutex. When a zero is
/  returned, the f_mount function fails with FR_INT_ERR.
*/

int ff_cre_syncobj (	/* TRUE:Function succeeded, FALSE:Could not create due to any error */
	BYTE vol,			/* Corresponding logical drive being processed */
	_SYNC_t *sobj		/* Pointer to return the created sync object */
)
{
  uint32_t MutexCount = 0;
  int RetVal = -1;
  osStatus SemStatus;
/* Check for available Mutexes. */
/* Take Mutex */
  SemStatus = osMutexWait(FATFS002_MutexProtectId,  osWaitForever );
  if (osOK == SemStatus)
  {
    for (MutexCount=0; MutexCount<FATFS002_MAX_LOGICAL_DRIVES; MutexCount++)
    {
      if( FATFS002_MutexInfo[MutexCount].MutexStatus == FATFS002_FREE)
      {
    	  *sobj = FATFS002_MutexInfo[MutexCount].MutexId;
    	  /* Remove the allocated mutex from free list*/
    	  FATFS002_MutexInfo[MutexCount].MutexStatus =  FATFS002_BUSY;
    	  RetVal =  (int)*sobj;
    	  break;
      }
    }/* End of "for loop"*/
    SemStatus = osMutexRelease (FATFS002_MutexProtectId);
    if (SemStatus != osOK)
    {
      ERROR(GID_FATFS002,FATFS002_MUTEX_RELEASE_FAILED,0,0);
      RetVal = -1;
    } /* End of "if (osOK != SemStatus)"*/
  } /* End of " if ((uint32_t)osOK != SemStatus)"*/
  return RetVal;
}



/*------------------------------------------------------------------------*/
/* Delete a Synchronization Object                                        */
/*------------------------------------------------------------------------*/
/* This function is called in f_mount function to delete a synchronization
/  object that created with ff_cre_syncobj function. When a zero is
/  returned, the f_mount function fails with FR_INT_ERR.
*/

int ff_del_syncobj (	/* TRUE:Function succeeded, FALSE:Could not delete due to any error */
	_SYNC_t sobj		/* Sync object tied to the logical drive to be deleted */
)
{
  uint32_t RetVal;
  uint32_t MutexCount = 0;
  for (MutexCount=0;MutexCount<FATFS002_MAX_LOGICAL_DRIVES; MutexCount++)
  {
	if(FATFS002_MutexInfo[MutexCount].MutexId == sobj)
	{
	   /* Remove the allocated mutex from free list*/
		FATFS002_MutexInfo[MutexCount].MutexStatus = FATFS002_FREE;
	}
  }
/*Return Status will be always 1 */
  RetVal = 1;
  return RetVal;
}



/*------------------------------------------------------------------------*/
/* Request Grant to Access the Volume                                     */
/*------------------------------------------------------------------------*/
/* This function is called on entering file functions to lock the volume.
/  When a zero is returned, the file function fails with FR_TIMEOUT.
*/

int ff_req_grant (	/* TRUE:Got a grant to access the volume, FALSE:Could not get a grant */
	_SYNC_t sobj	/* Sync object to wait */
)
{
  osStatus Status;
  int RetVal = 1;
/* Wait till the Mutex becomes available  */
  Status = (int )osMutexWait(sobj, _FS_TIMEOUT );
  if (Status != osOK )
  {
    RetVal = 0;
  }
  return RetVal;
}



/*------------------------------------------------------------------------*/
/* Release Grant to Access the Volume                                     */
/*------------------------------------------------------------------------*/
/* This function is called on leaving file functions to unlock the volume.
*/

void ff_rel_grant (
	_SYNC_t sobj	/* Sync object to be signaled */
)
{
  osMutexRelease (sobj);
}

#endif





