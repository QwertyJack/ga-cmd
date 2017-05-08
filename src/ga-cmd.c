#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "cfgfile.h"
/*#include "keyhide.h"*/
/*#include "verf.h"*/
/*#include "codegen.h"*/
#include "../google-authenticator/libpam/google_authenticator_gen.h"

/*-----------------------------------------------------------------*/
int main(int argc, char *const argv[]) {
    /*if (argc != 2) {*/
        /*fprintf(stderr, "usage: ga-cmd keyfile\n");*/
        /*return 1;*/
    /*}*/
    char *key;
    int keyLen;
    if (!(keyLen = load_key(argv[1], &key))) {
        return 1;
    }

    int verf_code = generateCode(key, time(0) / 30);
    fprintf(stdout, "%06d\n", verf_code);

    return EXIT_SUCCESS;
}
