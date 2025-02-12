#include "entreeSortieH.h"
#include "biblioH.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

BiblioH* charger_n_entrees(char* nomfic, int n, int m){
    /*Charger n livres dans une biblio avec une table de hachage de taille m*/
    FILE *f = fopen(nomfic, "r");
    if (f == NULL) {
        printf("Erreur ouverture fichier\n");
        return NULL;
    }
    int num;
    char titre[256];
    char auteur[256];
    BiblioH* b = creer_biblio(m);
    for (int i = 0; i < n; i++) {
        if (fscanf(f, "%d %255s %255s\n", &num, titre, auteur) == 3) {
            inserer(b, num, titre, auteur);
        } else {
            printf("Erreur sur le %dème livre\n", i + 1);
            break;
        }
    }
    fclose(f);
    return b;
}


void enregistrer_biblio(BiblioH *b, char* nomfic){
    FILE *f=fopen(nomfic,"w");
    if (f==NULL){
        printf("erreur ouverture ficher\n");
        return ;
    }

    LivreH* tmp;
    for (int i = 0; i < b->m; i++){
        tmp = b->T[i];
        while(tmp){
            fprintf(f,"%d %s %s\n",tmp->num, tmp->titre, tmp->auteur);
            tmp = tmp->suivant;
        }
    }
    fclose(f);
}