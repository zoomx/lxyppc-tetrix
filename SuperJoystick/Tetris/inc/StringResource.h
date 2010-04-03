#ifndef   STRING_RESOURCE_H
#define   STRING_RESOURCE_H

/*复制资源ID定义*/	
#define   STR_CAMERA_ON         	0
#define   STR_CAMERA_OFF         	1
#define   STR_JOYSTICK         	2
#define   STR_MOUSE         	3
#define   STR_AIR_MOUSE         	4
#define   STR_KEYBOARD         	5
#define   STR_KB_NORMAL         	6
#define   STR_KB_SEQ         	7
#define   STR_LAST         	8

typedef   const char* LPCSTR;
extern  const LPCSTR StringTable_ENG[STR_LAST];
extern  const LPCSTR StringTable_CHS[STR_LAST];

#endif
