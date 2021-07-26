#include "../lib/pixel.h"
#include <stdlib.h>


void p_editpixel(pixel *pix, int r, int g, int b) {
    pix->red = r;
    pix->green = g;
    pix->blue = b;
}


void p_copypixel(pixel *copiedpixel, pixel *targetpixel) {
    targetpixel->red = copiedpixel->red;
    targetpixel->green = copiedpixel->green;
    targetpixel->blue = copiedpixel->blue;
}


int isvalidcolor(int colorvalue, int color_max) {
    if (colorvalue < 0 || colorvalue > color_max) {
        return -1;
    }
    return 0;
}
