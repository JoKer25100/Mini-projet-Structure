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
void inserer(BiblioH* b,int num,char* titre,char* auteur);
void afficher_livre(LivreH *l);
void afficher_biblio(BiblioH *b);
LivreH* cherche_num(BiblioH* b, int num);
LivreH* cherche_titre(BiblioH* b,char* titre);
BiblioH* cherche_auteur(BiblioH* b,char* auteur);
void suppression_livre(BiblioH* b,int num,char* titre,char* auteur);
BiblioH* fusion_biblio(BiblioH* b1, BiblioH* b2);
BiblioH* doublon_biblio(BiblioH *b);


#endif

