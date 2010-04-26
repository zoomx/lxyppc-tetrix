#ifndef   HID_DEVICE_H
#define   HID_DEVICE_H


#define   MOUSE_INT               2     // Interface number for mouse
#define   KEYBOARD_INT            3     // Interface number for keyboard

#define   MOUSE_REPORT_ID         1
#define   JOYSTICK_REPORT_ID      2

#define   NUM_LOCK                0x01
#define   CAPS_LOCK               0x02
#define   SCROLL_LOCK             0x04
#define   COMPOSE                 0x08
#define   KANA                    0x10

u8    GetIdle(u8 interface, u8 ID);
u8    GetProtocol(u8 interface);

void  SetIdle(u8 interface, u8 ID, u8 data);
void  SetProtocol(u8 interface, u8 data);
// This routine only used when set the keyboard LED status
void  SetReport(u8 interface, u8 ID, u8 value);

void  HidProcess(void);

#endif
