/*
** Copyright (c) 2018, Bradley A. Minch
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met: 
** 
**     1. Redistributions of source code must retain the above copyright 
**        notice, this list of conditions and the following disclaimer. 
**     2. Redistributions in binary form must reproduce the above copyright 
**        notice, this list of conditions and the following disclaimer in the 
**        documentation and/or other materials provided with the distribution. 
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
** ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
** LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
** CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
** SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
** INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
** POSSIBILITY OF SUCH DAMAGE.
*/
#include "elecanisms.h"
uint8_t ledState = 0;
uint8_t recentPress = 0;


void __attribute__((interrupt, auto_psv)) _T1Interrupt(void) {
    IFS0bits.T1IF = 0;        // lower Timer1 interrupt flag
    recentPress = FALSE;      // reset recentPress FALSE for button debounce
}

int16_t main(void) {
    init_elecanisms();

    T1CON = 0x0030;           // set Timer1 period to 0.5s
    PR1 = 0x7A11;

    TMR1 = 0;                 // set Timer1 count to 0
    IFS0bits.T1IF = 0;        // lower Timer1 interrupt flag
    IEC0bits.T1IE = 1;        // enable Timer1 interrupt
    T1CONbits.TON = 1;        // turn on Timer1

    LED2 = ON;

    while (1) {
        if (D0 == 1 && recentPress == 0) {
          ledState++;
          TMR1 = 0;           // reset Timer1 count
          recentPress = TRUE; // set recentPress flag TRUE for button debounce
        }

        if (ledState > 7) {
          ledState = 0;       // reset ledState to 0
        }

        // With ledState being incremented, this displays counting by one in
        // binary on the LEDs.
        LED1 = (ledState >> 0) & 0x01;
        LED2 = (ledState >> 1) & 0x01;
        LED3 = (ledState >> 2) & 0x01;
    }
}

