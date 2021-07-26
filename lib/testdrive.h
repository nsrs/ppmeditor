#ifndef __TESTDRIVE_H__
#define __TESTDRIVE_H__

#include "image.h"


/**
 *  Pinta todos os p�xeis de uma imagem a preto.
 */
void test_paintblack(image *img);


/**
 *  Pinta a metade direita da imagem de forma a
 *  espelhar a metade esquerda.
 */
void test_mirroreffect(image *img);


/**
 *  Troca as posi��es dos p�xeis da imagem
 *  de forma a distorcer a imagem.
 */
void test_twist(image *img);


/**
 *  Testa uma tentativa de aceder a um p�xel que n�o existe
 *  na imagem.
 */
void test_wrongpixelaccess(image *img);


/**
 *  Testa uma tentativa de colorir um p�xel com uma cor
 *  cujo valor � superior ao m�ximo permitido na imagem.
 */
void test_wrongcolor(image *img);


#endif
