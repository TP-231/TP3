#include<stdio.h>
#include"image.h"
#include "NoirBlanc.h"

int main() {
    int taille;
    int choix;
    do {
        menu();
        printf("\nChoix: ");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            creer_image();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            printf("===CONVERSION EN NOIR SUR BLANC===\n");
            NoirBlanc();
            printf("Vous avez cree en noir sur blanc en format ppm!\n");
            break;
        case 5:

            break;
        case 6:
            taille=4*4;
            printf("=== TAILLE DE L'IMAGE ===\n");
            printf("TAILLE: %d pixels\n",taille);
            break;
        case 7:
            
            break;
        case 8:

            break;
        case 9:
        	return 0;
        default:
            printf("Choix non disponible!\n");
            break;
        }
    }
    while(choix!=0);
    return 0;
}