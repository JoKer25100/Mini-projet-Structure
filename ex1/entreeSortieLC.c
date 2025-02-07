#include "entreeSortieLC.h"
#include "biblioLC.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


Biblio* charger_n_entrees(char* nomfic, int n) {
    FILE *f = fopen(nomfic, "r");
    if (f == NULL) {
        printf("Erreur ouverture fichier\n");
        return NULL;
    }
    int num;
    char titre[256];
    char auteur[256];
    Biblio* b = creer_biblio();
    for (int i = 0; i < n; i++) {
        if (fscanf(f, "%d %255s %255s\n", &num, titre, auteur) == 3) {
            inserer_en_tete(b, num, titre, auteur);
        } else {
            printf("Erreur sur le %dème livre\n", i + 1);
            break;
        }
    }
    fclose(f);
    return b;
}

void enregistrer_biblio(Biblio *b, char* nomfic){
    FILE *f=fopen(nomfic,"w");
    if (f==NULL){
        printf("erreur ouverture ficher\n");
        return ;
    }
    Livre* tmp = b->L;
    while (tmp!=NULL){
        fprintf(f,"%d %s %s\n",tmp->num, tmp->titre, tmp->auteur);
        tmp=tmp->suiv;
    }
    fclose(f);
}