#include "biblioLC.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Livre* creer_livre(int num,char* titre,char* auteur){
    Livre* res = malloc(sizeof(Livre));
    res->num=num;
    res->titre=strdup(titre);
    res->auteur = strdup(auteur);
    res->suiv = NULL;
    return res;

}

void liberer_livre(Livre* l) {
    if (l != NULL) {
        free(l->auteur);
        free(l->titre);
        l->suiv = NULL;
        free(l);
    }
}

Biblio* creer_biblio(){
    Biblio* res = malloc(sizeof(Biblio));
    res->L=NULL;
    return res;
}

void liberer_biblio(Biblio* b) {
    Livre *tmp;
    while (b->L != NULL) {
        tmp = b->L;
        b->L = b->L->suiv;
        liberer_livre(tmp);
    }
    free(b);
}

void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur){
    Livre *tmp=creer_livre(num,titre,auteur);
    tmp->suiv=b->L;
    b->L=tmp;
}

void afficher_livre(Livre *l){
    printf("%d %s %s\n",l->num,l->titre,l->auteur);
}

void afficher_biblio(Biblio *b) {
    Livre *tmp = b->L;
    while (tmp != NULL) {
        afficher_livre(tmp);
        tmp = tmp->suiv;
    }
}

Livre* cherche_num(Biblio* b, int num) {
    Livre *tmp = b->L;
    while (tmp != NULL) {
        if (tmp->num == num) {
            return tmp;
        }
        tmp = tmp->suiv;
    }
    return NULL;
}

Livre* cherche_titre(Biblio* b,char* titre){
    Livre *tmp = b->L;
    while(tmp!=NULL){
        if (strcmp(tmp->titre,titre)==0) return tmp;
        tmp = tmp->suiv;
    }
    return NULL;
}

Biblio* cherche_auteur(Biblio* b,char* auteur){
    Biblio* res = creer_biblio();
    Livre *tmp = b->L;
    while(tmp!=NULL){
        if (strcmp(tmp->auteur,auteur)==0) inserer_en_tete(res,tmp->num,tmp->titre,tmp->auteur);
        tmp = tmp->suiv;
    }
    return res;
}

void suppression_livre(Biblio* b,int num,char* titre,char* auteur){
    Livre *tmp = b->L;
    if ((strcmp(tmp->auteur,auteur)==0)&&(strcmp(tmp->titre,titre)==0)&&(tmp->num==num)){
        b->L = b->L->suiv;
        liberer_livre(tmp);
        printf("Livre supprimé\n");
        return;
        }

    while(tmp!=NULL){
        Livre* av = tmp;
        tmp = tmp->suiv;
        if ((strcmp(tmp->auteur,auteur)==0)&&(strcmp(tmp->titre,titre)==0)&&(tmp->num==num)){
            av->suiv=tmp->suiv;
            liberer_livre(tmp);
            printf("Livre supprimé\n");
            return;
        }
    }
    printf("Livre non trouvé\n");
    return;
}

Biblio* fusion_biblio(Biblio* b1, Biblio* b2){
    if (b1 == NULL) return b2;
    if (b2 == NULL) return b1;

    if (b1->L == NULL) {
        liberer_biblio(b1);
        return b2;
    }
    if (b2->L == NULL) {
        liberer_biblio(b2);
        return b1;
    }

    Livre* temp = b1->L;
    while (temp->suiv != NULL) {
        temp = temp->suiv;
    }

    temp->suiv = b2->L;
    free(b2);
    return b1;
}

Biblio* doublon_biblio(Biblio *b) {
    Biblio* res = creer_biblio();
    Livre* tmp = b->L;
    Livre* tmp2;
    while (tmp != NULL) {
        tmp2 = tmp->suiv;
        while (tmp2 != NULL) {
            if ((strcmp(tmp->auteur, tmp2->auteur) == 0) && (strcmp(tmp->titre, tmp2->titre) == 0)) {
                // Insérer le premier livre en double
                Livre* l = cherche_num(res, tmp->num);
                if (l == NULL) {
                    inserer_en_tete(res, tmp->num, tmp->titre, tmp->auteur);
                }
                // Insérer le deuxième livre en double
                l = cherche_num(res, tmp2->num);
                if (l == NULL) {
                    inserer_en_tete(res, tmp2->num, tmp2->titre, tmp2->auteur);
                }
            }
            tmp2 = tmp2->suiv;
        }
        tmp = tmp->suiv;
    }
    return res;
}