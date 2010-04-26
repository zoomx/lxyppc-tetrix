/*******************************************************************************
* File Name          : StringResource.c
* Author             : lxyppc
* Version            : V1.0
* Date               : 10-01-21
* Description        : String resouce file
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "StringResource.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

const LPCSTR StringTable_ENG[STR_LAST] ={	
  [STR_CAMERA_ON]       = "Camera On ",
  [STR_CAMERA_OFF]      = "Camera Off",
  [STR_JOYSTICK]        = "Joystick",
  [STR_MOUSE]           = "Mouse",
  [STR_AIR_MOUSE]       = "Air Mouse",
  [STR_KEYBOARD]        = "Keyboard",
  [STR_KB_NORMAL]       = "Normal",
  [STR_KB_SEQ]          = "Senquence",
  [STR_TETRIS]          = "Play Tetris",
  [STR_TETRIS_PAUSE]    = "Game Pause  ",
  [STR_TETRIS_OVER]     = "Game Over   ",
  [STR_TETRIS_PLAY]     = "Game Running",
  [STR_TETRIS_SWITCH]   = "Pause game first!",
  [STR_ABOUT_0]         = "Super Joystick 1.0",
  [STR_ABOUT_1]         = "lxyppc@163.com",
  [STR_ABOUT_2]         = "All rights reserved",
  [STR_MOUSE_0]         = "R1 - Scorll Up",
  [STR_MOUSE_1]         = "R2 - Scroll Down",
  [STR_MOUSE_2]         = "Buttons:",
  [STR_MOUSE_3]         = "4-Left 3-Mid 2-Right",
  [STR_SETTING]         = "Setting",
  [STR_LANG_CHS]        = /*"简体中文"*/"\xB3\x86\x82\xA0",
  [STR_LANG_ENG]        = "English",
  [STR_ABOUT]           = "About",
  [STR_AIR_MOUSE_0]     = "Press 1, then",
  [STR_AIR_MOUSE_1]     = "rotate, make",
  [STR_AIR_MOUSE_2]     = "ball out of",
  [STR_AIR_MOUSE_3]     = "the inner box",
};

const LPCSTR StringTable_CHS[STR_LAST] ={	
  [STR_CAMERA_ON]       = /*"摄像头开"*/"\x9F\x89\x93\x98",
  [STR_CAMERA_OFF]      = /*"摄像头关"*/"\x9F\x89\x93\x8B",
  [STR_JOYSTICK]        = /*"游戏手柄"*/"\xAD\x9A\x9C\xA8",
  [STR_MOUSE]           = /*"鼠标"*/"\xC2\xA9",
  [STR_AIR_MOUSE]       = /*"感应鼠标"*/"\x99\x97\xC2\xA9",
  [STR_KEYBOARD]        = /*"键盘"*/"\xC0\xB1",
  [STR_KB_NORMAL]       = /*"正常"*/"\xAB\x95",
  [STR_KB_SEQ]          = /*"顺序"*/"\xC1\x96",
  [STR_TETRIS]          = /*"俄罗斯方块"*/"\x87\xB6\xA1\xA2\x92",
  [STR_TETRIS_PAUSE]    = /*"游戏暂停    "*/"\xAD\x9A\xA4\x88    ",
  [STR_TETRIS_OVER]     = /*"游戏结束    "*/"\xAD\x9A\xB5\xA7    ",
  [STR_TETRIS_PLAY]     = /*"游戏进行中.."*/"\xAD\x9A\xBF\xB8\x82..",
  [STR_TETRIS_SWITCH]   = /*"请先暂停游戏!"*/"\xBB\x8A\xA4\x88\xAD\x9A!",
  [STR_ABOUT_0]         = /*"超级手柄 1.0"*/"\xBC\xB4\x9C\xA8 1.0",
  [STR_ABOUT_1]         = "lxyppc@163.com",
  [STR_ABOUT_2]         = /*"版权所有"*/"\xAF\xA6\x9B\xA5",
  [STR_MOUSE_0]         = /*"R1 - 滚轮向上"*/"R1 - \xAE\xBE\x91\x80",
  [STR_MOUSE_1]         = /*"R2 - 滚轮向下"*/"R2 - \xAE\xBE\x91\x81",
  [STR_MOUSE_2]         = /*"按键:"*/"\x9D\xC0:",
  [STR_MOUSE_3]         = /*"4左  3中  2右"*/"4\x94  3\x82  2\x8F",
  [STR_SETTING]         = /*"设置"*/"\xBA\xB7",
  [STR_LANG_CHS]        = /*"简体中文"*/"\xB3\x86\x82\xA0",
  [STR_LANG_ENG]        = "English",
  [STR_ABOUT]           = /*"关于"*/"\x8B\x83",
  [STR_AIR_MOUSE_0]     = /*"按住1键后旋转"*/"\x9D\x85\x31\xC0\x90\xA3\xBD",
  [STR_AIR_MOUSE_1]     = /*"手柄,让球移出"*/"\x9C\xA8,\xB9\xB0\xB2\x8D",
  [STR_AIR_MOUSE_2]     = /*"内框,以此控制"*/"\x8C\xAA,\x84\xAC\x9E\x8E",
  [STR_AIR_MOUSE_3]     = /*"鼠标"*/"\xC2\xA9",
};

/** Replaced strings:
      上下中于以住体俄停像先关内出制右后向块头左常序应开感戏所手按控摄文斯方旋暂有权束柄标框正此游滚版球盘移简级结罗置行让设请超转轮进键顺鼠

String Lookup Table:
     Char: 上 下 中 于 以 住 体 俄 停 像 先 关 内 出 制 右 
    Value: 80 81 82 83 84 85 86 87 88 89 8A 8B 8C 8D 8E 8F 
     Char: 后 向 块 头 左 常 序 应 开 感 戏 所 手 按 控 摄 
    Value: 90 91 92 93 94 95 96 97 98 99 9A 9B 9C 9D 9E 9F 
     Char: 文 斯 方 旋 暂 有 权 束 柄 标 框 正 此 游 滚 版 
    Value: A0 A1 A2 A3 A4 A5 A6 A7 A8 A9 AA AB AC AD AE AF 
     Char: 球 盘 移 简 级 结 罗 置 行 让 设 请 超 转 轮 进 
    Value: B0 B1 B2 B3 B4 B5 B6 B7 B8 B9 BA BB BC BD BE BF 
     Char: 键 顺 鼠 
    Value: C0 C1 C2 
*/
