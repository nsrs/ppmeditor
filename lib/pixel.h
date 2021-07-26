#ifndef __PIXEL_H__
#define __PIXEL_H__


/**
 *  Representa uma píxel RGB, composto por três inteiros.
 *  A "quantidade" de cada cor num píxel é guardada em cada
 *  um destes inteiros, e encontra-se entre 0 e 255.
 *
 *   red   <- quantidade de cor vermelha no píxel
 *   green <- .. de cor verde ..
 *   blue  <- .. de cor azul ..
 */
typedef struct _pixel{
    int red;
    int green;
    int blue;
} pixel;


/**
 *  Altera as cores de um píxel.
 *  O píxel deve ser passado como argumento em primeiro lugar,
 *  seguido das três cores RGB.
 */
void p_editpixel(pixel *pix, int r, int g, int b);


/**
 *  Copia as cores de um píxel para outro píxel.
 *  O primeiro pârametro é o píxel cujas cores se pretende copiar.
 *  O segundo pârametro é o píxel cujas cores vão ser "substituídas".
 */
void p_copypixel(pixel *copiedpixel, pixel *targetpixel);


/**
 *  Testa o valor de uma cor.
 *  Se estiver dentro dos limites estipulados, retorna 0.
 *  Caso contrário, retorna -1.
 */
int isvalidcolor(int colorvalue, int color_max);


/**
 *  Representa uma píxel RGB "económico" em termos de memória.
 *
 *  Em comparação ao tipo 'int', que, nesta altura, ocupa pelo menos 4 bytes,
 *  ao passo que um 'char' ocupa apenas 1 byte.
 *  Como a "quantidade" de cada cor só se poderá encontrar entre 0 e 255,
 *  1 byte é suficiente para guardar cada uma das cores.
 *
 *   red   <- quantidade de cor vermelha no píxel
 *   green <- .. de cor verde ..
 *   blue  <- .. de cor azul ..
 */
struct pixel_cheap {
    char red;
    char green;
    char blue;
};


#endif
