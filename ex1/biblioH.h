#ifndef _BIBLIOH_H_
#define _BIBLIOH_H_

typedef struct livreh{
    int clef;
    int num;
    char* titre;
    char* auteur;
    struct livreh* suivant;
} LivreH;

typedef struct table{
    int nE;
    int m;
    LivreH** T;
} BiblioH;

int fonctionClef(char* auteur);
LivreH* creer_livre(int num, char* titre, char* auteur);
void liberer_livre(LivreH* l);
BiblioH* creer_biblio(int m);
void liberer_biblio(BiblioH* b);
int fonctionHachage(int cle, int m);

#endif