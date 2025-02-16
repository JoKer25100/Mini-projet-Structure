#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "biblioH.h"
#include "entreeSortieH.h"

int main(int argc, char** argv){

    if (argc < 3) {
        printf("Usage: %s <number_of_entries> <size_of_table>\n", argv[0]);
        return 1;
    }
    
    BiblioH *b=charger_n_entreesH("GdeBiblio.txt", atoi(argv[1]),atoi(argv[2]));
    /*afficher_biblioH(b);*/
    void menu(){
        printf("Actions possibles:\n");
        printf("0-Sortir du programme\n");
        printf("1-Afficher la bibliothèque\n");
        printf("2-Inserer un livre\n");
        printf("3-Rechercher un livre par son numéro\n");
        printf("4-Rechercher un livre par son titre\n");
        printf("5-Rechercher de tous les livres d'un auteur\n");
        printf("6-Supprimer un livre\n");
        printf("7-Chercher les doublons\n");
    }
    
    int rep;
    int num;
    char titre[256];
    char auteur[256];
    char s[512];
    do{
        menu();
        if(fgets(s,512,stdin)!=NULL){
            if(sscanf(s,"%d",&rep)==1){
                switch (rep){
                case 1:
                    printf("Affichage de la bibliothèque\n");
                    afficher_biblioH(b);
                    break;
                case 2:
                    printf("Veuillez donner le numéro, le titre et l'autre \n");
                    if(fgets(s,512,stdin)!=NULL){
                        if(sscanf(s,"%d %255s %255s",&num,titre,auteur)==3){
                            insererH(b,num,titre,auteur);
                        }else{
                            printf("Erreur de saisie : format incorrect\n");
                        }
                    }else{
                        printf("Erreur de saisie\n");
                    }
                    break;
                case 3:
                    printf("Veuillez donner le numéro du livre\n");
                    if(fgets(s,512,stdin)!=NULL){
                        if(sscanf(s,"%d",&num)==1){
                            LivreH* l = cherche_numH(b,num);
                            if (l!=NULL) afficher_livreH(l);
                            else printf("Livre non trouvé\n");
                        }else{
                            printf("Erreur de saisie : format incorrect\n");
                        }
                    }else{
                        printf("Erreur de saisie\n");
                    }
                    break;
                case 4:
                    printf("Veuillez donner le titre du livre\n");
                    if(fgets(s,512,stdin)!=NULL){
                        if(sscanf(s,"%255s",titre)==1){
                            LivreH* l = cherche_titreH(b,titre);
                            if (l!=NULL) afficher_livreH(l);
                            else printf("Livre non trouvé\n");
                        }else{
                            printf("Erreur de saisie : format incorrect\n");
                        }
                    }else{
                        printf("Erreur de saisie\n");
                    }
                    break;
                case 5:
                    printf("Veuillez donner l'auteur du livre\n");
                    if(fgets(s,512,stdin)!=NULL){
                        if(sscanf(s,"%255s",auteur)==1){
                            BiblioH* b2 = cherche_auteurH(b,auteur);
                            if (b2!=NULL) {
                                afficher_biblioH(b2);
                                liberer_biblioH(b2);
                            } else printf("Livre non trouvé\n");
                        }else{
                            printf("Erreur de saisie : format incorrect\n");
                        }
                    }else{
                        printf("Erreur de saisie\n");
                    }
                    break;
                case 6:
                    printf("Veuillez donner le numéro, le titre et l'auteur du livre à supprimer\n");
                    if(fgets(s,512,stdin)!=NULL){
                        if(sscanf(s,"%d %255s %255s",&num,titre,auteur)==3){
                            suppression_livreH(b,num,titre,auteur);
                        }else{
                            printf("Erreur de saisie : format incorrect\n");
                        }
                    }else{
                        printf("Erreur de saisie\n");
                    }
                    break;
                case 7:
                    printf("Affichage des doublons de la bibliothèque\n");
                    BiblioH* b3 = doublon_biblioH(b);
                    if (b3!=NULL) {
                        afficher_biblioH(b3);
                        liberer_biblioH(b3);
                    } else printf("Pas de doublon\n");
                    break;
                }
            }else{
                printf("Erreur de saisie : format incorrect\n");
            }
        }else{
            printf("Erreur de saisie\n");
        }
    } while (rep!=0);
    printf("Fin du programme\n");
    
    enregistrer_biblioH(b, "test.txt"); 
    liberer_biblioH(b);
    return 0;
}