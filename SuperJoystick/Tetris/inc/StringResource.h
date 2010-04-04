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
#define   STR_TETRIS            8
#define   STR_TETRIS_PAUSE      9
#define   STR_TETRIS_OVER       10
#define   STR_TETRIS_PLAY       11
#define   STR_TETRIS_SWITCH     12
#define   STR_ABOUT_0           13
#define   STR_ABOUT_1           14
#define   STR_ABOUT_2           15
#define   STR_MOUSE_0           16
#define   STR_MOUSE_1           17
#define   STR_MOUSE_2           18
#define   STR_MOUSE_3           19
#define   STR_SETTING           20
#define   STR_LANG_CHS          21
#define   STR_LANG_ENG          22
#define   STR_ABOUT             23
#define   STR_LAST         	24

typedef   const char* LPCSTR;
extern  const LPCSTR StringTable_ENG[STR_LAST];
extern  const LPCSTR StringTable_CHS[STR_LAST];

#endif
