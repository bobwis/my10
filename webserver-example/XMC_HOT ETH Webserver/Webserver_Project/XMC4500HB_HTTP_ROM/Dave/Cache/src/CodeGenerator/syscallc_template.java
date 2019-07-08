package CodeGenerator;

import com.ifx.davex.appjetinteract.App2JetInterface;

public class syscallc_template
{
  protected static String nl;
  public static synchronized syscallc_template create(String lineSeparator)
  {
    nl = lineSeparator;
    syscallc_template result = new syscallc_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/* CODE_BLOCK_BEGIN[syscall.c] */" + NL + "/*------------------------------------------------------------------------*/" + NL + "/* Sample code of OS dependent controls for FatFs R0.08b                  */" + NL + "/* (C)ChaN, 2011                                                          */" + NL + "/*------------------------------------------------------------------------*/" + NL + "/*******************************************************************************" + NL + " Copyright (c) 2011, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without**" + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : App Developer                                                     **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : Oct 1, 2012                                            **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials    Name                                                           **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** SK          App Developer                                                  **" + NL + "*******************************************************************************/";
  protected final String TEXT_2 = NL;
  protected final String TEXT_3 = NL + "#include <stdlib.h>\t\t/* ANSI memory controls */" + NL + "#include <DAVE3.h>" + NL + "" + NL + "" + NL + "#if _FS_REENTRANT" + NL + "" + NL + "extern ";
  protected final String TEXT_4 = "_MutexInfoType ";
  protected final String TEXT_5 = "_MutexInfo[";
  protected final String TEXT_6 = "_MAX_LOGICAL_DRIVES];" + NL + "" + NL + "" + NL + "extern volatile osMutexId ";
  protected final String TEXT_7 = "_MutexProtectId;" + NL + "/*------------------------------------------------------------------------*/" + NL + "/* Create a Synchronization Object                                        */" + NL + "/*------------------------------------------------------------------------*/" + NL + "/* This function is called in f_mount function to create a new" + NL + "/  synchronization object, such as semaphore and mutex. When a zero is" + NL + "/  returned, the f_mount function fails with FR_INT_ERR." + NL + "*/" + NL + "" + NL + "int ff_cre_syncobj (\t/* TRUE:Function succeeded, FALSE:Could not create due to any error */" + NL + "\tBYTE vol,\t\t\t/* Corresponding logical drive being processed */" + NL + "\t_SYNC_t *sobj\t\t/* Pointer to return the created sync object */" + NL + ")" + NL + "{" + NL + "  uint32_t MutexCount = 0;" + NL + "  int RetVal = -1;" + NL + "  osStatus SemStatus;" + NL + "/* Check for available Mutexes. */" + NL + "/* Take Mutex */" + NL + "  SemStatus = osMutexWait(";
  protected final String TEXT_8 = "_MutexProtectId,  osWaitForever );" + NL + "  if (osOK == SemStatus)" + NL + "  {" + NL + "    for (MutexCount=0; MutexCount<";
  protected final String TEXT_9 = "_MAX_LOGICAL_DRIVES; MutexCount++)" + NL + "    {" + NL + "      if( ";
  protected final String TEXT_10 = "_MutexInfo[MutexCount].MutexStatus == ";
  protected final String TEXT_11 = "_FREE)" + NL + "      {" + NL + "    \t  *sobj = ";
  protected final String TEXT_12 = "_MutexInfo[MutexCount].MutexId;" + NL + "    \t  /* Remove the allocated mutex from free list*/" + NL + "    \t  ";
  protected final String TEXT_13 = "_MutexInfo[MutexCount].MutexStatus =  ";
  protected final String TEXT_14 = "_BUSY;" + NL + "    \t  RetVal =  (int)*sobj;" + NL + "    \t  break;" + NL + "      }" + NL + "    }/* End of \"for loop\"*/" + NL + "    SemStatus = osMutexRelease (";
  protected final String TEXT_15 = "_MutexProtectId);" + NL + "    if (SemStatus != osOK)" + NL + "    {" + NL + "      ERROR(GID_FATFS002,";
  protected final String TEXT_16 = "_MUTEX_RELEASE_FAILED,0,0);" + NL + "      RetVal = -1;" + NL + "    } /* End of \"if (osOK != SemStatus)\"*/" + NL + "  } /* End of \" if ((uint32_t)osOK != SemStatus)\"*/" + NL + "  return RetVal;" + NL + "}" + NL + "" + NL + "" + NL + "" + NL + "/*------------------------------------------------------------------------*/" + NL + "/* Delete a Synchronization Object                                        */" + NL + "/*------------------------------------------------------------------------*/" + NL + "/* This function is called in f_mount function to delete a synchronization" + NL + "/  object that created with ff_cre_syncobj function. When a zero is" + NL + "/  returned, the f_mount function fails with FR_INT_ERR." + NL + "*/" + NL + "" + NL + "int ff_del_syncobj (\t/* TRUE:Function succeeded, FALSE:Could not delete due to any error */" + NL + "\t_SYNC_t sobj\t\t/* Sync object tied to the logical drive to be deleted */" + NL + ")" + NL + "{" + NL + "  uint32_t RetVal;" + NL + "  uint32_t MutexCount = 0;" + NL + "  for (MutexCount=0;MutexCount<";
  protected final String TEXT_17 = "_MAX_LOGICAL_DRIVES; MutexCount++)" + NL + "  {" + NL + "\tif(";
  protected final String TEXT_18 = "_MutexInfo[MutexCount].MutexId == sobj)" + NL + "\t{" + NL + "\t   /* Remove the allocated mutex from free list*/" + NL + "\t\t";
  protected final String TEXT_19 = "_MutexInfo[MutexCount].MutexStatus = ";
  protected final String TEXT_20 = "_FREE;" + NL + "\t}" + NL + "  }" + NL + "/*Return Status will be always 1 */" + NL + "  RetVal = 1;" + NL + "  return RetVal;" + NL + "}" + NL + "" + NL + "" + NL + "" + NL + "/*------------------------------------------------------------------------*/" + NL + "/* Request Grant to Access the Volume                                     */" + NL + "/*------------------------------------------------------------------------*/" + NL + "/* This function is called on entering file functions to lock the volume." + NL + "/  When a zero is returned, the file function fails with FR_TIMEOUT." + NL + "*/" + NL + "" + NL + "int ff_req_grant (\t/* TRUE:Got a grant to access the volume, FALSE:Could not get a grant */" + NL + "\t_SYNC_t sobj\t/* Sync object to wait */" + NL + ")" + NL + "{" + NL + "  osStatus Status;" + NL + "  int RetVal = 1;" + NL + "/* Wait till the Mutex becomes available  */" + NL + "  Status = (int )osMutexWait(sobj, _FS_TIMEOUT );" + NL + "  if (Status != osOK )" + NL + "  {" + NL + "    RetVal = 0;" + NL + "  }" + NL + "  return RetVal;" + NL + "}" + NL + "" + NL + "" + NL + "" + NL + "/*------------------------------------------------------------------------*/" + NL + "/* Release Grant to Access the Volume                                     */" + NL + "/*------------------------------------------------------------------------*/" + NL + "/* This function is called on leaving file functions to unlock the volume." + NL + "*/" + NL + "" + NL + "void ff_rel_grant (" + NL + "\t_SYNC_t sobj\t/* Sync object to be signaled */" + NL + ")" + NL + "{" + NL + "  osMutexRelease (sobj);" + NL + "}" + NL + "" + NL + "#endif" + NL + NL + NL + NL;
  protected final String TEXT_21 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri = "app/fatfs002/"; 
     int appInst = 0; 
     int RTOS = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_fs_reentrant");
   String  Module_Name = "FATFS002";

    stringBuffer.append(TEXT_2);
     
  if (RTOS == 1)
  {
    Module_Name = "FATFS003";
  }
  else
  {
    Module_Name = "FATFS002";
  }

    stringBuffer.append(TEXT_3);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_4);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_5);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_6);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_7);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_8);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_9);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_10);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_11);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_12);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_13);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_14);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_15);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_16);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_17);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_18);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_19);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_20);
    stringBuffer.append(TEXT_21);
    return stringBuffer.toString();
  }
}
