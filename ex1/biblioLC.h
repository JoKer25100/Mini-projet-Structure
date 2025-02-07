#ifndef _BIBLIOLC_H_
#define _BIBLIOLC_H_


typedef struct livre {
    int num ;
    char * titre ;
    char * auteur ;
    struct livre * suiv ;
} Livre ;

typedef struct { /* Tete fictive */
    Livre * L ; /* Premier element */
} Biblio ;


Livre* creer_livre(int num,char* titre,char* auteur);
void liberer_livre(Livre* l);
Biblio* creer_biblio();
void liberer_biblio(Biblio* b);
void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur);
void afficher_livre(Livre *l);
void afficher_biblio(Biblio *b);
Livre* cherche_num(Biblio* b,int num);
Livre* cherche_titre(Biblio* b,char* titre);
Biblio* cherche_auteur(Biblio* b,char* auteur);
void suppression_livre(Biblio* b,int num,char* titre,char* auteur);
Biblio* fusion_biblio(Biblio* b1, Biblio* b2);
Biblio* doublon_biblio(Biblio *b);

#endif