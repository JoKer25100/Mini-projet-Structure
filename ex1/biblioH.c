#include "biblioH.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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
    L->num = num;
    L->titre = strdup(titre);
    L->auteur = strdup(auteur);
    L->suivant = NULL;
    return L;
}

void liberer_livre(LivreH* l){
    LivreH* tmp;
    while (l != NULL) {
        tmp = l;
        l = l->suivant;
        free(tmp->auteur);
        free(tmp->titre);
        free(tmp);
    }
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

int fonctionHachage(int cle, int m){
    double A = (sqrt(5)-1)/2;
    int arr= (int)(cle*A);
    A = m*(cle*A-arr);
    int res = (int) A;
    return res;
}

void inserer(BiblioH* b,int num,char* titre,char* auteur){
    int fctH = fonctionHachage(fonctionClef(auteur),b->m);
    if (fctH>=b->m) {
        printf("Erreur dans les calculs");
        exit(1);
    }
    LivreH* l = creer_livre(num,titre,auteur);
    LivreH* tmp = b->T[fctH];
    if (tmp == NULL) tmp = l;
    else {
        l->suivant = tmp; 
        tmp = l;
    }
    b->nE++;
}