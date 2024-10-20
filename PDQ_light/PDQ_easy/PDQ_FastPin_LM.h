#ifndef __INC_FASTPIN_LM_H
#define __INC_FASTPIN_LM_H

//#include<avr/io.h>


#define	ST7735_CS_PIN		PB2			// <= /CS pin

#define	ST7735_DC_PIN		PB0			// <= DC pin

// Asta e definit de mine:
//#define ST7735_RST_PIN		PB1		// Folosesc SW Reset, economisesc un GPIO.

// DEFINESC ACTIUNILE PORTULUI B - SETARI, HI/LO, ETC - INLOCUIND FUNCTIILE ORIGINALE ALE MINUNATULUI FASTPIN
#define CS_HI		PORTB |= _BV(ST7735_CS_PIN);
#define CS_LO		PORTB &= ~(_BV(ST7735_CS_PIN));
#define DC_HI		PORTB |= _BV(ST7735_DC_PIN);
#define DC_LO		PORTB &= ~(_BV(ST7735_DC_PIN));
//#define RST_HI		PORTB |= _BV(ST7735_RST_PIN);
//#define RST_LO		PORTB &= ~(_BV(ST7735_RST_PIN));

#endif
