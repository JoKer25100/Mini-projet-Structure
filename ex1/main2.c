#include <stdio.h>
#include <stdlib.h>
#include "biblioH.h"

int main(int argc, char** argv){

    if (argc < 2) {
        printf("Usage: %s <number_of_entries>\n", argv[0]);
        return 1;
    }
    
    printf("%d\n",fonctionClef(argv[1]));
    printf("%d\n",fonctionHachage(atoi(argv[1]), 10));

    return 0;
}