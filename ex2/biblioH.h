#ifndef _BIBLIOLC_H_
#define _BIBLIOLC_H_

typedef struct livreh{
    int clef;
    struct livreh*  suivant;
} LivreH;

typedef struct table{
    int nE;
    int m;
    LivreH** T;
}BiblioH;

int fonctionClef(char* auteur);

#endif