#include "PDQ_ST7735_config.h"		// PDQ: ST7735 pins and other setup for this sketch
#include "PDQ_ST7735.h"				// PDQ: Hardware-specific driver library
PDQ_ST7735 tft;						// PDQ: create LCD object (using pins in "PDQ_ST7735_config.h")

//#include "Fonts/FreeSans24pt7b.h"		// asta e cel folosit in final LMA
#include "Fonts/FreeSans24pt7b_sel.h"

int main(void)
{
	tft.begin();			// initialize LCD
//	tft.setRotation(1);

	tft.fillScreen(ST7735_BLACK);
//	tft.setCursor(20, 40);
	tft.setTextColor(ST7735_YELLOW, ST7735_BLACK);
	tft.setTextSize(1);
//	tft.setFont(&FreeSans24pt7b);
	tft.setFont(&FreeSans24pt7b_sel);
while(1){
	tft.setCursor(20, 40);
	tft.print(F("00,00"));
#ifndef DEBUG
	_delay_ms(300);
#endif
	tft.setCursor(20, 40);
	tft.print(F("00,00"));
	#ifndef DEBUG
	_delay_ms(300);
	#endif
	tft.setCursor(20, 40);
	tft.print(F("11,11"));
	#ifndef DEBUG
	_delay_ms(300);
	#endif
	tft.setCursor(20, 40);
	tft.print(F("22,22"));
	#ifndef DEBUG
	_delay_ms(300);
	#endif
	tft.setCursor(20, 40);
	tft.print(F("33,33"));
	#ifndef DEBUG
	_delay_ms(300);
	#endif
	tft.setCursor(20, 40);
	tft.print(F("44,44"));
	#ifndef DEBUG
	_delay_ms(300);
	#endif
	tft.setCursor(20, 40);
	tft.print(F("55,55"));
	#ifndef DEBUG
	_delay_ms(300);
	#endif
	tft.setCursor(20, 40);
	tft.print(F("66,66"));
	#ifndef DEBUG
	_delay_ms(300);
	#endif
	tft.setCursor(20, 40);
	tft.print(F("77,77"));
	#ifndef DEBUG
	_delay_ms(300);
	#endif
	tft.setCursor(20, 40);
	tft.print(F("88,88"));
	#ifndef DEBUG
	_delay_ms(300);
	#endif
	tft.setCursor(20, 40);
	tft.print(F("99,99"));
	#ifndef DEBUG
	_delay_ms(300);
	#endif
	tft.setCursor(20, 40);
	tft.print(F("12,34"));
	#ifndef DEBUG
	_delay_ms(300);
	#endif
	tft.setCursor(20, 40);
	tft.print(F("56,78"));
	#ifndef DEBUG
	_delay_ms(300);
	#endif
	tft.setCursor(20, 40);
	tft.print(F("90,12"));
	#ifndef DEBUG
	_delay_ms(3000);
	#endif
}
	return 0;
}


void testPixels()
{
	int32_t	w = tft.width();
	int32_t	h = tft.height();

	for (uint16_t y = 0; y < h; y++)
	{
		for (uint16_t x = 0; x < w; x++)
		{
			tft.drawPixel(x, y, tft.color565(x<<3, y<<3, x*y));
		}
	}
}

void testLines(uint16_t color)
{
	int32_t	x1, y1, x2, y2;
	int32_t	w = tft.width();
	int32_t	h = tft.height();

	tft.fillScreen(ST7735_BLACK);

	x1 = y1 = 0;
	y2 = h - 1;

	for (x2 = 0; x2 < w; x2 += 6)
	{
		tft.drawLine(x1, y1, x2, y2, color);
	}

	x2 = w - 1;

	for (y2 = 0; y2 < h; y2 += 6)
	{
		tft.drawLine(x1, y1, x2, y2, color);
	}

	tft.fillScreen(ST7735_BLACK);

	x1 = w - 1;
	y1 = 0;
	y2 = h - 1;

	for (x2 = 0; x2 < w; x2 += 6)
	{
		tft.drawLine(x1, y1, x2, y2, color);
	}

	x2 = 0;
	for (y2 = 0; y2 < h; y2 += 6)
	{
		tft.drawLine(x1, y1, x2, y2, color);
	}

	tft.fillScreen(ST7735_BLACK);

	x1 = 0;
	y1 = h - 1;
	y2 = 0;

	for (x2 = 0; x2 < w; x2 += 6)
	{
		tft.drawLine(x1, y1, x2, y2, color);
	}
	x2 = w - 1;
	for (y2 = 0; y2 < h; y2 += 6)
	{
		tft.drawLine(x1, y1, x2, y2, color);
	}

	tft.fillScreen(ST7735_BLACK);

	x1 = w - 1;
	y1 = h - 1;
	y2 = 0;

	for (x2 = 0; x2 < w; x2 += 6)
	{
		tft.drawLine(x1, y1, x2, y2, color);
	}

	x2 = 0;
	for (y2 = 0; y2 < h; y2 += 6)
	{
		tft.drawLine(x1, y1, x2, y2, color);
	}

}

void testFastLines(uint16_t color1, uint16_t color2)
{
	int32_t x, y;
	int32_t w = tft.width();
	int32_t h = tft.height();

	tft.fillScreen(ST7735_BLACK);

	for (y = 0; y < h; y += 5)
		tft.drawFastHLine(0, y, w, color1);
	for (x = 0; x < w; x += 5)
		tft.drawFastVLine(x, 0, h, color2);
}

void testRects(uint16_t color)
{
	int32_t n, i, i2;
	int32_t cx = tft.width() / 2;
	int32_t cy = tft.height() / 2;

	tft.fillScreen(ST7735_BLACK);
	n = min(tft.width(), tft.height());
	for (i = 2; i < n; i += 6)
	{
		i2 = i / 2;
		tft.drawRect(cx-i2, cy-i2, i, i, color);
	}
}

void testFilledRects(uint16_t color1, uint16_t color2)
{
	int32_t n, i, i2;
	int32_t cx = tft.width() / 2 - 1;
	int32_t cy = tft.height() / 2 - 1;

	tft.fillScreen(ST7735_BLACK);
	n = min(tft.width(), tft.height());
	for (i = n; i > 0; i -= 6)
	{
		i2 = i / 2;

		tft.fillRect(cx-i2, cy-i2, i, i, color1);

		// Outlines are not included in timing results
		tft.drawRect(cx-i2, cy-i2, i, i, color2);
	}
}

void testFilledCircles(uint8_t radius, uint16_t color)
{
	int32_t x, y, w = tft.width(), h = tft.height(), r2 = radius * 2;

	tft.fillScreen(ST7735_BLACK);

	for (x = radius; x < w; x += r2)
	{
		for (y = radius; y < h; y += r2)
		{
			tft.fillCircle(x, y, radius, color);
		}
	}
}

void testCircles(uint8_t radius, uint16_t color)
{
	int32_t x, y, r2 = radius * 2;
	int32_t w = tft.width() + radius;
	int32_t h = tft.height() + radius;

	for (x = 0; x < w; x += r2)
	{
		for (y = 0; y < h; y += r2)
		{
			tft.drawCircle(x, y, radius, color);
		}
	}
}

void testTriangles()
{
	int32_t n, i;
	int32_t cx = tft.width()/ 2 - 1;
	int32_t cy = tft.height() / 2 - 1;

	tft.fillScreen(ST7735_BLACK);
	n = min(cx, cy);

	for (i = 0; i < n; i += 5)
	{
		tft.drawTriangle(
			cx		, cy - i, // peak
			cx - i, cy + i, // bottom left
			cx + i, cy + i, // bottom right
			tft.color565(0, 0, i));
	}
}

void testFilledTriangles()
{
	int32_t i;
	int32_t cx = tft.width() / 2 - 1;
	int32_t cy = tft.height() / 2 - 1;

	tft.fillScreen(ST7735_BLACK);

	for (i = min(cx,cy); i > 10; i -= 5) {
		tft.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
			tft.color565(0, i, i));
		tft.drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
			tft.color565(i, i, 0));
	}
}

void testRoundRects()
 {
	int32_t w, i, i2;
	int32_t cx = tft.width() / 2 - 1;
	int32_t cy = tft.height() / 2 - 1;

	tft.fillScreen(ST7735_BLACK);

	w = min(tft.width(), tft.height());

	for (i = 0; i < w; i += 6)
	{
		i2 = i / 2;
		tft.drawRoundRect(cx-i2, cy-i2, i, i, i/8, tft.color565(i, 0, 0));
	}
}

void testFilledRoundRects()
{
	int32_t i, i2;
	int32_t cx = tft.width() / 2 - 1;
	int32_t cy = tft.height() / 2 - 1;

	tft.fillScreen(ST7735_BLACK);

	for (i = min(tft.width(), tft.height()); i > 20; i -= 6)
	{
		i2 = i / 2;
		tft.fillRoundRect(cx-i2, cy-i2, i, i, i/8, tft.color565(0, i, 0));
	}
}




