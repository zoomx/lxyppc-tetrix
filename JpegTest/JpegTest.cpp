// JpegTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "JpegLib.h"


unsigned char buf[320*240*3] = {0};
JSAMPLE * image_buffer = buf;	/* Points to large array of R,G,B-order data */
int image_height = 240;	/* Number of rows in image */
int image_width = 320;		/* Number of columns in image */

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

