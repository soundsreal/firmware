/**
  TMR4 Generated Driver API Header File 

  @Company
    Microchip Technology Inc.

  @File Name
    tmr4.h

  @Summary
    This is the generated header file for the TMR4 driver using MPLAB(c) Code Configurator

  @Description
    This header file provides APIs for driver for TMR4. 
    Generation Information : 
        Product Revision  :  MPLAB(c) Code Configurator - 3.16
        Device            :  PIC24FJ128GB204
        Driver Version    :  0.5
    The generated drivers are tested against the following:
        Compiler          :  XC16 1.26
        MPLAB 	          :  MPLAB X 3.20
 */

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

#ifndef _TMR4_H
#define _TMR4_H

/**
  Section: Included Files
 */

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus  // Provide C++ Compatibility

extern "C"
{

#endif

#define TMR4_INTERRUPT_TICKER_FACTOR            6124 /* 160 ms */

    /* Param Fq RDY/CLK. */
    // #define DECODING_RFID_INTERRUPT_TICKER_FACTOR    16 // avec 510-515 us de periode pour DEMOD_OUT (RDY/CLK = 125 kHz --> fonctionne mieux a 125.8 kHz)
    // Pour autre antenne fonctionne a partir de 126.8 kHz
    // Measure DMOD_OUT periode = 480 us
    // --> on observe le signal DMOD_OUT retourne par le module EM4095 en fonction du signal RF que celui recoit en presence du Tag
    // Commence a fonctionner avec 490 us de periode pour DEMOD_OUT (RDY/CLK = 131.5 kHz)
   //#define DECODING_RFID_INTERRUPT_TICKER_FACTOR     15 // 0-15 => 16
  #define DECODING_RFID_INTERRUPT_TICKER_FACTOR    14 // --> ok avec 475 us de periode pour DEMOD_OUT (RDY/CLK = 134 kHz)
//#define DECODING_RFID_INTERRUPT_TICKER_FACTOR   11

#define DECODING_RFID_HALF_PERIODE_READING      7 // 16 / 2
//#define DECODING_RFID_HALF_PERIODE_READING      8 // 16 / 2
#define DECODING_RFID_QUARTER_PERIODE_READING   4 // 16 / 4


    /**
      Section: Interface Routines
     */

    /**
      @Summary
        Initializes hardware and data for the given instance of the TMR module

      @Description
        This routine initializes hardware for the instance of the TMR module,
        using the hardware initialization given data.  It also initializes all
        necessary internal data.

      @Param
        None.

      @Returns
        None
 
      @Example 
        <code>
        bool statusTimer1;
        uint16_t period;
        uint16_t value;

        period = 0x20;

        TMR4_Initialize();

        TMR4_Period16BitSet(period);

        if((value = TMR4_Period16BitGet())== period)
        {
            TMR4_Start();
        }

        while(1)
        {
            TMR4_Tasks();
            if( (statusTimer1 = TMR4_GetElapsedThenClear()) == true)
            {
                TMR4_Stop();
            }
        }
        </code>
     */
    void TMR4_Initialize( void );


    /**
      @Summary
        Updates 16-bit timer value

      @Description
        This routine updates 16-bit timer value

      @Param
        None.

      @Returns
        None
 
      @Example 
        Refer to the example of TMR4_Initialize();
     */

    void TMR4_Period16BitSet( uint16_t value );

    /**

      @Summary
        Provides the timer 16-bit period value

      @Description
        This routine provides the timer 16-bit period value

      @Param
        None.

      @Returns
        Timer 16-bit period value
 
      @Example 
        Refer to the example of TMR4_Initialize();
     */

    uint16_t TMR4_Period16BitGet( void );

    /**
      @Summary
        Updates the timer's 16-bit value

      @Description
        This routine updates the timer's 16-bit value

      @Param
        None.

      @Returns
        None

      @Example 
        <code>
        uint16_t value=0xF0F0;

        TMR4_Counter16BitSet(value));

        while(1)
        {
            TMR4_Tasks();
            if( (value == TMR4_Counter16BitGet()))
            {
                TMR4_Stop();
            }
        }
        </code>
     */

    void TMR4_Counter16BitSet( uint16_t value );

    /**
      @Summary
        Provides 16-bit current counter value

      @Description
        This routine provides 16-bit current counter value

      @Param
        None.

      @Returns
        16-bit current counter value
 
      @Example 
        Refer to the example of TMR4_Counter16BitSet();
     */

    uint16_t TMR4_Counter16BitGet( void );

    /**
      @Summary
        Callback for timer interrupt.

      @Description
        This routine is callback for timer interrupt

      @Param
        None.

      @Returns
        None
 
      @Example 
        Refer to the example of TMR4_Initialize();
     */
    void TMR4_CallBack( void );

    /**
      @Summary
        Starts the TMR

      @Description
        This routine starts the TMR

      @Param
        None.

      @Returns
        None
 
      @Example 
        Refer to the example of TMR4_Initialize();
     */

    void TMR4_Start( void );

    /**
      @Summary
        Stops the TMR

      @Description
        This routine stops the TMR

      @Param
        None.

      @Returns
        None
 
      @Example 
        Refer to the example of TMR4_Initialize();
     */

    void TMR4_Stop( void );

    /**
      @Summary
        Returns the elapsed status of the timer and clears if flag is set.

      @Description
        This routine returns the elapsed status of the timer and clears 
        flag if its set.

      @Param
        None.

      @Returns
        True - Timer has elapsed.
        False - Timer has not elapsed.
 
      @Example 
        Refer to the example of TMR4_Initialize();
     */

    bool TMR4_GetElapsedThenClear( void );

    /**
      @Summary
        Returns the software counter value.

      @Description
        This routine returns the software counter value.

      @Param
        None.

      @Returns
        Software counter value.
 
      @Example 
        Refer to the example of TMR4_Initialize();
     */

    int TMR4_SoftwareCounterGet( void );

    /**
      @Summary
        Clears the software counter value.

      @Description
        This routine clears the software counter value.

      @Param
        None.

      @Returns
        None
 
      @Example 
        Refer to the example of TMR4_Initialize();
     */

    void TMR4_SoftwareCounterClear( void );

#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif

#endif //_TMR4_H

/**
 End of File
 */
