/* ===================================================================================
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Adam Dunkels <adam@sics.se>
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
 * ========================================================================== */

/* lwIP includes. */
#include "lwip/debug.h"
#include "lwip/def.h"
#include "lwip/sys.h"
#include "lwip/mem.h"
#include "lwip/opt.h"
#include "ethernetif.h"
#include "netconf.h"

#include <DAVE3.h>


/*****************************************************************************
              DUMMY DEFINTIONS OF DEBUG LOG MACROS
*****************************************************************************/
/*These definitions are included here to avoid compilation errors,
 since the DBG002 app is not part of the project. All the macros are defined
 as empty*/
#ifndef _DBG002_H_

#define DBG002_RegisterCallBack(A,B,C)
#define DBG002_I(e)
#define DBG002_IG(e,g)
#define DBG002_IH(e,h)
#define DBG002_IP(e,p)
#define DBG002_IGH(e,g,h)
#define DBG002_IGP(e,g,p)
#define DBG002_IHP(e,h,p)
#define DBG002_IGHP(e,g,h,p)
#define DBG002_N(e)
#define DBG002_NG(e,g)
#define DBG002_NH(e,h)
#define DBG002_NP(e,p)
#define DBG002_NGH(e,g,h)
#define DBG002_NGP(e,g,p)
#define DBG002_NHP(e,h,p)
#define DBG002_NGHP(e,g,h,p)
#define DBG002_ID(e)
#define DBG002_IS(e)
#define DBG002_ISG(e,g)
#define DBG002_SAFETY_CRITICAL(groupid,messageid,length,value)
#define DBG002_CRITICAL(groupid,messageid,length,value)
#define DBG002_ERROR(groupid,messageid,length,value)
#define DBG002_WARNING(groupid,messageid,length,value)
#define DBG002_INFO(groupid,messageid,length,value)
#define DBG002_TRACE(groupid,messageid,length,value)
#define DBG002_FUNCTION_ENTRY(GID, Status)
#define DBG002_FUNCTION_EXIT(GID, Status)

#endif/* End of defintions of dummy Debug Log macros*/

/* TODO: Change */
typedef uint32_t portTickType;
#define portTICK_RATE_MS 1000
typedef uint32_t portLONG;


#if !NO_SYS

#define lwIP_CEILING_PRIORITY 5
/* Message queue constants. */
#define archMESG_QUEUE_LENGTH	( 6 )

/* TODO: Update */
#define archPOST_BLOCK_TIME_MS  ( ( uint32_t ) 10000 )

struct timeoutlist 
{
	struct sys_timeouts timeouts;
	handle_t pid;
};

/* This is the number of threads that can be started with sys_thread_new() */
#define SYS_THREAD_MAX 4

#define lwipTCP_STACK_SIZE			600
#define lwipBASIC_SERVER_STACK_SIZE	250

static struct timeoutlist timeoutlist[SYS_THREAD_MAX];
static u16_t nextthread = 0;
int intlevel = 0;


/*-----------------------------------------------------------------------------------*/
//  Creates an empty mailbox.
sys_mbox_t
sys_mbox_new(int size)
{
   
  /* <<<DD_LWIP_PORT_11_1>>> */
	handle_t mbox;

	mbox = RTOS001_CreateQueue( size, sizeof( void * ) );

	if (0 == mbox)
	{
	  DBG002_ERROR(GID_LWIP, lwIP_NULL_PARAM, 0, NULL);
	}

	return mbox;
}

/*-----------------------------------------------------------------------------------*/
/*
  Deallocates a mailbox. If there are messages still present in the
  mailbox when the mailbox is deallocated, it is an indication of a
  programming error in lwIP and the developer should be notified.
*/
void
sys_mbox_free(sys_mbox_t mbox)
{
  /* <<<DD_LWIP_PORT_12_1>>> */

#ifdef lwIP_CODE
	if( uxQueueMessagesWaiting( mbox ) )
	{
		/* Line for breakpoint.  Should never break here! */
		__asm volatile ( "NOP" );
	}
#endif
	RTOS001_DeleteQueue( mbox );
        

}

/*-----------------------------------------------------------------------------------*/
//   Posts the "msg" to the mailbox.
void
sys_mbox_post(sys_mbox_t mbox, void *data)
{   
  /* <<<DD_LWIP_PORT_13_1>>> */

  status_t Status = lwIP_MBOX_ERROR;

  Status = RTOS001_SendToQueue( mbox, &data,
      ( portTickType ) ( archPOST_BLOCK_TIME_MS / portTICK_RATE_MS ) );

  if (Status != DAVEApp_SUCCESS)
  {
    DBG002_WARNING(GID_LWIP, lwIP_MBOX_ERROR, 0, NULL);
  }

}

//   Posts the "msg" to the mailbox.
err_t sys_mbox_trypost(sys_mbox_t mbox, void *msg)
{
  status_t Status = lwIP_MBOX_ERROR;

  /* <<<DD_LWIP_PORT_14_1>>> */
  Status = RTOS001_SendToQueue( mbox, &msg,
        ( portTickType ) ( archPOST_BLOCK_TIME_MS / portTICK_RATE_MS ) );

  if (Status != DAVEApp_SUCCESS)
  {
    DBG002_WARNING(GID_LWIP, lwIP_MBOX_ERROR, 0, NULL);
  }

  return ERR_OK;

}


/*-----------------------------------------------------------------------------------*/
/*
  Blocks the thread until a message arrives in the mailbox, but does
  not block the thread longer than "timeout" milliseconds (similar to
  the sys_arch_sem_wait() function). The "msg" argument is a result
  parameter that is set by the function (i.e., by doing "*msg =
  ptr"). The "msg" parameter maybe NULL to indicate that the message
  should be dropped.

  The return values are the same as for the sys_arch_sem_wait() function:
  Number of milliseconds spent waiting or SYS_ARCH_TIMEOUT if there was a
  timeout.

  Note that a function with a similar name, sys_mbox_fetch(), is
  implemented by lwIP. 
*/
u32_t sys_arch_mbox_fetch(sys_mbox_t mbox, void **msg, u32_t timeout)
{
  /* <<<DD_LWIP_PORT_15_1>>> */
  
  void *dummyptr;
  portTickType StartTime, EndTime, Elapsed;
  status_t Status;



	StartTime = RTOS001_GetTime ();

	if( msg == NULL )
	{
		msg = &dummyptr;
	}
		
	if(	timeout != 0 )
	{
	  Status = RTOS001_ReceiveQueue( mbox, &(*msg), timeout);
	  if (Status != DAVEApp_SUCCESS)
	  {
	    *msg = NULL;
	    return SYS_ARCH_TIMEOUT;
	  }
	  else // timed out blocking for message
	  {
	    EndTime = RTOS001_GetTime();
        Elapsed = EndTime - StartTime;
        if( Elapsed == 0 )
        {
          Elapsed = 1;
        }
        return ( Elapsed );
	  }
	}
	else // block forever for a message.
	{
		while(1)
		{
		    Status = RTOS001_ReceiveQueue( mbox, &(*msg), 10000 ); // time is arbitrary;
		    if (Status != DAVEApp_SUCCESS) /* TODO: CHeck with correct status */
		    {
		      continue;
		    }
		    else
		    {
		      break;
		    }
		}
		EndTime = RTOS001_GetTime();
		Elapsed = EndTime - StartTime;
		if( Elapsed == 0 )
		{
			Elapsed = 1;
		}
		return ( Elapsed ); // return time blocked TBD test	
	}
 }

/*-----------------------------------------------------------------------------------*/
//  Creates and returns a new semaphore. The "count" argument specifies
//  the initial state of the semaphore. TBD finish and test
sys_sem_t
sys_sem_new(u8_t count)
{
  /* <<<DD_LWIP_PORT_7_1>>> */
 
	handle_t  xSemaphore = 0;
	status_t status;
       
	RTOS001_EnterCritical();
	xSemaphore = RTOS001_CreateSemaphore( 1, 1, lwIP_CEILING_PRIORITY);
	/*
	if (status != DAVEApp_SUCCESS)
	{
	  return 0;  // TBD need assert
	}
	*/
	if(count == 0)	// Means it can't be taken
	{
	  status = RTOS001_GetSemaphore(xSemaphore,1);
	  if (status != DAVEApp_SUCCESS)
	  {
	    return 0;  // TBD need assert
	  }
	}
	RTOS001_ExitCritical();
	return xSemaphore;
}

/*-----------------------------------------------------------------------------------*/
/*
  Blocks the thread while waiting for the semaphore to be
  signaled. If the "timeout" argument is non-zero, the thread should
  only be blocked for the specified time (measured in
  milliseconds).

  If the timeout argument is non-zero, the return value is the number of
  milliseconds spent waiting for the semaphore to be signaled. If the
  semaphore wasn't signaled within the specified time, the return value is
  SYS_ARCH_TIMEOUT. If the thread didn't have to wait for the semaphore
  (i.e., it was already signaled), the function may return zero.

  Notice that lwIP implements a function with a similar name,
  sys_sem_wait(), that uses the sys_arch_sem_wait() function.
*/
u32_t
sys_arch_sem_wait(sys_sem_t sem, u32_t timeout)
{
  /* <<<DD_LWIP_PORT_10_1>>> */
portTickType StartTime, EndTime, Elapsed;
status_t Status;

	StartTime = RTOS001_GetTime();

	if(	timeout != 0)
	{
	  Status = RTOS001_GetSemaphore( sem, timeout );
		if(Status != DAVEApp_SUCCESS)
		{
		  return SYS_ARCH_TIMEOUT;
		}
		else
		{
      EndTime = RTOS001_GetTime();
      Elapsed = EndTime - StartTime;
      if( Elapsed == 0 )
      {
        Elapsed = 1;
      }
      return (Elapsed); // return time blocked TBD test
		}
	}
	else // must block without a timeout
	{
		while(1)
		{
		  Status = RTOS001_GetSemaphore( sem, 10000 );
		  if (Status != DAVEApp_SUCCESS) /* TODO: CHeck with correct status */
			{
		    continue;
			}
		  else
		  {
		    break;
		  }
		}
		EndTime = RTOS001_GetTime();
		Elapsed = EndTime - StartTime;
		if( Elapsed == 0 )
		{
			Elapsed = 1;
		}

		return ( Elapsed ); // return time blocked	
		 
	}
}

/*-----------------------------------------------------------------------------------*/
// Signals a semaphore
void
sys_sem_signal(sys_sem_t sem)
{
  /* <<<DD_LWIP_PORT_9_1>>> */
  status_t Status;

  Status = RTOS001_PutSemaphore(sem);
  if (Status != DAVEApp_SUCCESS)
  {
    DBG002_WARNING(GID_LWIP, lwIP_INFO_MSG, sizeof ("sys_sem_signal failed"), "sys_sem_signal failed");
  }
}

/*-----------------------------------------------------------------------------------*/
// Deallocates a semaphore
void
sys_sem_free(sys_sem_t sem)
{
  /* <<<DD_LWIP_PORT_8_1>>> */

  RTOS001_DeleteSemaphore(sem);

}

/*-----------------------------------------------------------------------------------*/
// Initialize sys arch
void
sys_init(void)
{
  /* <<<DD_LWIP_PORT_6>>> */

	int i;

	// Initialize the the per-thread sys_timeouts structures
	// make sure there are no valid pids in the list
	for(i = 0; i < SYS_THREAD_MAX; i++)
	{
		timeoutlist[i].pid = 0;
	}

	// keep track of how many threads have been created
	nextthread = 0;

}

/*-----------------------------------------------------------------------------------*/
/*
  Returns a pointer to the per-thread sys_timeouts structure. In lwIP,
  each thread has a list of timeouts which is represented as a linked
  list of sys_timeout structures. The sys_timeouts structure holds a
  pointer to a linked list of timeouts. This function is called by
  the lwIP timeout scheduler and must not return a NULL value. 

  In a single threaded sys_arch implementation, this function will
  simply return a pointer to a global sys_timeouts variable stored in
  the sys_arch module.
*/
struct sys_timeouts *
sys_arch_timeouts(void)
{
int i;
handle_t pid;
struct timeoutlist *tl;  


	pid = RTOS001_GetTaskHandle( );

	for(i = 0; i < nextthread; i++) 
	{
		tl = &timeoutlist[i];
		if(tl->pid == pid) 
		{
			return &(tl->timeouts);
		}
	}

	// Error

	return NULL;
}

/*-----------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------*/
// TBD 
/*-----------------------------------------------------------------------------------*/
/*
  Starts a new thread with priority "prio" that will begin its execution in the
  function "thread()". The "arg" argument will be passed as an argument to the
  thread() function. The id of the new thread is returned. Both the id and
  the priority are system dependent.
*/


sys_thread_t sys_thread_stop(sys_thread_t TaskHandle)
{

		RTOS001_DeleteTask(TaskHandle);

}


sys_thread_t sys_thread_new(char *name, void (* thread)(void *arg), void *arg, int stackSize, int prio)
{
handle_t CreatedTask;
void * TCPThreadHandle;
status_t Status;
		/* The first time this is called we are creating the lwIP handler. */
		Status = RTOS001_CreateTask ((handle_t)thread, name,
		    (uint32_t)stackSize, arg,(uint32_t) prio,  &TCPThreadHandle, 0, NULL);
		
	

	// For each task created, store the task handle (pid) in the timers array.
	// This scheme doesn't allow for threads to be deleted
	//timeoutlist[nextthread++].pid = TCPThreadHandle;

	if(TCPThreadHandle != 0)
	{
		return (sys_thread_t)TCPThreadHandle;
	}
	else
	{
		return 0;
	}
        return 0;
}

/*
  This optional function does a "fast" critical region protection and returns
  the previous protection level. This function is only called during very short
  critical regions. An embedded system which supports ISR-based drivers might
  want to implement this function by disabling interrupts. Task-based systems
  might want to implement this by using a mutex or disabling tasking. This
  function should support recursive calls from the same task or interrupt. In
  other words, sys_arch_protect() could be called while already protected. In
  that case the return value indicates that it is already protected.

  sys_arch_protect() is only required if your port is supporting an operating
  system.
*/
void sys_arch_protect(void)
{

  RTOS001_EnterCritical();

	return;
}

/*
  This optional function does a "fast" set of critical region protection to the
  value specified by pval. See the documentation for sys_arch_protect() for
  more information. This function is only required if your port is supporting
  an operating system.
*/
void sys_arch_unprotect(void)
{ 

	RTOS001_ExitCritical();

}
#endif
