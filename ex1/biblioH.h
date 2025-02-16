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
LivreH* creer_livreH(int num, char* titre, char* auteur);
void liberer_livreH(LivreH* l);
BiblioH* creer_biblioH(int m);
void liberer_biblioH(BiblioH* b);
int fonctionHachage(int cle, int m);
void insererH(BiblioH* b,int num,char* titre,char* auteur);
void afficher_livreH(LivreH *l);
void afficher_biblioH(BiblioH *b);
LivreH* cherche_numH(BiblioH* b, int num);
LivreH* cherche_titreH(BiblioH* b,char* titre);
BiblioH* cherche_auteurH(BiblioH* b,char* auteur);
void suppression_livreH(BiblioH* b,int num,char* titre,char* auteur);
BiblioH* fusion_biblioH(BiblioH* b1, BiblioH* b2);
BiblioH* doublon_biblioH(BiblioH *b);


#endif

