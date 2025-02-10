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

LivreH* creer_livre(int num,char* titre,char* auteur){
    LivreH* L = (LivreH*)malloc(sizeof(LivreH));
    L->clef = fonctionClef(auteur);
    L->suivant = NULL;
    return L;
}

void liberer_livre(LivreH* l){
    LivreH* tmp;
    if (l != NULL) {
        tmp = l;
        l = l->suivant;
        free(tmp);
    }
    free(l);
}

BiblioH* creer_biblio(int m){
    BiblioH* b = (BiblioH*)malloc(sizeof(BiblioH));
    b->nE = 0;
    b->m = m;
    b->T = (LivreH**)malloc(m*sizeof(LivreH*));
    for (int i = 0; i < m; i++){
        b->T[i] = NULL;
    }
    return b;
}
void liberer_biblio(BiblioH* b){
    for (int i = 0; i < b->m; i++){
        liberer_livre(b->T[i]);
    }
    free(b->T);
    free(b);
}