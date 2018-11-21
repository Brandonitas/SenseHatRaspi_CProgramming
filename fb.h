#ifndef _SENSE_FB_H
#define _SENSE_FB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
* Bitmap (memory or framebuffer) 
*/
typedef struct sense_bitmap *sense_bitmap_t;
/**
Colores representados en RBG 565 (16 bit)
*/
typedef uint16_t sense_color_t;

/**
Asignar al framebuffer el dispositivo
*/
sense_bitmap_t sense_alloc_fb();

/**
Asignar a memoria el bitmap
*/
sense_bitmap_t sense_alloc_bitmap();
/**
* Copiar bitmap a otro bitmap. 
*/
void sense_copy_bitmap(sense_bitmap_t target,const sense_bitmap_t source);
/**
* Libre bitmap
*/
void sense_free_bitmap(sense_bitmap_t bitmap);

/**
Get the internal buffer of a bitmap for direct manipulation.
*/
uint16_t* sense_bitmap_get_buffer(sense_bitmap_t bitmap);

/**
* Copiar bitmap.
*/
void sense_bitmap_cpy(sense_bitmap_t dst,const sense_bitmap_t src);
/**
* Color punto flotante RBG
*/
sense_color_t sense_make_color_rgbf(double r,double g,double b);
/**
* Color RBG
*/
sense_color_t sense_make_color_rgb(uint8_t r,uint8_t g,uint8_t b);
/**
* Color RBG 565
*/
sense_color_t sense_make_color_rgb565(uint8_t r,uint8_t g,uint8_t b);

/**
* Last error in sense library.
*/
int sense_errno();

/**
* Error code
*/
const char* sense_strerror(int err);

/**
* Asignar pixeles al bitmap
*/
int sense_bitmap_set_pixel(sense_bitmap_t bitmap,uint8_t x,uint8_t y,sense_color_t color);

/**
* Pintamos el bitmap
*/
void sense_bitmap_paint(sense_bitmap_t bitmap,sense_color_t color);


/**
* Bitmap pixel width
*/
#define SENSE_BITMAP_WIDTH 8
/**
* Bitmap pixel height
*/
#define SENSE_BITMAP_HEIGHT 8
/**
* Number of pixels in the bitmap
*/
#define SENSE_PIXELS (SENSE_BITMAP_WIDTH * SENSE_BITMAP_HEIGHT)
/**
* Buffer size in bytes for the bitmap
*/
#define SENSE_BUFFER_SIZE (SENSE_PIXELS * sizeof(uint16_t))

#ifdef __cplusplus
}
#endif



#endif