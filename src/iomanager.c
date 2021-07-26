#include "../lib/iomanager.h"
#include <stdio.h>

image* input_stdin() {
    return read_image(stdin);
}

image* input_file(char *filename) {
    FILE *file = fopen(filename, "r");
    image *img;
    if (file == NULL) {
        printf("\nERRO: falha ao abrir ficheiro de input\n");
        return NULL;
    }
    img = read_image(file);
    fclose(file);
    return img;
}


void output_stdin(image *img) {
    print_image(stdout, img);
}


int output_file(image *img, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("\nERRO: falha ao abrir ficheiro de output\n");
        return -1;
    }
    print_image(file, img);
    fclose(file);
    return 0;
}





