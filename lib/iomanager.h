#ifndef __IOMANAGER_H__
#define __IOMANAGER_H__

#include "image.h"


/**
 *  Obtem do standard input uma imagem .ppm e devolve
 *  uma imagem pronta ser manipulada.
 */
image* input_stdin();


/**
 *  Obtem uma imagem .ppm de um ficheiro e devolve
 *  uma imagem pronta ser manipulada.
 */
image* input_file(char *filename);


/**
 * Imprime o conteúdo da imagem passada como argumento
 * em formato .ppm para o standard input.
 */
void output_stdin(image *img);


/**
 * Imprime o conteúdo da imagem passada como argumento
 * em formato .ppm para o ficheiro dado.
 * Retorna um inteiro, utilizado para o retorno final na função 'main'.
 */
int output_file(image *img, char *filename);


#endif
