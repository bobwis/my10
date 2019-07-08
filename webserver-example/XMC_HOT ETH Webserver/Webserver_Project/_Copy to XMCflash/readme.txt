Step 1:

- Put all webpage into folder "fs"
- Double click on makefsdat.exe
- fsdata.c will be generated or overwritten


Step 2:
- Copy and replace "fsdata.c" into folder ...\Dave\Generated\src\WEBSERVER001\HTTPServer



Step 3:
- Open file "WEBSERVER001_Conf.h" in folder ...\Dave\Generated\inc\WEBSERVER001
- Make changes to "HTTPD_FAT_FS" as shown below

	#define HTTPD_FAT_FS                   0 // 0 = Read webpage from XMC flash memory
						 // 1 = Read webpage from SD card
 

Step 4

- To avoid compilation error please include the follow codes into "fsdata.c"



#ifdef FS_C		// Used to avoid compilation errors of fsdata.c

#include "fs.h"
#include "lwip/def.h"
#include "fsdata.h"

#if  ~HTTPD_FAT_FS	// Used to avoid compilation errors of fsdata.c

	:
	:
	:
	:
	:

#endif			// Used to avoid compilation errors of fsdata.c
#endif			// Used to avoid compilation errors of fsdata.c



