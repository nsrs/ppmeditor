#include "../lib/iomanager.h"
#include "../lib/testdrive.h"
#include <stdio.h>


void runtests(image *img) {
    //test_wrongcolor(img);
    //test_wrongpixelaccess(img);
    test_mirroreffect(img);
    output_file(img, "mirrored.ppm");

    test_twist(img);
    output_file(img, "twisted.ppm");

    test_paintblack(img);

}


int main(int argn, char **argv) {
    image *img;
    if (argn > 3) {
        printf("\nERRO: demasiados argumentos\n");
        return -1;
    }

    if (argn < 2) {
        img = input_stdin();
    }
    else {
        img = input_file(argv[1]);
    }
    if (img == NULL) {
        return -1;
    }

    runtests(img);

    if (argn < 3) {
        output_stdin(img);
        delete_image(img);
        return 0;
    }
    else {
        int opstate = output_file(img, argv[2]);
        delete_image(img);
        return opstate;
    }
}
