#ifndef __PIXEL_H__
#define __PIXEL_H__


/**
 *  Representa uma p�xel RGB, composto por tr�s inteiros.
 *  A "quantidade" de cada cor num p�xel � guardada em cada
 *  um destes inteiros, e encontra-se entre 0 e 255.
 *
 *   red   <- quantidade de cor vermelha no p�xel
 *   green <- .. de cor verde ..
 *   blue  <- .. de cor azul ..
 */
typedef struct _pixel{
    int red;
    int green;
    int blue;
} pixel;


/**
 *  Altera as cores de um p�xel.
 *  O p�xel deve ser passado como argumento em primeiro lugar,
 *  seguido das tr�s cores RGB.
 */
void p_editpixel(pixel *pix, int r, int g, int b);


/**
 *  Copia as cores de um p�xel para outro p�xel.
 *  O primeiro p�rametro � o p�xel cujas cores se pretende copiar.
 *  O segundo p�rametro � o p�xel cujas cores v�o ser "substitu�das".
 */
void p_copypixel(pixel *copiedpixel, pixel *targetpixel);


/**
 *  Testa o valor de uma cor.
 *  Se estiver dentro dos limites estipulados, retorna 0.
 *  Caso contr�rio, retorna -1.
 */
int isvalidcolor(int colorvalue, int color_max);


/**
 *  Representa uma p�xel RGB "econ�mico" em termos de mem�ria.
 *
 *  Em compara��o ao tipo 'int', que, nesta altura, ocupa pelo menos 4 bytes,
 *  ao passo que um 'char' ocupa apenas 1 byte.
 *  Como a "quantidade" de cada cor s� se poder� encontrar entre 0 e 255,
 *  1 byte � suficiente para guardar cada uma das cores.
 *
 *   red   <- quantidade de cor vermelha no p�xel
 *   green <- .. de cor verde ..
 *   blue  <- .. de cor azul ..
 */
struct pixel_cheap {
    char red;
    char green;
    char blue;
};


#endif
