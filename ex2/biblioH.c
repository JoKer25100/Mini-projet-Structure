#include "biblioH.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int fonctionClef(char* auteur){
    int res =0;
    for (int i = 0; i<strlen(auteur); i++){
        res += auteur[i];
    }
    return res;
}