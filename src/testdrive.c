#include "../lib/testdrive.h"


void test_paintblack(image *img) {
    int height = img->height;
    int width = img->width;

    int i, j;
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            edit_pixel(img, i, j, 0, 0, 0);
        }
    }
}


void test_mirroreffect(image *img) {
    int height = img->height;
    int width = img->width;
    int mirrorcolumn; //Coluna onde se encontra o p�xel-espelho

    int i, j;
    for(i=0; i<height; i++) {
        for(j=0; j<(width/2); j++) {
            mirrorcolumn = width-j-1;
            copy_pixel(img, i, j, i, mirrorcolumn);
        }
    }
}


void test_twist(image *img) {
    int height = img->height;
    int width = img->width;
	
	//Indica se a troca do p�xel � com o p�xel acima ou abaixo (alternando)
	// (1 se for com o de cima, 0 se for com o de baixo)
	int switch_top = 0;
	
	//Indica se a troca � com o p�xel � esquerda ou � direita (alternando)
	// (1 se for com o da esquerda, 0 se for com o da direita)
	int switch_left = 0;

    int i, j;
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
			//S� troca com o de cima se existir um p�xel acima
			if (i>0 && switch_top == 1) {
				swap_pixels(img, i, j, i-1, j);
				switch_top = 0;
			}
			//S� troca com o de baixo se existir um p�xel abaixo
			else if (i<height-1 && switch_top == 0) {
				swap_pixels(img, i, j, i+1, j);
				switch_top = 1;
			}
			
            //S� troca com o da esquerda se existir um p�xel � esquerda
			if (j>0 && switch_left == 1) {
				swap_pixels(img, i, j, i, j-1);
				switch_left = 0;
			}
			//S� troca com o de baixo se existir um p�xel abaixo
			else if (j<width-1 && switch_left == 0) {
				swap_pixels(img, i, j, i, j+1);
				switch_left = 1;
			}
        }
    }
}


void test_wrongpixelaccess(image *img) {
    get_pixel(img, 0, -1);
}


void test_wrongcolor(image *img) {
    edit_pixel(img, 0, 0, 0, 0, (img->color_range_max)+1);
}

