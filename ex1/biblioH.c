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

LivreH* creer_livreH(int num,char* titre,char* auteur){
    LivreH* L = (LivreH*)malloc(sizeof(LivreH));
    L->clef = fonctionClef(auteur);
    L->num = num;
    L->titre = strdup(titre);
    L->auteur = strdup(auteur);
    L->suivant = NULL;
    return L;
}

void liberer_livreH(LivreH* l) {
    LivreH* tmp;
    if (l != NULL) {
        tmp = l;
        l = l->suivant;
        free(tmp->auteur);
        free(tmp->titre);
        free(tmp);
    }
}

BiblioH* creer_biblioH(int m){
    BiblioH* b = (BiblioH*)malloc(sizeof(BiblioH));
    b->nE = 0;
    b->m = m;
    b->T = (LivreH**)malloc(m*sizeof(LivreH*));
    for (int i = 0; i < m; i++){
        b->T[i] = NULL;
    }
    return b;
}

void liberer_biblioH(BiblioH* b){
    for (int i = 0; i < b->m; i++){
        LivreH* tmp = b->T[i];
        while (tmp != NULL) {
            LivreH* suppr = tmp;
            tmp = tmp->suivant;
            liberer_livreH(suppr);
        }
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

void insererH(BiblioH* b, int num, char* titre, char* auteur) {
    int fctH = fonctionHachage(fonctionClef(auteur), b->m);
    if (fctH >= b->m) {
        printf("Erreur dans les calculs");
        return;
    }
    LivreH* l = creer_livreH(num, titre, auteur);
    l->suivant = b->T[fctH];
    b->T[fctH] = l;
    b->nE++;
}

void afficher_livreH(LivreH *l){
    printf("%d %s %s\n",l->num,l->titre,l->auteur);
}

void afficher_biblioH(BiblioH *b) {
    LivreH* tmp;
    for (int i = 0; i < b->m; i++){
        tmp = b->T[i];
        while(tmp){
            afficher_livreH(tmp);
            tmp = tmp->suivant;
        }
    }
}

LivreH* cherche_numH(BiblioH* b, int num) {
    LivreH* tmp;
    for (int i = 0; i < b->m; i++){
        tmp = b->T[i];
        while(tmp){
            if (tmp->num == num){
                return tmp;
            }
            tmp = tmp->suivant;
        }
    }
    return NULL;
}

LivreH* cherche_titreH(BiblioH* b,char* titre){
    LivreH* tmp;
    for (int i = 0; i < b->m; i++){
        tmp = b->T[i];
        while(tmp){
            if (strcmp(tmp->titre,titre)==0){
                return tmp;
            }
            tmp = tmp->suivant;
        }
    }
    return NULL;
}

BiblioH* cherche_auteurH(BiblioH* b,char* auteur){
    BiblioH* res = creer_biblioH(b->m);
    LivreH* tmp = b->T[fonctionHachage(fonctionClef(auteur),b->m)];
    while(tmp!=NULL){
        if (strcmp(tmp->auteur,auteur)==0) insererH(res,tmp->num,tmp->titre,tmp->auteur);
        tmp = tmp->suivant;
    }
    return res;
}

void suppression_livreH(BiblioH* b, int num, char* titre, char* auteur) {
    int i = fonctionHachage(fonctionClef(auteur), b->m);
    LivreH *tmp = b->T[i];
    LivreH *prev = NULL;

    while (tmp != NULL) {
        if ((strcmp(tmp->auteur, auteur) == 0) && (strcmp(tmp->titre, titre) == 0) && (tmp->num == num)) {
            if (prev == NULL) {
                b->T[i] = tmp->suivant;
            } else {
                prev->suivant = tmp->suivant;
            }
            liberer_livreH(tmp);
            printf("Livre supprimé\n");
            return;
        }
        prev = tmp;
        tmp = tmp->suivant;
    }
    printf("Livre non trouvé\n");
}

BiblioH* fusion_biblioH(BiblioH* b1, BiblioH* b2){
    if (b1 == NULL) return b2;
    if (b2 == NULL) return b1;

    if (b1->nE == 0) {
        liberer_biblioH(b1);
        return b2;
    }
    if (b2->nE == 0) {
        liberer_biblioH(b2);
        return b1;
    }

    LivreH* tmp;
    for (int i = 0; i < b2->m; i++){
        tmp = b2->T[i];
        while(tmp){
            insererH(b1,tmp->num,tmp->titre,tmp->auteur);
            tmp = tmp->suivant;
        }
    }
    liberer_biblioH(b2);
    return b1;
}
BiblioH* doublon_biblioH(BiblioH *b) {
    BiblioH* res = creer_biblioH(b->m);
    LivreH* tmp;
    LivreH* tmp2;
    BiblioH* b1;
    for (int i = 0; i < b->m; i++) {
        tmp = b->T[i];
        while (tmp) {
            b1 = cherche_auteurH(b, tmp->auteur);
            tmp2 = b1->T[fonctionHachage(fonctionClef(tmp->auteur), b1->m)];
            while (tmp2) {
                if ((strcmp(tmp->titre, tmp2->titre) == 0) && (tmp->num != tmp2->num)) {
                    // Insérer le premier livre en double
                    LivreH* l = cherche_numH(res, tmp->num);
                    if (l == NULL) {
                        insererH(res, tmp->num, tmp->titre, tmp->auteur);
                    }
                    // Insérer le deuxième livre en double
                    l = cherche_numH(res, tmp2->num);
                    if (l == NULL) {
                        insererH(res, tmp2->num, tmp2->titre, tmp2->auteur);
                    }
                }
                tmp2 = tmp2->suivant;
            }
            liberer_biblioH(b1);
            tmp = tmp->suivant;
        }
    }
    return res;
}