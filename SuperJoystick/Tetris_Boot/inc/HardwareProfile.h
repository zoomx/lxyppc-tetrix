/*********************************************************************
 *
 *	Hardware specific definitions
 *
 *********************************************************************
 * FileName:        HardwareProfile.h
 * Dependencies:    None
 * Processor:       PIC24F, PIC24H, dsPIC, PIC32
 * Compiler:        Microchip C32 v1.00 or higher
 *					Microchip C30 v3.01 or higher
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright ?2002-2008 Microchip Technology Inc.  All rights 
 * reserved.
 *
 * Microchip licenses to you the right to use, modify, copy, and 
 * distribute: 
 * (i)  the Software when embedded on a Microchip microcontroller or 
 *      digital signal controller product (“Device? which is 
 *      integrated into Licensee’s product; or
 * (ii) ONLY the Software driver source files ENC28J60.c and 
 *      ENC28J60.h ported to a non-Microchip device used in 
 *      conjunction with a Microchip ethernet controller for the 
 *      sole purpose of interfacing with the ethernet controller. 
 *
 * You should refer to the license agreement accompanying this 
 * Software for additional information regarding your rights and 
 * obligations.
 *
 * THE SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS?WITHOUT 
 * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
 * LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR A 
 * PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL 
 * MICROCHIP BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR 
 * CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF 
 * PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS 
 * BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE 
 * THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER 
 * SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF CONTRACT, TORT 
 * (INCLUDING NEGLIGENCE), BREACH OF WARRANTY, OR OTHERWISE.
 *
 *
 * Author               Date		Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Howard Schlunder		10/03/06	Original, copied from Compiler.h
 ********************************************************************/
#ifndef __HARDWARE_PROFILE_H
#define __HARDWARE_PROFILE_H

/*********************************************************************
* GetSystemClock() returns system clock frequency.
*
* GetPeripheralClock() returns peripheral clock frequency.
*
* GetInstructionClock() returns instruction clock frequency.
*
********************************************************************/

/*********************************************************************
* Macro: #define	GetSystemClock() 
*
* Overview: This macro returns the system clock frequency in Hertz.
*			* value is 8 MHz x 4 PLL for PIC24
*			* value is 8 MHz/2 x 18 PLL for PIC32
*
********************************************************************/
#if defined(__PIC24F__)	
	#define	GetSystemClock()            (32000000ul)          
#elif defined(__PIC32MX__)
	#define	GetSystemClock() 			(72000000ul)
#elif defined(__dsPIC33F__) || defined(__PIC24H__)
	#define GetSystemClock() 			(80000000ul)
#elif defined(_STM32_)
        #define GetSystemClock() 			(72000000ul)
#endif

/*********************************************************************
* Macro: #define	GetPeripheralClock() 
*
* Overview: This macro returns the peripheral clock frequency 
*			used in Hertz.
*			* value for PIC24 is <PRE>(GetSystemClock()/2) </PRE> 
*			* value for PIC32 is <PRE>(GetSystemClock()/(1<<OSCCONbits.PBDIV)) </PRE>
*
********************************************************************/
#if defined(__PIC24F__)	|| defined(__PIC24H__) || defined(__dsPIC33F__)
	#define	GetPeripheralClock()		(GetSystemClock()/2)
#elif defined(__PIC32MX__)
	#define	GetPeripheralClock()		(GetSystemClock()/(1<<OSCCONbits.PBDIV))
#elif defined(_STM32_)
        #define	GetPeripheralClock()		(GetSystemClock())
#endif

/*********************************************************************
* Macro: #define	GetInstructionClock() 
*
* Overview: This macro returns instruction clock frequency 
*			used in Hertz.
*			* value for PIC24 is <PRE>(GetSystemClock()/2) </PRE> 
*			* value for PIC32 is (GetSystemClock()/PFMWSbits.CHECON) </PRE> 
*
********************************************************************/
#if defined(__PIC24F__)	|| defined(__PIC24H__) || defined(__dsPIC33F__)
	#define	GetInstructionClock()		(GetSystemClock()/2)
#elif defined(__PIC32MX__)
	#define	GetInstructionClock()		(GetSystemClock()/PFMWSbits.CHECON)
#elif defined(_STM32_)
        #define	GetInstructionClock()		(GetSystemClock())
#endif


/*********************************************************************
* IOS FOR THE DISPLAY CONTROLLER
*********************************************************************/
#if (GRAPHICS_PICTAIL_VERSION == 1)

// Definitions for reset pin
#define RST_TRIS_BIT       TRISCbits.TRISC1
#define RST_LAT_BIT        LATCbits.LATC1

// Definitions for RS pin
#define RS_TRIS_BIT        TRISBbits.TRISB15
#define RS_LAT_BIT         LATBbits.LATB15

// Definitions for CS pin
#define CS_TRIS_BIT        TRISDbits.TRISD8
#define CS_LAT_BIT         LATDbits.LATD8

// Definitions for FLASH CS pin 
#define CS_FLASH_LAT_BIT   LATDbits.LATD9
#define CS_FLASH_TRIS_BIT  TRISDbits.TRISD9


#elif (GRAPHICS_PICTAIL_VERSION == 2)

#if  (DISPLAY_CONTROLLER == LGDP4531)

#if defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__) 

// Definitions for reset pin
#define RST_TRIS_BIT       TRISAbits.TRISA4
#define RST_LAT_BIT        LATAbits.LATA4

// Definitions for RS pin
#define RS_TRIS_BIT        TRISAbits.TRISA1
#define RS_LAT_BIT         LATAbits.LATA1

// Definitions for CS pin
#define CS_TRIS_BIT        TRISBbits.TRISB15
#define CS_LAT_BIT         LATBbits.LATB15

// Definitions for FLASH CS pin 
#define CS_FLASH_LAT_BIT   LATAbits.LATA8
#define CS_FLASH_TRIS_BIT  TRISAbits.TRISA8

// Definitions for POWER ON pin
#define POWERON_LAT_BIT    LATAbits.LATA10		
#define POWERON_TRIS_BIT   TRISAbits.TRISA10	

#else

// Definitions for reset pin
#define RST_TRIS_BIT       TRISCbits.TRISC1
#define RST_LAT_BIT        LATCbits.LATC1

// Definitions for RS pin
#define RS_TRIS_BIT        TRISCbits.TRISC2
#define RS_LAT_BIT         LATCbits.LATC2

// Definitions for CS pin
#define CS_TRIS_BIT        TRISDbits.TRISD10
#define CS_LAT_BIT         LATDbits.LATD10

// Definitions for FLASH CS pin 
#define CS_FLASH_LAT_BIT   LATDbits.LATD1
#define CS_FLASH_TRIS_BIT  TRISDbits.TRISD1

// Definitions for POWER ON pin
#define POWERON_LAT_BIT    LATCbits.LATC3
#define POWERON_TRIS_BIT   TRISCbits.TRISC3

#endif

#elif (DISPLAY_CONTROLLER == SSD1906)

// Definitions for reset line
#define RST_TRIS_BIT       TRISCbits.TRISC1
#define RST_LAT_BIT        LATCbits.LATC1

// Definitions for RS line
#define RS_TRIS_BIT        TRISCbits.TRISC2
#define RS_LAT_BIT         LATCbits.LATC2

// Definitions for CS line
#define CS_TRIS_BIT        TRISDbits.TRISD10
#define CS_LAT_BIT         LATDbits.LATD10

// Definitions for A0 line
#define A0_LAT_BIT         LATDbits.LATD3
#define A0_TRIS_BIT        TRISDbits.TRISD3

// Definitions for A17 line 
#define A17_LAT_BIT        LATGbits.LATG14
#define A17_TRIS_BIT       TRISGbits.TRISG14

#else

#error	GRAPHICS CONTROLLER IS NOT SUPPORTED

#endif  // (DISPLAY_CONTROLLER == ...

#elif (GRAPHICS_PICTAIL_VERSION == 3)

#if defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__) 

// Definitions for reset pin
#define RST_TRIS_BIT       TRISAbits.TRISA4
#define RST_LAT_BIT        LATAbits.LATA4

// Definitions for RS pin
#define RS_TRIS_BIT        TRISAbits.TRISA1
#define RS_LAT_BIT         LATAbits.LATA1

// Definitions for CS pin
#define CS_TRIS_BIT        TRISBbits.TRISB15
#define CS_LAT_BIT         LATBbits.LATB15

#else

// Definitions for reset line
#define RST_TRIS_BIT       TRISCbits.TRISC1
#define RST_LAT_BIT        LATCbits.LATC1

// Definitions for RS line
#define RS_TRIS_BIT        TRISCbits.TRISC2
#define RS_LAT_BIT         LATCbits.LATC2

// Definitions for CS line
#define CS_TRIS_BIT        TRISDbits.TRISD10
#define CS_LAT_BIT         LATDbits.LATD10

#endif

#endif // (GRAPHICS_PICTAIL_VERSION == ...

/*********************************************************************
* IO FOR THE BEEPER
*********************************************************************/
#if defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__) 
#define BEEP_TRIS_BIT         TRISBbits.TRISB4
#define BEEP_LAT_BIT          LATBbits.LATB4
#else
#define BEEP_TRIS_BIT         TRISDbits.TRISD0
#define BEEP_LAT_BIT          LATDbits.LATD0
#endif

/*********************************************************************
* IOS FOR THE FLASH/EEPROM SPI
*********************************************************************/
#if (GRAPHICS_PICTAIL_VERSION < 3)

#if defined (__C30__)
	#if defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__) 
        #define EEPROM_CS_TRIS       TRISAbits.TRISA0
        #define EEPROM_CS_LAT        LATAbits.LATA0		
    #elif defined( __PIC24FJ256GB110__ )
        // This PIM has RD12 rerouted to RG0
        #define EEPROM_CS_TRIS       TRISGbits.TRISG0
        #define EEPROM_CS_LAT        LATGbits.LATG0
    #else
        #define EEPROM_CS_TRIS       TRISDbits.TRISD12
        #define EEPROM_CS_LAT        LATDbits.LATD12
    #endif
#elif defined( __PIC32MX__ )
    #define EEPROM_CS_TRIS       TRISDbits.TRISD12
    #define EEPROM_CS_LAT        LATDbits.LATD12
#endif

#if defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__) 
#define EEPROM_SCK_TRIS      TRISCbits.TRISC2
#define EEPROM_SDO_TRIS      TRISCbits.TRISC0
#define EEPROM_SDI_TRIS      TRISCbits.TRISC1
#else
#define EEPROM_SCK_TRIS      TRISGbits.TRISG6
#define EEPROM_SDO_TRIS      TRISGbits.TRISG8
#define EEPROM_SDI_TRIS      TRISGbits.TRISG7
#endif

#else

#if defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__) 
#define SST25_CS_TRIS       TRISAbits.TRISA8
#define SST25_CS_LAT        LATAbits.LATA8
#define SST25_SCK_TRIS      TRISCbits.TRISC2
#define SST25_SDO_TRIS      TRISCbits.TRISC0
#define SST25_SDI_TRIS      TRISCbits.TRISC1
#else
#define SST25_CS_TRIS       TRISDbits.TRISD1
#define SST25_CS_LAT        LATDbits.LATD1
#define SST25_SCK_TRIS      TRISGbits.TRISG6
#define SST25_SDO_TRIS      TRISGbits.TRISG8
#define SST25_SDI_TRIS      TRISGbits.TRISG7
#endif

#endif

/*********************************************************************
* IOS FOR THE TOUCH SCREEN
*********************************************************************/
// ADC channel constants
#if defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__) 
    #define ADC_TEMP        4
    #define ADC_POT         0
    #define ADC_POT_TRIS 	TRISAbits.TRISA0
    #define ADC_POT_PCFG	AD1PCFGLbits.PCFG0
#elif defined(__PIC32MX__)
    #define ADC_TEMP        ADC_CH0_POS_SAMPLEA_AN4
    #define ADC_POT         ADC_CH0_POS_SAMPLEA_AN5
#else
    #define ADC_TEMP        4
    #define ADC_POT         5
#endif

#if (GRAPHICS_PICTAIL_VERSION == 1)

    #ifdef __PIC32MX__
        #define ADC_XPOS        ADC_CH0_POS_SAMPLEA_AN13
        #define ADC_YPOS        ADC_CH0_POS_SAMPLEA_AN12
    #else
        #define ADC_XPOS        13
        #define ADC_YPOS        12
    #endif
    
    // Y port definitions
    #define ADPCFG_XPOS     AD1PCFGbits.PCFG13
    #define LAT_XPOS        LATBbits.LATB13 
    #define LAT_XNEG        LATBbits.LATB11
    #define TRIS_XPOS       TRISBbits.TRISB13
    #define TRIS_XNEG       TRISBbits.TRISB11 
    
    // X port definitions
    #define ADPCFG_YPOS     AD1PCFGbits.PCFG12
    #define LAT_YPOS        LATBbits.LATB12  
    #define LAT_YNEG        LATBbits.LATB10 
    #define TRIS_YPOS       TRISBbits.TRISB12
    #define TRIS_YNEG       TRISBbits.TRISB10 

#elif (GRAPHICS_PICTAIL_VERSION == 2)

	#if defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__) 
        #define ADC_XPOS        5
        #define ADC_YPOS        4	
    #elif defined(__PIC32MX__)
        #define ADC_XPOS        ADC_CH0_POS_SAMPLEA_AN11
        #define ADC_YPOS        ADC_CH0_POS_SAMPLEA_AN10
    #else
        #define ADC_XPOS        11
        #define ADC_YPOS        10
    #endif
 
 	#if defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__) 
 	
    // Y port definitions
    #define ADPCFG_XPOS     AD1PCFGLbits.PCFG5	
    #define LAT_XPOS        LATBbits.LATB3
    #define LAT_XNEG        LATCbits.LATC9
    #define TRIS_XPOS       TRISBbits.TRISB3
    #define TRIS_XNEG       TRISCbits.TRISC9
    
    // X port definitions
    #define ADPCFG_YPOS     AD1PCFGLbits.PCFG4	
    #define LAT_YPOS        LATBbits.LATB2  
    #define LAT_YNEG        LATCbits.LATC8
    #define TRIS_YPOS       TRISBbits.TRISB2
    #define TRIS_YNEG       TRISCbits.TRISC8
    
    #else   
    
    // Y port definitions
    #define ADPCFG_XPOS     AD1PCFGbits.PCFG11
    #define LAT_XPOS        LATBbits.LATB11
    #define LAT_XNEG        LATGbits.LATG13
    #define TRIS_XPOS       TRISBbits.TRISB11
    #define TRIS_XNEG       TRISGbits.TRISG13
    
    // X port definitions
    #define ADPCFG_YPOS     AD1PCFGbits.PCFG10
    #define LAT_YPOS        LATBbits.LATB10  
    #define LAT_YNEG        LATGbits.LATG12 
    #define TRIS_YPOS       TRISBbits.TRISB10
    #define TRIS_YNEG       TRISGbits.TRISG12 
    
    #endif

#elif (GRAPHICS_PICTAIL_VERSION == 3)

 	#if defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__) 
        #define ADC_XPOS        5
        #define ADC_YPOS        4 	
    #elif defined(__PIC32MX__)
        #define ADC_XPOS        ADC_CH0_POS_SAMPLEA_AN11
        #define ADC_YPOS        ADC_CH0_POS_SAMPLEA_AN10
    #else
        #define ADC_XPOS        11
        #define ADC_YPOS        10
    #endif

 	#if defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__) 

	    // Y port definitions
	    #define ADPCFG_XPOS     AD1PCFGLbits.PCFG5	
	    #define LAT_XPOS        LATBbits.LATB3
	    #define LAT_XNEG        LATCbits.LATC9
	    #define TRIS_XPOS       TRISBbits.TRISB3
	    #define TRIS_XNEG       TRISCbits.TRISC9
	    
	    // X port definitions
	    #define ADPCFG_YPOS     AD1PCFGLbits.PCFG4	
	    #define LAT_YPOS        LATBbits.LATB2  
	    #define LAT_YNEG        LATCbits.LATC8
	    #define TRIS_YPOS       TRISBbits.TRISB2
	    #define TRIS_YNEG       TRISCbits.TRISC8
    
	#else 
    
	    // Y port definitions
	    #define ADPCFG_XPOS     AD1PCFGbits.PCFG11
	    #define LAT_XPOS        LATBbits.LATB11
	    #define LAT_XNEG        LATDbits.LATD9
	    #define TRIS_XPOS       TRISBbits.TRISB11
	    #define TRIS_XNEG       TRISDbits.TRISD9
	    
	    // X port definitions
	    #define ADPCFG_YPOS     AD1PCFGbits.PCFG10
	    #define LAT_YPOS        LATBbits.LATB10  
	    #define LAT_YNEG        LATDbits.LATD8 
	    #define TRIS_YPOS       TRISBbits.TRISB10
	    #define TRIS_YNEG       TRISDbits.TRISD8 

	#endif

#endif

/*********************************************************************
* IOS FOR THE SIDE BUTTONS
*********************************************************************/
#if defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__) 
#define BTN_S3 PORTAbits.RA9
#define BTN_S4 0
#define BTN_S5 0
#define BTN_S6 0
#else
#define BTN_S3 PORTDbits.RD6
#define BTN_S4 PORTDbits.RD13
#define BTN_S5 PORTAbits.RA7
#define BTN_S6 PORTDbits.RD7
#endif

#endif // __HARDWARE_PROFILE_H
