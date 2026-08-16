



#define __CLOCK_H 





void msleep(uint32_t);
uint32_t mtime(void);
void clock_setup(void);
#define __CONSOLE_H 
#define CONSOLE_UART USART1





void console_putc(char c);
char console_getc(int wait);
void console_puts(char *s);
int console_gets(char *s, int len);
void console_setup(int baudrate);


#define RESET_ON_CTRLC 
#define __SDRAM_H 

#define SDRAM_BASE_ADDRESS ((uint8_t *)(0xd0000000))


void sdram_init(void);
#define LCD_SPI_H 
void lcd_spi_init(void);
void lcd_show_frame(void);
void lcd_draw_pixel(int x, int y, uint16_t color);


#define LCD_BLACK 0x0000
#define LCD_BLUE 0x1F00
#define LCD_RED 0x00F8
#define LCD_GREEN 0xE007
#define LCD_CYAN 0xFF07
#define LCD_MAGENTA 0x1FF8
#define LCD_YELLOW 0xE0FF
#define LCD_WHITE 0xFFFF
#define LCD_GREY 0xc339





#define LCD_CS PC2
#define LCD_SCK PF7
#define LCD_DC PD13
#define LCD_MOSI PF9

#define LCD_SPI SPI5

#define LCD_WIDTH 240
#define LCD_HEIGHT 320

#define FRAME_SIZE (LCD_WIDTH * LCD_HEIGHT)
#define FRAME_SIZE_BYTES (FRAME_SIZE * 2)





#define _GFX_H 


#define swap(a,b) { int16_t t = a; a = b; b = t; }

void gfx_drawPixel(int x, int y, uint16_t color);
void gfx_drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
    uint16_t color);
void gfx_drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
void gfx_drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
void gfx_drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void gfx_fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void gfx_fillScreen(uint16_t color);

void gfx_drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void gfx_drawCircleHelper(int16_t x0, int16_t y0, int16_t r,
     uint8_t cornername, uint16_t color);
void gfx_fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void gfx_init(void (*draw)(int, int, uint16_t), int, int);

void gfx_fillCircleHelper(int16_t x0, int16_t y0, int16_t r,
     uint8_t cornername, int16_t delta, uint16_t color);
void gfx_drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
        int16_t x2, int16_t y2, uint16_t color);
void gfx_fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
        int16_t x2, int16_t y2, uint16_t color);
void gfx_drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
         int16_t radius, uint16_t color);
void gfx_fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
         int16_t radius, uint16_t color);
void gfx_drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
      int16_t w, int16_t h, uint16_t color);
void gfx_drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color,
    uint16_t bg, uint8_t size);
void gfx_setCursor(int16_t x, int16_t y);
void gfx_setTextColor(uint16_t c, uint16_t bg);
void gfx_setTextSize(uint8_t s);
void gfx_setTextWrap(uint8_t w);
void gfx_setRotation(uint8_t r);
void gfx_puts(char *);
void gfx_write(uint8_t);

uint16_t gfx_height(void);
uint16_t gfx_width(void);

uint8_t gfx_getRotation(void);

#define GFX_WIDTH 320
#define GFX_HEIGHT 240

struct gfx_state {
 int16_t _width, _height, cursor_x, cursor_y;
 uint16_t textcolor, textbgcolor;
 uint8_t textsize, rotation;
 uint8_t wrap;
 void (*drawpixel)(int, int, uint16_t);
};

extern struct gfx_state __gfx_state;

#define GFX_COLOR_WHITE 0xFFFF
#define GFX_COLOR_BLACK 0x0000
#define GFX_COLOR_GREY 0xF7DE
#define GFX_COLOR_BLUE 0x001F
#define GFX_COLOR_BLUE2 0x051F
#define GFX_COLOR_RED 0xF800
#define GFX_COLOR_MAGENTA 0xF81F
#define GFX_COLOR_GREEN 0x07E0
#define GFX_COLOR_CYAN 0x7FFF
#define GFX_COLOR_YELLOW 0xFFE0


#define d2r(d) ((d) * 6.2831853 / 360.0)





int main(void)
{
 int p1, p2, p3;

 clock_setup();
 console_setup(115200);
 sdram_init();
 lcd_spi_init();
 console_puts("LCD Initialized\n");
 console_puts("Should have a checker pattern, press any key to proceed\n");
 msleep(2000);

 gfx_init(lcd_draw_pixel, 240, 320);
 gfx_fillScreen(0xc339);
 gfx_fillRoundRect(10, 10, 220, 220, 5, 0xFFFF);
 gfx_drawRoundRect(10, 10, 220, 220, 5, 0x00F8);
 gfx_fillCircle(20, 250, 10, 0x00F8);
 gfx_fillCircle(120, 250, 10, 0xE007);
 gfx_fillCircle(220, 250, 10, 0x1F00);
 gfx_setTextSize(2);
 gfx_setCursor(15, 25);
 gfx_puts("STM32F4-DISCO");
 gfx_setTextSize(1);
 gfx_setCursor(15, 49);
 gfx_puts("Simple example to put some");
 gfx_setCursor(15, 60);
 gfx_puts("stuff on the LCD screen.");
 lcd_show_frame();
 console_puts("Now it has a bit of structured graphics.\n");
 console_puts("Press a key for some simple animation.\n");
 msleep(2000);

 gfx_setTextColor(0xE0FF, 0x0000);
 gfx_setTextSize(3);
 p1 = 0;
 p2 = 45;
 p3 = 90;
 while (1) {
  gfx_fillScreen(0x0000);
  gfx_setCursor(15, 36);
  gfx_puts("PLANETS!");
  gfx_fillCircle(120, 160, 40, 0xE0FF);
  gfx_drawCircle(120, 160, 55, 0xc339);
  gfx_drawCircle(120, 160, 75, 0xc339);
  gfx_drawCircle(120, 160, 100, 0xc339);

  gfx_fillCircle(120 + (sin(((p1) * 6.2831853 / 360.0)) * 55),
          160 + (cos(((p1) * 6.2831853 / 360.0)) * 55), 5, 0x00F8);
  gfx_fillCircle(120 + (sin(((p2) * 6.2831853 / 360.0)) * 75),
          160 + (cos(((p2) * 6.2831853 / 360.0)) * 75), 10, 0xFFFF);
  gfx_fillCircle(120 + (sin(((p3) * 6.2831853 / 360.0)) * 100),
          160 + (cos(((p3) * 6.2831853 / 360.0)) * 100), 8, 0x1F00);
  p1 = (p1 + 3) % 360;
  p2 = (p2 + 2) % 360;
  p3 = (p3 + 1) % 360;
  lcd_show_frame();
 }
}
