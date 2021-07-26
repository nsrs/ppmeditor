#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "pixel.h"
#include <stdio.h>


/**
 *  Representa uma imagem com extens�o .ppm, que � uma matriz
 *  de p�xeis RGB.
 *
 *   height <- n�mero de linhas da matriz que define a imagem
 *   width  <- n�mero de colunas ..
 *   matrix <- matriz de p�xeis que corresponde � imagem,
 *             onde o tipo 'pixel' est� definido em "pixel.h"
 *
 */
typedef struct _image{
    int height;
    int width;
    int color_range_max;
    pixel **matrix; // equivalente a matrix[][]
} image;


/**
 *  Cria e retorna uma imagem, representada por uma matriz de p�xeis RGB,
 *  dados o n�mero de linhas e de colunas desta mesma matriz.
 *  O alcance m�ximo da cor RGB deve ser dado como terceiro argumento.
 */
image* create_image(int rows, int cols, int color_max);


/**
 *  Apaga uma imagem, de forma a libertar o espa�o em mem�ria que esta ocupa.
 */
void delete_image(image *img);


/**
 *  L� uma imagem do canal de input (seja do stdin ou de um ficheiro .ppm),
 *  e cria uma nova imagem.
 *  Erros no input dever�o ser detetados nesta fun��o.
 */
image* read_image(FILE *stream);


/**
 *  Imprime uma imagem conforme as especifica��es do formato .ppm
 */
void print_image(FILE *stream, image *img);


/**
 *  Retorna o p�xel de uma imagem na posi��o (x,y).
 *  Se falhar, apaga a imagem e termina o programa.
 */
pixel* get_pixel(image *img, int x, int y);


/**
 *  Altera as cores de um p�xel na posi��o (x,y) da imagem.
 *  Se falhar, apaga a imagem e termina o programa.
 */
 void edit_pixel(image *img, int x, int y, int red, int green, int blue);


/**
 *  Copia as cores de um p�xel na posi��o (x1,y1) da imagem
 *  para um p�xel em (x2, y2).
 *  Se falhar, apaga a imagem e termina o programa.
 */
 void copy_pixel(image *img, int x1, int y1, int x2, int y2);


/**
 *  Troca as cores de dois p�xeis.
 *  O primeiro p�xel vai passar a ter as cores do segundo, e vice-versa.
 *  Se falhar, apaga a imagem e termina o programa.
 */
void swap_pixels(image *img, int x1, int y1, int x2, int y2);


#endif
