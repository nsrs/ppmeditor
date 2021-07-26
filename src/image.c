#include "../lib/image.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Funções privadas
int read_firstline(FILE *stream);
int read_pixels(FILE *stream, image *img, int rows, int cols);


image* create_image(int rows, int cols, int color_max) {
    image *img = (image*) malloc(sizeof(image));
    //Se a alocação de memória falhar, a operação é interrompida
    if (img == NULL) {
        return NULL;
    }
    img->height = rows;
    img->width = cols;
    img->color_range_max = color_max;
    img->matrix = (pixel**) malloc(rows*sizeof(pixel*));
    //Se a alocação de memória falhar, interrompe-se e reverte-se a operação
    if (img->matrix == NULL) {
        free(img);
        return NULL;
    }
    int i, j;
    for (i=0; i<rows; i++) {
        img->matrix[i] = (pixel*) malloc(cols*sizeof(pixel));
        //Se a alocação de memória falhar, interrompe-se e reverte-se tudo
        if (img->matrix[i] == NULL) {
            i--;
            while(i >= 0) {
                free(img->matrix[i]);
                i--;
            }
            free(img->matrix);
            free(img);
            return NULL;
        }

        //Os píxeis começam a branco por defeito
        for(j=0; j<cols; j++) {
            p_editpixel(&(img->matrix[i][j]), 255, 255, 255);
        }
    }
    return img;
}


void delete_image(image *img) {
    int i;
    for(i=0; i<img->width; i++) {
        free(img->matrix[i]);
    }
    free(img->matrix);
    free(img);
}


image* read_image(FILE *stream) {
    image* img;
    int rows, cols, color_max;
    if (read_firstline(stream) != 0) {
        return NULL;
    }

    if (fscanf(stream, "%d%d", &cols, &rows) != 2
    || rows < 1
    || cols < 1) {
        printf("\nERRO: dimensoes da imagem incorretas\n");
        return NULL;
    }

    if (fscanf(stream, "%d", &color_max) != 1) {
        printf("\nERRO: alcance maximo de cor invalido\n");
        return NULL;
    }

    img = create_image(rows, cols, color_max);
    if (img == NULL) {
        printf("\nERRO: falha ao alocar memoria para a imagem\n");
        printf("Tente novamente\n");
        return NULL;
    }
    if (read_pixels(stream, img, rows, cols) != 0) {
        delete_image(img);
        return NULL;
    }

    return img;
}


void print_image(FILE *stream, image *img) {
    int rows = img->height;
    int cols = img->width;
    fprintf(stream, "P3\n");
    fprintf(stream, "%d %d\n", cols, rows);
    fprintf(stream, "%d", img->color_range_max);
    int i, j;
    for (i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            //Imprime o '\n' exceto na última linha do output
            fprintf(stream, "\n");

            int red = img->matrix[i][j].red;
            int green = img->matrix[i][j].green;
            int blue = img->matrix[i][j].blue;
            fprintf(stream, "%d %d %d", red, green, blue);
        }
    }
}


pixel* get_pixel(image *img, int x, int y) {
    if (x < 0 || x > img->height
    || y < 0 || y > img->width) {
        printf("\nERRO: nao existe o pixel (%d,%d) na imagem\n", x, y);
        printf("A matriz da imagem tem ");
        printf("%d linhas e %d colunas\n", img->height, img->width);
        delete_image(img);
        exit(-1);
        return NULL;
    }
    return &(img->matrix[x][y]);
}


void edit_pixel(image *img, int x, int y, int red, int green, int blue) {
    pixel *pix = get_pixel(img, x, y);
    int color_max = img->color_range_max;

    if (isvalidcolor(red, color_max) != 0
    || isvalidcolor(green, color_max) != 0
    || isvalidcolor(blue, color_max) != 0) {
        printf("\nERRO: codigo RGB invalido atribuido ao pixel em:\n");
        printf("(%d, %d)\n", x, y);
        printf("Codigo RGB: (%d, %d, %d)\n", red, green, blue);
        delete_image(img);
        exit(-1);
    }

    p_editpixel(pix, red, green, blue);
}


void copy_pixel(image *img, int x1, int y1, int x2, int y2) {
    pixel *copiedpixel = get_pixel(img, x1, y1);
    pixel *targetpixel = get_pixel(img, x2, y2);

    p_copypixel(copiedpixel, targetpixel);
}


void swap_pixels(image *img, int x1, int y1, int x2, int y2) {
    pixel *pix1 = get_pixel(img, x1, y1);
    pixel *pix2 = get_pixel(img, x2, y2);
    int red, green, blue; //Cores do segundo píxel
    red = pix2->red;
    green = pix2->green;
    blue = pix2->blue;

    p_copypixel(pix1, pix2);
    p_editpixel(pix1, red, green, blue);
}


//###########################################
//###########################################
//             FUNÇÕES PRIVADAS


int read_firstline(FILE *stream) {
    char fileheader[3]; //primeiros dois carateres do input
    fscanf(stream, "%2s", fileheader);
    if (strcmp(fileheader, "P3") != 0) {
        printf("\nERRO: primeira linha de input incorreta\n");
        printf("Deveria ser: P3\n");
        printf("Foi encontrado: %s\n", fileheader);
        return -1;
    }
    return 0;
}


int read_pixels(FILE *stream, image *img, int rows, int cols) {
    int red, green, blue;
    int color_max = img->color_range_max;
    int i, j;

    for (i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            if (fscanf(stream, "%d%d%d", &red, &green, &blue) != 3) {
                printf("\nERRO: %d-esimo pixel nao foi lido\n", (i+1)*j);
                return -1;
            }
            if (isvalidcolor(red, color_max) != 0
            || isvalidcolor(green, color_max) != 0
            || isvalidcolor(blue, color_max) != 0) {
                printf("\nERRO: cor errada no %d-esimo pixel\n", (i+1)*j);
                printf("Alcance da cor: [%d,%d]\n", 0, color_max);
                return -1;
            }
            p_editpixel(&(img->matrix[i][j]), red, green, blue);
        }
    }
    return 0;
}


