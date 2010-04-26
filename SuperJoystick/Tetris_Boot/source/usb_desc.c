/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : usb_desc.c
* Author             : MCD Application Team
* Version            : V2.2.0
* Date               : 06/13/2008
* Description        : Descriptors for Audio Speaker Demo
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "usb_lib.h"
#include "usb_desc.h"
#include "HidDevice.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants----------------------------------------------------------*/
/* USB Standard Device Descriptor */
const u8 Speaker_DeviceDescriptor[] =
  {
    SPEAKER_SIZ_DEVICE_DESC,          /* bLength */
    USB_DEVICE_DESCRIPTOR_TYPE,           /* bDescriptorType */
    0x00,          /* 1.10 */             /* bcdUSB */
    0x02,
    0xEF,                                 /* bDeviceClass */ /*Miscellaneous Device Class*/
    0x02,                                 /* bDeviceSubClass */ /*Common Class */
    0x01,                                 /* bDeviceProtocol */ /*Interface Association Descriptor*/
    0x40,                                 /* bMaxPacketSize 40 */
    0x85,                                 /* idVendor = 0x1985*/
    0x19,
    0x17,                                 /* idProduct  = 0x1017*/
    0x10,
    0x00,                                 /* 1.00 */             /* bcdDevice */
    0x01,
    1,                                    /* iManufacturer */
    2,                                    /* iProduct */
    0,                                    /* iSerialNumber */
    0x01                                  /* bNumConfigurations */
  };

/* USB Configuration Descriptor */
/*   All Descriptors (Configuration, Interface, Endpoint, Class, Vendor */
#if   UNCOMPRESS
const u8 Speaker_ConfigDescriptor[] =
#else
const u8 Speaker_ConfigDescriptor_xxx[] =
#endif
  {
    /* Configuration Descriptor */
    0x09,                                /* bLength */
    USB_CONFIGURATION_DESCRIPTOR_TYPE,   /* bDescriptorType */
    SPEAKER_SIZ_CONFIG_DESC,             /* wTotalLength  0x90 bytes*/
    0x00,
    0x02,                                 /* bNumInterfaces */
    0x01,                                 /* bConfigurationValue */
    0x00,                                 /* iConfiguration */
    0x80,                                 /* bmAttributes  BUS Powred, no remote wakeup*/
    0xFA,                                 /* bMaxPower = 500 mA*/
    /* 09 byte, total size 9*/

    /* Standard Video Interface Collection IAD */
    0x08,                                 /* bLength */
    USB_ASSOCIATION_DESCRIPTOR_TYPE,      /* bDescriptorType */
    0x00,                                 /* bFirstInterface: Interface number of the VideoControl interface that is associated with this function*/
    0x02,                                 /* Number of contiguous Video interfaces that are associated with this function */
    0x0E,                                 /* bFunction Class: CC_VIDEO*/
    0x03,                                 /* bFunction sub Class: SC_VIDEO_INTERFACE_COLLECTION */
    0x00,                                 /* bFunction protocol : PC_PROTOCOL_UNDEFINED*/
    0x02,                                 /* iFunction */
    /* 08 bytes, total size 17*/
    
    /* Standard VC Interface Descriptor */
    0x09,                                 /* bLength */
    0x04,                                 /* bDescriptorType */
    0x00,                                 /* bInterfaceNumber */
    0x00,                                 /* bAlternateSetting */
    0x00,                                 /* bNumEndpoints */
    0x0e,                                 /* bInterfaceClass : CC_VIDEO */
    0x01,                                 /* bInterfaceSubClass : SC_VIDEOCONTROL */
    0x00,                                 /* bInterfaceProtocol : PC_PROTOCOL_UNDEFINED */
    0x02,                                 /* iInterface */
    /* 09 bytes, total size 26*/
    
    /* Class-specific VC Interface Descriptor */
    0x0d,                                 /* bLength */
    0x24,                                 /* bDescriptorType : CS_INTERFACE */
    0x01,                                 /* bDescriptorSubType : VC_HEADER subtype */
    0x00, 0x01,                           /* bcdUVC : Revision of class specification that this device is based upon. For this example, the device complies with Video Class specification version 1.0 */
    0x33, 0x00,                           /* wTotalLength : Total size of class-specific descriptors*/
    0x00, 0xA2, 0x4A, 0x04,               /* dwClockFrequency : 0x044aa200 -> 72,000,000 == 72MHz*/
    0x01,                                 /* bInCollection : Number of streaming interfaces. */
    0x01,                                 /* baInterfaceNr(1) : VideoStreaming interface 1 belongs to this VideoControl interface.*/
    /* 13 Bytes, totoal size 39 */
    
    /* Input Terminal Descriptor (Composite) */
    0x12,                                 /* bLength */
    0x24,                                 /* bDescriptorType : CS_INTERFACE */
    0x02,                                 /* bDescriptorSubType : VC_INPUT_TERMINAL subtype */
    0x01,                                 /* bTerminalID: ID of this input terminal */
    0x01, 0x02,                           /* wTerminalType: 0x0201 ITT_CAMERA type. This terminal is the composite connector. */
    0x00,                                 /* bAssocTerminal: No association */
    0x00,                                 /* iTerminal: Unused*/
    /* For ITT_CAMERA */
    0x00, 0x00,                           /* wObjectiveFocalLengthMin */
    0x00, 0x00,                           /* wObjectiveFocalLengthMax */
    0x00, 0x00,                           /* wOcularFocalLength */
    0x03,                                 /* bControlSize */
    0x00, 0x00, 0x00,                     /* bmControls */
    
    /* 18 Bytes, totoal size 57 */
    
    /* Video Control Processing Unit Descriptor */
    0x0B,                                 /* bLength */
    0x24,                                 /* bDescriptorType : CS_INTERFACE */
    0x05,                                 /* bDescriptorSubType : VC_SELECTOR_UNIT subtype */
    0x02,                                 /* bUnitID: ID of this output terminal */
    0x01,                                 /* bSourceID:  */
    0x00, 0x00,                           /* wMaxMultiplier */
    0x02,                                 /* bControlSize: */
    0x00, 0x00,                           /* bmControls */
    0x00,                                 /* iProcessing: Unused*/
    /* 11 Bytes, totoal size 68 */
  
    /* Output Terminal Descriptor */
    0x09,                                 /* bLength */
    0x24,                                 /* bDescriptorType : CS_INTERFACE */
    0x03,                                 /* bDescriptorSubType : VC_OUTPUT_TERMINAL subtype */
    0x03,                                 /* bTerminalID: ID of this output terminal */
    0x01, 0x01,                           /* wTerminalType: 0x0101 TT_STREAMING type. This terminal is a USB streaming terminal. */
    0x00,                                 /* bAssocTerminal: No association */
    0x02,                                 /* bSourceID: The input pin of this unit is connected to the output pin of unit 2. */
    0x00,                                 /* iTerminal: Unused*/
    /* 9 bytes, total size 77 */

    /* Standard VS Interface Descriptor*/
    0x09,                                 /* bLength */
    0x04,                                 /* bDescriptorType : INTERFACE */
    0x01,                                 /* bInterfaceNumber */
    0x00,                                 /* bAlternateSetting */
    0x00,                                 /* bNumEndpoints : 0 endpoints 每 no bandwidth used*/
    0x0e,                                 /* bInterfaceClass : CC_VIDEO */
    0x02,                                 /* bInterfaceSubClass : SC_VIDEOSTREAMING */
    0x00,                                 /* bInterfaceProtocol : PC_PROTOCOL_UNDEFINED */
    0x00,                                 /* iInterface : unused */
    /* 9 bytes, total size 86 */
    
    /* Class-specific VS Header Descriptor (Input) */
    0x0e,                                 /* bLength */
    0x24,                                 /* bDescriptorType : CS_INTERFACE */
    0x01,                                 /* bDescriptorSubType : VC_HEADER subtype */
    0x01,                                 /* bNumFormats : One format descriptor follows. */
    0x4F-8+6, 0x00,                           /* wTotalLength : Total size of class-specific descriptors*/
    0x81,                                 /* bEndpointAddress : 0x81 */
    0x00,                                 /* bmInfo : No dynamic format change supported. */
    0x03,                                 /* bTerminalLink : This VideoStreaming interface supplies terminal ID 3 (Output Terminal). */
    0x00,                                 /* bStillCaptureMethod : Device supports still image capture method 0. */
    0x00,                                 /* bTriggerSupport : Hardware trigger supported for still image capture */
    0x00,                                 /* bTriggerUsage : Hardware trigger should initiate a still image capture. */
    0x01,                                 /* bControlSize : Size of the bmaControls field */
    0x00,                                 /* bmaControls : No VideoStreaming specific controls are supported.*/
    /* 14 Bytes, totoal size 100 */
    
    /* Class-specific VS Format Descriptor  */    
    0x1B,                                 /* bLength */
    0x24,                                 /* bDescriptorType : CS_INTERFACE */
    0x04,                                 /* bDescriptorSubType : VS_FORMAT_UNCOMPRESSED subtype */
    0x01,                                 /* bFormatIndex : First (and only) format descriptor */
    0x01,                                 /* bNumFrameDescriptors : One frame descriptor for this format follows. */
    0x59,0x55,0x59,0x32,                  /* Giud Format YUY2 {32595559-0000-0010-8000-00AA00389B71} */
    //0x4E,0x56,0x31,0x32,                  /* NV12:           3231564E-0000-0010-8000-00AA00389B71 */
    0x00,0x00,
    0x10,0x00,
    //0x00,0x80,                            
    //0x71,0x9b,0x38,0x00,0xAA,0x00,
    0x80,0x00,0x00,0xAA,0x00,0x38,0x9B,0x71,
    0x10,                                 /* bBitsPerPixel : Number of bits per pixel used to specify color in the decoded video frame */
    0x01,                                 /* bDefaultFrameIndex : Default frame index is 1. */
    0x00,                                 /* bAspectRatioX : Non-interlaced stream 每 not required. */
    0x00,                                 /* bAspectRatioY : Non-interlaced stream 每 not required. */
    0x00,                                 /* bmInterlaceFlags : Non-interlaced stream */
    0x00,                                 /* bCopyProtect : No restrictions imposed on the duplication of this video stream. */
    /* 27 Bytes, total size 127 */

    /* Class-specific VS Frame Descriptor */
    0x1e,                                 /* bLength */
    0x24,                                 /* bDescriptorType : CS_INTERFACE */
    0x05,                                 /* bDescriptorSubType : VS_FRAME_UNCOMPRESSED */
    0x01,                                 /* bFrameIndex : First (and only) frame descriptor */
    0x02,                                 /* bmCapabilities : Still images using capture method 0 are supported at this frame setting.D1: Fixed frame-rate. */
    MAKE_WORD(WIDTH),                     /* wWidth : Width of frame is 128 pixels. */
    MAKE_WORD(HEIGHT),                    /* wHeight : Height of frame is 64 pixels. */
    MAKE_DWORD(MIN_BIT_RATE),
    MAKE_DWORD(MAX_BIT_RATE),
    //0x00, 0x00, 0x0A, 0x00,               /* dwMinBitRate : Min bit rate in bits/s  */ // 128*64*16*5 = 655360 = 0x000A0000
    //0x00, 0x00, 0x0A, 0x00,               /* dwMaxBitRate : Max bit rate in bits/s  */ // 128*64*16*5 = 655360 = 0x000A0000
    //0x00, 0x00, 0x06, 0x00,
    //0x00, 0x00, 0x06, 0x00,
    MAKE_DWORD(MAX_FRAME_SIZE),             /* dwMaxVideoFrameBufSize : Maximum video or still frame size, in bytes. */ // 128*64*2 = 16384 = 0x00004000
    MAKE_DWORD(INTERVEL),
    //0x80, 0x84, 0x1e, 0x00,               // 5 FPS -> 200ms -> 200,000 us -> 2,000,000 X 100ns = 0x001e8480
    //0x40, 0x42, 0x0f, 0x00,               /* dwDefaultFrameInterval : 1,000,000 * 100ns -> 10 FPS */
    0x01,                                 /* bFrameIntervalType : Continuous frame interval */
    MAKE_DWORD(INTERVEL),
    //0x80, 0x84, 0x1e, 0x00,
    //0x80, 0x84, 0x1e, 0x00,
    //0x80, 0x84, 0x1e, 0x00,
    //0x00, 0x00, 0x00, 0x00,
    //0xD5, 0xDC, 0x32, 0x00,
    //0x40, 0x42, 0x0f, 0x00,               /* dwMinFrameInterval : 1,000,000 ns  *100ns -> 10 FPS */
    //0x40, 0x42, 0x0f, 0x00,               /* dwMaxFrameInterval : 1,000,000 ns *100ns -> 10 FPS */
    //0x00, 0x00, 0x00, 0x00,               /* dwFrameIntervalStep : No frame interval step supported. */
    /* 30 bytes, total size 157 */
    
    /* Color Matching Descriptor */
    0x06,                                 /* bLength */
    0x24,                                 /* bDescriptorType : CS_INTERFACE */
    0x0D,                                 /* bDescriptorSubType : VS_COLORFORMAT */
    0x01,                                 /* bColorPrimarie : 1: BT.709, sRGB (default) */
    0x01,                                 /* bTransferCharacteristics : 1: BT.709 (default) */
    0x04,                                 /* bMatrixCoefficients : 1: BT. 709. */
    /* 6 bytes, total size 163 */
    
    /* Standard VS Interface Descriptor */
    0x09,
    0x04,
    0x01,
    0x01,
    0x01,
    0x0e,
    0x02,
    0x00,
    0x00,
    /* 9 bytes, total size 172 */ // 153
    
    /* Standard VS Isochronous Video Data Endpoint Descriptor */
    0x07,
    0x05,
    0x81,
    0x01,
    MAKE_WORD(PACKET_SIZE),
    0x01,
    /* 7 bytes, total size 179 */ // 160
  };

#if   UNCOMPRESS
const u8 Speaker_ConfigDescriptor_oldVersion[] =
#else
const u8 Speaker_ConfigDescriptor/*_oldVersion*/[] =
#endif
  {
    /* Configuration Descriptor */
    0x09,                                /* bLength */
    USB_CONFIGURATION_DESCRIPTOR_TYPE,   /* bDescriptorType */
    SPEAKER_SIZ_CONFIG_DESC,             /* wTotalLength  0x90 bytes*/
    0x00,
    0x04,                                 /* bNumInterfaces */
    0x01,                                 /* bConfigurationValue */
    0x00,                                 /* iConfiguration */
    0x80,                                 /* bmAttributes  BUS Powred, no remote wakeup*/
    0xFA,                                 /* bMaxPower = 500 mA*/
    /* 09 byte, total size 9*/

    /* Standard Video Interface Collection IAD */
    0x08,                                 /* bLength */
    USB_ASSOCIATION_DESCRIPTOR_TYPE,      /* bDescriptorType */
    0x00,                                 /* bFirstInterface: Interface number of the VideoControl interface that is associated with this function*/
    0x02,                                 /* Number of contiguous Video interfaces that are associated with this function */
    0x0E,                                 /* bFunction Class: CC_VIDEO*/
    0x03,                                 /* bFunction sub Class: SC_VIDEO_INTERFACE_COLLECTION */
    0x00,                                 /* bFunction protocol : PC_PROTOCOL_UNDEFINED*/
    0x02,                                 /* iFunction */
    /* 08 bytes, total size 17*/
    
    /* Standard VC Interface Descriptor */
    0x09,                                 /* bLength */
    0x04,                                 /* bDescriptorType */
    0x00,                                 /* bInterfaceNumber */
    0x00,                                 /* bAlternateSetting */
    0x00,                                 /* bNumEndpoints */
    0x0e,                                 /* bInterfaceClass : CC_VIDEO */
    0x01,                                 /* bInterfaceSubClass : SC_VIDEOCONTROL */
    0x00,                                 /* bInterfaceProtocol : PC_PROTOCOL_UNDEFINED */
    0x02,                                 /* iInterface */
    /* 09 bytes, total size 26*/
    
    /* Class-specific VC Interface Descriptor */
    0x0d,                                 /* bLength */
    0x24,                                 /* bDescriptorType : CS_INTERFACE */
    0x01,                                 /* bDescriptorSubType : VC_HEADER subtype */
    0x00,                                 /* bcdUVC : Revision of class specification that this device is based upon. For this example, the device complies with Video Class specification version 1.0 */
    0x01,
    0x1e,                                 /* wTotalLength : Total size of class-specific descriptors*/
    0x00,
    0x80, 0x8d, 0x5b, 0x00,               /* dwClockFrequency : 0x005b8d80 -> 6,000,000 == 6MHz*/
    0x01,                                 /* bInCollection : Number of streaming interfaces. */
    0x01,                                 /* baInterfaceNr(1) : VideoStreaming interface 1 belongs to this VideoControl interface.*/
    /* 13 Bytes, totoal size 39 */
    
    /* Input Terminal Descriptor (Composite) */
    0x08,                                 /* bLength */
    0x24,                                 /* bDescriptorType : CS_INTERFACE */
    0x02,                                 /* bDescriptorSubType : VC_INPUT_TERMINAL subtype */
    0x02,                                 /* bTerminalID: ID of this input terminal */
    0x01, 0x04,                           /* wTerminalType: 0x0401 COMPOSITE_CONNECTOR type. This terminal is the composite connector. */
    0x00,                                 /* bAssocTerminal: No association */
    0x00,                                 /* iTerminal: Unused*/
    /* 8 Bytes, totoal size 47 */
  
    /* Output Terminal Descriptor */
    0x09,                                 /* bLength */
    0x24,                                 /* bDescriptorType : CS_INTERFACE */
    0x03,                                 /* bDescriptorSubType : VC_OUTPUT_TERMINAL subtype */
    0x03,                                 /* bTerminalID: ID of this output terminal */
    0x01, 0x01,                           /* wTerminalType: 0x0101 TT_STREAMING type. This terminal is a USB streaming terminal. */
    0x00,                                 /* bAssocTerminal: No association */
    0x02,                                 /* bSourceID: The input pin of this unit is connected to the output pin of unit 2. */
    0x00,                                 /* iTerminal: Unused*/
    /* 9 bytes, total size 56 */

    /* Standard VS Interface Descriptor*/
    0x09,                                 /* bLength */
    0x04,                                 /* bDescriptorType : INTERFACE */
    0x01,                                 /* bInterfaceNumber */
    0x00,                                 /* bAlternateSetting */
    0x00,                                 /* bNumEndpoints : 0 endpoints 每 no bandwidth used*/
    0x0e,                                 /* bInterfaceClass : CC_VIDEO */
    0x02,                                 /* bInterfaceSubClass : SC_VIDEOSTREAMING */
    0x00,                                 /* bInterfaceProtocol : PC_PROTOCOL_UNDEFINED */
    0x00,                                 /* iInterface : unused */
    /* 9 bytes, total size 65 */
    
    /* Class-specific VS Header Descriptor (Input) */
    0x0e,                                 /* bLength */
    0x24,                                 /* bDescriptorType : CS_INTERFACE */
    0x01,                                 /* bDescriptorSubType : VC_HEADER subtype */
    0x01,                                 /* bNumFormats : One format descriptor follows. */
    0x3f, 0x00,                           /* wTotalLength : Total size of class-specific descriptors*/
    0x81,                                 /* bEndpointAddress : 0x81 */
    0x00,                                 /* bmInfo : No dynamic format change supported. */
    0x03,                                 /* bTerminalLink : This VideoStreaming interface supplies terminal ID 3 (Output Terminal). */
    0x00,                                 /* bStillCaptureMethod : Device supports still image capture method 0. */
    0x00,                                 /* bTriggerSupport : Hardware trigger supported for still image capture */
    0x00,                                 /* bTriggerUsage : Hardware trigger should initiate a still image capture. */
    0x01,                                 /* bControlSize : Size of the bmaControls field */
    0x00,                                 /* bmaControls : No VideoStreaming specific controls are supported.*/
    /* 14 Bytes, totoal size 79 */
    
    /* Class-specific VS Format Descriptor  */   
    0x0b,                                 /* bLength */
    0x24,                                 /* bDescriptorType : CS_INTERFACE */
    0x06,                                 /* bDescriptorSubType : VS_FORMAT_MJPEG subtype */
    0x01,                                 /* bFormatIndex : First (and only) format descriptor */
    0x01,                                 /* bNumFrameDescriptors : One frame descriptor for this format follows. */
    0x01,                                 /* bmFlags : Uses fixed size samples.. */
    0x01,                                 /* bDefaultFrameIndex : Default frame index is 1. */
    0x00,                                 /* bAspectRatioX : Non-interlaced stream 每 not required. */
    0x00,                                 /* bAspectRatioY : Non-interlaced stream 每 not required. */
    0x00,                                 /* bmInterlaceFlags : Non-interlaced stream */
    0x00,                                 /* bCopyProtect : No restrictions imposed on the duplication of this video stream. */
    /* 11 bytes, total size 90 */
    
    /* Class-specific VS Frame Descriptor */
    0x26,                                 /* bLength */
    0x24,                                 /* bDescriptorType : CS_INTERFACE */
    0x07,                                 /* bDescriptorSubType : VS_FRAME_MJPEG */
    0x01,                                 /* bFrameIndex : First (and only) frame descriptor */
    0x02,                                 /* bmCapabilities : Still images using capture method 0 are supported at this frame setting.D1: Fixed frame-rate. */
    MAKE_WORD(WIDTH),                     /* wWidth : Width of frame is 176 pixels. */
    MAKE_WORD(HEIGHT),                    /* wHeight : Height of frame is 144 pixels. */
    MAKE_DWORD(MIN_BIT_RATE),             /* dwMinBitRate : Min bit rate in bits/s  */
    MAKE_DWORD(MAX_BIT_RATE),             /* dwMaxBitRate : Max bit rate in bits/s  */
    MAKE_DWORD(MAX_FRAME_SIZE),           /* dwMaxVideoFrameBufSize : Maximum video or still frame size, in bytes. */
    MAKE_DWORD(INTERVEL),                 /* dwDefaultFrameInterval : 1,000,000 * 100ns -> 10 FPS */
    0x00,                                 /* bFrameIntervalType : Continuous frame interval */
    MAKE_DWORD(INTERVEL),                 /* dwMinFrameInterval : 1,000,000 ns  *100ns -> 10 FPS */
    MAKE_DWORD(INTERVEL),                 /* dwMaxFrameInterval : 1,000,000 ns *100ns -> 10 FPS */
    0x00, 0x00, 0x00, 0x00,               /* dwFrameIntervalStep : No frame interval step supported. */
    /* 38 bytes, total size 128 */

    /* Standard VS Interface Descriptor */
    0x09,
    0x04,
    0x01,
    0x01,
    0x01,
    0x0e,
    0x02,
    0x00,
    0x00,
    /* 9 bytes, total size 137 */ // 153
    
    /* Standard VS Isochronous Video Data Endpoint Descriptor */
    0x07,
    0x05,
    0x81,
    0x05,
    MAKE_WORD(PACKET_SIZE),
    0x01,
    /* 7 bytes, total size 144 */ // 160
    
    
    
    // Add a hid mouse descriptor
    /************** Descriptor of Joystick Mouse interface ****************/
    /* 09 */
    0x09,         /*bLength: Interface Descriptor size*/
    USB_INTERFACE_DESCRIPTOR_TYPE,/*bDescriptorType: Interface descriptor type*/
    0x02,         /*bInterfaceNumber: Number of Interface*/
    0x00,         /*bAlternateSetting: Alternate setting*/
    0x01,         /*bNumEndpoints*/
    0x03,         /*bInterfaceClass: HID*/
    0x01,         /*bInterfaceSubClass : 1=BOOT, 0=no boot*/
    0x02,         /*nInterfaceProtocol : 0=none, 1=keyboard, 2=mouse*/
    0,            /*iInterface: Index of string descriptor*/
    /******************** Descriptor of Joystick Mouse HID ********************/
    /* 18 */
    0x09,         /*bLength: HID Descriptor size*/
    HID_DESCRIPTOR_TYPE, /*bDescriptorType: HID*/
    0x00,         /*bcdHID: HID Class Spec release number*/
    0x01,
    0x00,         /*bCountryCode: Hardware target country*/
    0x01,         /*bNumDescriptors: Number of HID class descriptors to follow*/
    0x22,         /*bDescriptorType*/
    JOYSTICK_SIZ_REPORT_DESC,/*wItemLength: Total length of Report descriptor*/
    0x00,
    /******************** Descriptor of Joystick Mouse endpoint ********************/
    /* 27 */
    0x07,          /*bLength: Endpoint Descriptor size*/
    USB_ENDPOINT_DESCRIPTOR_TYPE, /*bDescriptorType:*/

    0x82,          /*bEndpointAddress: Endpoint Address (IN)*/
    0x03,          /*bmAttributes: Interrupt endpoint*/
    0x40,          /*wMaxPacketSize: 4 Byte max */
    0x00,
    0x08,          /*bInterval: Polling Interval (32 ms)*/
    
    
    // Add a hid keyboard descriptor
    /************** Descriptor of Joystick Mouse interface ****************/
    /* 09 */
    0x09,         /*bLength: Interface Descriptor size*/
    USB_INTERFACE_DESCRIPTOR_TYPE,/*bDescriptorType: Interface descriptor type*/
    0x03,         /*bInterfaceNumber: Number of Interface*/
    0x00,         /*bAlternateSetting: Alternate setting*/
    0x01,         /*bNumEndpoints*/
    0x03,         /*bInterfaceClass: HID*/
    0x01,         /*bInterfaceSubClass : 1=BOOT, 0=no boot*/
    0x01,         /*nInterfaceProtocol : 0=none, 1=keyboard, 2=mouse*/
    0,            /*iInterface: Index of string descriptor*/
    /******************** Descriptor of Joystick Mouse HID ********************/
    /* 18 */
    0x09,         /*bLength: HID Descriptor size*/
    HID_DESCRIPTOR_TYPE, /*bDescriptorType: HID*/
    0x00,         /*bcdHID: HID Class Spec release number*/
    0x01,
    0x00,         /*bCountryCode: Hardware target country*/
    0x01,         /*bNumDescriptors: Number of HID class descriptors to follow*/
    0x22,         /*bDescriptorType*/
    KEYBOARD_SIZ_REPORT_DESC,/*wItemLength: Total length of Report descriptor*/
    0x00,
    /******************** Descriptor of Joystick Mouse endpoint ********************/
    /* 27 */
    0x07,          /*bLength: Endpoint Descriptor size*/
    USB_ENDPOINT_DESCRIPTOR_TYPE, /*bDescriptorType:*/

    0x83,          /*bEndpointAddress: Endpoint Address (IN)*/
    0x03,          /*bmAttributes: Interrupt endpoint*/
    0x40,          /*wMaxPacketSize: 4 Byte max */
    0x00,
    0x08,          /*bInterval: Polling Interval (32 ms)*/
    
  };


const u8 Joystick_ReportDescriptor[JOYSTICK_SIZ_REPORT_DESC] =
{
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
    0x09, 0x02,                    // USAGE (Mouse)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x85, MOUSE_REPORT_ID,         //   REPORT_ID (MOUSE_REPORT_ID)
    0x09, 0x01,                    //   USAGE (Pointer)
    0xa1, 0x00,                    //   COLLECTION (Physical)
    0x05, 0x09,                    //     USAGE_PAGE (Button)
    0x19, 0x01,                    //     USAGE_MINIMUM (Button 1)
    0x29, 0x03,                    //     USAGE_MAXIMUM (Button 3)
    0x15, 0x00,                    //     LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //     LOGICAL_MAXIMUM (1)
    0x95, 0x03,                    //     REPORT_COUNT (3)
    0x75, 0x01,                    //     REPORT_SIZE (1)
    0x81, 0x02,                    //     INPUT (Data,Var,Abs)
    0x95, 0x01,                    //     REPORT_COUNT (1)
    0x75, 0x05,                    //     REPORT_SIZE (5)
    0x81, 0x01,                    //     INPUT (Cnst,Ary,Abs)
    0x05, 0x01,                    //     USAGE_PAGE (Generic Desktop)
    0x09, 0x30,                    //     USAGE (X)
    0x09, 0x31,                    //     USAGE (Y)
    0x09, 0x38,                    //     USAGE (Wheel)
    0x15, 0x81,                    //     LOGICAL_MINIMUM (-127)
    0x25, 0x7f,                    //     LOGICAL_MAXIMUM (127)
    0x75, 0x08,                    //     REPORT_SIZE (8)
    0x95, 0x03,                    //     REPORT_COUNT (3)
    0x81, 0x06,                    //     INPUT (Data,Var,Rel)
    0xc0,                          //   END_COLLECTION
    0xc0,                          // END_COLLECTION
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
    0x09, 0x04,                    // USAGE (Joystick)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x85, JOYSTICK_REPORT_ID,      //   REPORT_ID (JOYSTICK_REPORT_ID)
    0x05, 0x01,                    //   USAGE_PAGE (Generic Desktop)
    0x09, 0x01,                    //   USAGE (Pointer)
    0xa1, 0x00,                    //   COLLECTION (Physical)
    0x15, 0x81,                    //     LOGICAL_MINIMUM (-127)
    0x25, 0x7f,                    //     LOGICAL_MAXIMUM (127)
    0x75, 0x08,                    //     REPORT_SIZE (8)
    0x95, 0x05,                    //     REPORT_COUNT (5)
    0x09, 0x30,                    //     USAGE (X)
    0x09, 0x31,                    //     USAGE (Y)
    0x09, 0x33,                    //     USAGE (Rx)
    0x09, 0x34,                    //     USAGE (Ry)
    0x09, 0x35,                    //     USAGE (Rz)
    0x81, 0x02,                    //     INPUT (Data,Var,Abs)
    0x15, 0x00,                    //     LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //     LOGICAL_MAXIMUM (1)
    0x95, 0x0a,                    //     REPORT_COUNT (10)
    0x75, 0x01,                    //     REPORT_SIZE (1)
    0x05, 0x09,                    //     USAGE_PAGE (Button)
    0x19, 0x01,                    //     USAGE_MINIMUM (Button 1)
    0x29, 0x0a,                    //     USAGE_MAXIMUM (Button 10)
    0x65, 0x00,                    //     UNIT (None)
    0x81, 0x02,                    //     INPUT (Data,Var,Abs)
    0x75, 0x06,                    //     REPORT_SIZE (6)
    0x95, 0x01,                    //     REPORT_COUNT (1)
    0x81, 0x01,                    //     INPUT (Cnst,Ary,Abs)
    0xc0,                          //   END_COLLECTION
    0xc0                           // END_COLLECTION
};

const u8 Keyboard_ReportDescriptor[KEYBOARD_SIZ_REPORT_DESC] =
  {
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
    0x09, 0x06,                    // USAGE (Keyboard)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
    0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
    0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,                    //   REPORT_SIZE (1)
    0x95, 0x08,                    //   REPORT_COUNT (8)
    0x81, 0x02,                    //   INPUT (Data,Var,Abs)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x81, 0x01,                    //   INPUT (Cnst,Ary,Abs)
    0x95, 0x05,                    //   REPORT_COUNT (5)
    0x75, 0x01,                    //   REPORT_SIZE (1)
    0x05, 0x08,                    //   USAGE_PAGE (LEDs)
    0x19, 0x01,                    //   USAGE_MINIMUM (Num Lock)
    0x29, 0x05,                    //   USAGE_MAXIMUM (Kana)
    0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x75, 0x03,                    //   REPORT_SIZE (3)
    0x91, 0x01,                    //   OUTPUT (Cnst,Ary,Abs)
    0x95, 0x06,                    //   REPORT_COUNT (6)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x65,                    //   LOGICAL_MAXIMUM (101)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
    0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
    0x29, 0x65,                    //   USAGE_MAXIMUM (Keyboard Application)
    0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
    0xc0,                          // END_COLLECTION
  }; /* Keyboard_ReportDescriptor */

/* USB String Descriptor (optional) */
const u8 Speaker_StringLangID[SPEAKER_SIZ_STRING_LANGID] =
  {
    0x04,
    0x03,
    0x09,
    0x04
  }
  ; /* LangID = 0x0409: U.S. English */

const u8 Speaker_StringVendor[SPEAKER_SIZ_STRING_VENDOR] =
  {
    SPEAKER_SIZ_STRING_VENDOR, /* Size of manufaturer string */
    USB_STRING_DESCRIPTOR_TYPE,  /* bDescriptorType*/
    /* Manufacturer: "STMicroelectronics" */
    'l', 0, 'x', 0, 'y', 0, 'p', 0, 'p', 0, 'c', 0,'\'', 0, 's', 0,
    ' ', 0, 'D', 0, 'e', 0, 'm', 0, 'o', 0, ' ', 0, 'P', 0, 'r', 0,
    'o', 0, 'j', 0, 'e', 0, 'c', 0, 't', 0,
  };

const u8 Speaker_StringProduct[SPEAKER_SIZ_STRING_PRODUCT] =
  {
    SPEAKER_SIZ_STRING_PRODUCT,  /* bLength */
    USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
    'C', 0, 'a', 0, 'm', 0, 'e', 0, 'r', 0, 'a', 0,
    ' ', 0, 'T', 0, 'e', 0, 't', 0, 'r', 0, 'i', 0, 's', 0
  };

u8 Speaker_StringSerial[SPEAKER_SIZ_STRING_SERIAL] =
  {
    SPEAKER_SIZ_STRING_SERIAL,  /* bLength */
    USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
    'l', 0, 'x', 0, 'y', 0, 'p', 0, 'p', 0, 'c', 0, ' ', 0
  };
/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Extern function prototypes ------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
