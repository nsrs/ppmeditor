#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "pixel.h"
#include <stdio.h>


/**
 *  Representa uma imagem com extensão .ppm, que é uma matriz
 *  de píxeis RGB.
 *
 *   height <- número de linhas da matriz que define a imagem
 *   width  <- número de colunas ..
 *   matrix <- matriz de píxeis que corresponde à imagem,
 *             onde o tipo 'pixel' está definido em "pixel.h"
 *
 */
typedef struct _image{
    int height;
    int width;
    int color_range_max;
    pixel **matrix; // equivalente a matrix[][]
} image;


/**
 *  Cria e retorna uma imagem, representada por uma matriz de píxeis RGB,
 *  dados o número de linhas e de colunas desta mesma matriz.
 *  O alcance máximo da cor RGB deve ser dado como terceiro argumento.
 */
image* create_image(int rows, int cols, int color_max);


/**
 *  Apaga uma imagem, de forma a libertar o espaço em memória que esta ocupa.
 */
void delete_image(image *img);


/**
 *  Lê uma imagem do canal de input (seja do stdin ou de um ficheiro .ppm),
 *  e cria uma nova imagem.
 *  Erros no input deverão ser detetados nesta função.
 */
image* read_image(FILE *stream);


/**
 *  Imprime uma imagem conforme as especificações do formato .ppm
 */
void print_image(FILE *stream, image *img);


/**
 *  Retorna o píxel de uma imagem na posição (x,y).
 *  Se falhar, apaga a imagem e termina o programa.
 */
pixel* get_pixel(image *img, int x, int y);


/**
 *  Altera as cores de um píxel na posição (x,y) da imagem.
 *  Se falhar, apaga a imagem e termina o programa.
 */
 void edit_pixel(image *img, int x, int y, int red, int green, int blue);


/**
 *  Copia as cores de um píxel na posição (x1,y1) da imagem
 *  para um píxel em (x2, y2).
 *  Se falhar, apaga a imagem e termina o programa.
 */
 void copy_pixel(image *img, int x1, int y1, int x2, int y2);


/**
 *  Troca as cores de dois píxeis.
 *  O primeiro píxel vai passar a ter as cores do segundo, e vice-versa.
 *  Se falhar, apaga a imagem e termina o programa.
 */
void swap_pixels(image *img, int x1, int y1, int x2, int y2);


#endif
