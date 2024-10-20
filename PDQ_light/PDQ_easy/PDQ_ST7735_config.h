//
// PDQ_ST7735 configuration
//
#define INITR_MINI160x80_PLUGIN 0x06  // din Adafruit_ST7735.h

// ST7735 has several variations, set your version based on this list (using the color of the "tab" on the screen cover).
// NOTE: The tab colors refer to Adafruit versions, other suppliers may vary (you may have to experiment to find the right one).
enum
{
	ST7735_INITB				= 0,				// 1.8" (128x160) ST7735B chipset (only one type)
	ST7735_INITR_GREENTAB		= 1,				// 1.8" (128x160) ST7735R chipset with green tab (same as ST7735_INITR_18GREENTAB)
	ST7735_INITR_REDTAB			= 2,				// 1.8" (128x160) ST7735R chipset with red tab (same as ST7735_INITR_18REDTAB)
	ST7735_INITR_BLACKTAB		= 3,				// 1.8" (128x160) ST7735S chipset with black tab (same as ST7735_INITR_18BLACKTAB)
	ST7735_INITR_144GREENTAB   	= 4,				// 1.4" (128x128) ST7735R chipset with green tab
	ST7735_INITR_18GREENTAB		= ST7735_INITR_GREENTAB,	// 1.8" (128x160) ST7735R chipset with green tab
	ST7735_INITR_18REDTAB		= ST7735_INITR_REDTAB,		// 1.8" (128x160) ST7735R chipset with red tab
	ST7735_INITR_18BLACKTAB		= ST7735_INITR_BLACKTAB,	// 1.8" (128x160) ST7735S chipset with black tab
	ST7735_INITR_096_BLACKTAB	= INITR_MINI160x80_PLUGIN
};

#define ST7735_CHIPSET		ST7735_INITR_096_BLACKTAB	// <= Set ST7735 LCD chipset/variation here (from above list) In Adafruit e BLACKTAB = 2 !!
													// iar ce am eu este Green tab! Dar cu setarea Green, am rosu<->albastru inversate! Haos! LMA
	
// LMA pinii sunt definiti conform Arduino - pinii placii, nu ai uC! Mie nu-mi folosesc asa, ca nu vreau Arduino shit!
//#define	ST7735_CS_PIN		10			// <= /CS pin (chip-select, LOW to get attention of ST7735, HIGH and it ignores SPI bus)
//#define	ST7735_DC_PIN		8			// <= DC pin (1=data or 0=command indicator line) also called RS

// PINII REALI AI PROCESORULUI, NU GUNOIUL ARDUINO! - LMA
// TOTI PINII FOLOSITI DE AFISAJ SUNT CONECTATI LA PORTUL B, DECI NU-L MAI DEFINESC
// MOSI SI SCK SUNT INITIALIZATE PRIN ACTIVAREA SPI, DECI NU SUNT SETATE NICAIERI DIN NOU
#define	ST7735_CS_PIN		PB2			// <= /CS pin

#define	ST7735_DC_PIN		PB0			// <= DC pin

// Asta e definit de mine:
//#define ST7735_RST_PIN		PB1
#define _BV(bit) (1 << (bit))			// macro do deal with set and clear bits

// other PDQ library options
#define	ST7735_SAVE_SPI_SETTINGS	0			// <= 0/1 with 1 to save AVR SPI control and status registers (required when other SPI devices are in use with other settings)
