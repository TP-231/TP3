#include<stdio.h>

int creer_image(){
    FILE*q=fopen("image.ppm","w");
    if(!q){
        perror("Impossible de creer une image");
        return 1;
    }
    int largeur,hauteur=4;
    int i,j;
    fprintf(q,"P3\n");
    fprintf(q,"4 4\n");
    fprintf(q,"255\n");

    fprintf(q," 255 0 87  255 0 87  255 0 87  255 0 87");
    fprintf(q," 255 254 0  255 254 0  255 254 0  255 254 0");
    fprintf(q," 255 0 254  255 0 254  255 0 254  255 0 254");
    fprintf(q," 0 255 0  0 255 0  0 255 0  0 255 0");
    
    fclose(q);
    printf("Vous avez creer une image!\n");
    return 0;
}
void menu() {
    printf("\n===== MENU =====\n");
    printf("1. Afficher l'image PPM\n");
    printf("2. Foncer les pixels a dominance RBG\n");
    printf("3. Eclairsir tous les pixels a dominance RBG\n");
    printf("4. Passer en noir et en blanc\n");
    printf("5. Creer le negatif d'une image\n");
    printf("6. Afficher la taille d'une image\n");
    printf("7. Decouper et garder une partie d'une image\n");
    printf("8. Appliquer a une image le filtre median\n");
}

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
        default:
            printf("Choix non disponible!\n");
            break;
        }
    }
    while(choix!=0);
    return 0;
}