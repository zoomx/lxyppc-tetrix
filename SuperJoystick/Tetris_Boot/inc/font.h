#ifndef   FONT_H
#define   FONT_H

typedef unsigned long(*pfnFontDrawChar)(pfnDrawBlock_t DrawBlock,Pos_t x, Pos_t y, unsigned int ch);

unsigned long SongSmall5_DrawChar(pfnDrawBlock_t DrawBlock,Pos_t x, Pos_t y,unsigned int ch);

#define   GetFontTextHeight(pfnFont,ch)    pfnFont(0,0,0,(unsigned char)(ch))
#define   GetFontTextWidth(pfnFont,ch)     pfnFont(0,1,0,(unsigned char)(ch))

#endif
