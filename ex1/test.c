#include <stdio.h>
#include <stdlib.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"

int main(int argc, char** argv){

    if (argc < 2) {
        printf("Usage: %s <number_of_entries>\n", argv[0]);
        return 1;
    }
    Biblio *b=charger_n_entrees("GdeBiblio.txt", atoi(argv[1]));
    afficher_biblio(b);
    
    Livre* l = cherche_num(b,4);
    if (l!=NULL) {
        afficher_livre(l);
    }
    enregistrer_biblio(b, "test.txt"); 
    liberer_biblio(b);
    return 0;
}