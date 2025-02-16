#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"
#include "biblioH.h"
#include "entreeSortieH.h"

int main(int argc, char** argv){

    if (argc < 2) {
        printf("Usage: %s <name_of_file>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "w");
    clock_t temps_initial ;
    clock_t temps_final ;
    double temps_liste ;
    double temps_hache ;
    for (int i = 1000; i <= 50000; i+=1000) {
        
        Biblio *b=charger_n_entrees("GdeBiblio.txt", i);
        BiblioH *bH=charger_n_entreesH("GdeBiblio.txt",i,i/100);

        temps_initial = clock();
        Biblio* b2 = doublon_biblio(b);
        temps_final = clock();
        temps_liste = (double)(temps_final - temps_initial) / CLOCKS_PER_SEC;
        liberer_biblio(b2);


        temps_initial = clock();
        BiblioH* b3 = doublon_biblioH(bH);
        temps_final = clock();
        temps_hache = (double)(temps_final - temps_initial) / CLOCKS_PER_SEC;
        liberer_biblioH(b3);

        fprintf(f, "%d %f %f\n", i, temps_liste, temps_hache);

        liberer_biblio(b);
        liberer_biblioH(bH);
    }
    return 0;
}