#ifndef __TESTDRIVE_H__
#define __TESTDRIVE_H__

#include "image.h"


/**
 *  Pinta todos os píxeis de uma imagem a preto.
 */
void test_paintblack(image *img);


/**
 *  Pinta a metade direita da imagem de forma a
 *  espelhar a metade esquerda.
 */
void test_mirroreffect(image *img);


/**
 *  Troca as posições dos píxeis da imagem
 *  de forma a distorcer a imagem.
 */
void test_twist(image *img);


/**
 *  Testa uma tentativa de aceder a um píxel que não existe
 *  na imagem.
 */
void test_wrongpixelaccess(image *img);


/**
 *  Testa uma tentativa de colorir um píxel com uma cor
 *  cujo valor é superior ao máximo permitido na imagem.
 */
void test_wrongcolor(image *img);


#endif
