
#ifndef IMAGE_H
#define IMAGE_H
#include <stdio.h>

typedef struct {
    int r, g, b; // rouge, vert, bleu
} Pixel;

typedef struct {
    int largeur;
    int hauteur;
    Pixel **pixels; // matrice dynamique de pixels
} Image;

// creation de l'image
int creer_image(){
    FILE*q=fopen("image.ppm","w");
    if(!q){
        perror("Impossible de creer une image");
        return 1;
    }
    fprintf(q,"P3\n");
    fprintf(q,"4 4\n");
    fprintf(q,"255\n");

    fprintf(q,"255 0 87  255 0 87  255 0 87  255 0 87\n");
    fprintf(q,"255 254 0  255 254 0  255 254 0  255 254 0\n");
    fprintf(q,"255 0 254  255 0 254  255 0 254  255 0 254\n");
    fprintf(q,"0 255 0  0 255 0  0 255 0  0 255 0\n");
    
    fclose(q);
    printf("Vous avez creer une image!\n");
    return 0;
}
// fonction de lecture de l'image

Image lire_image(const char *nom_fichier) {
    Image img;
    FILE *f = fopen(nom_fichier, "r");
    if (!f) {
        perror("Erreur lors de la lecture du fichier");
        img.largeur = img.hauteur = 0;
        img.pixels = NULL;
        return img;
    }

    char format[3];
    fscanf(f, "%2s", format); // lit "P3"
    fscanf(f, "%d %d", &img.largeur, &img.hauteur);
    int max;
    fscanf(f, "%d", &max);

    // Allocation dynamique de la matrice de pixels
    img.pixels = malloc(img.hauteur * sizeof(Pixel *));
    for (int i = 0; i < img.hauteur; i++) {
        img.pixels[i] = malloc(img.largeur * sizeof(Pixel));
        for (int j = 0; j < img.largeur; j++) {
            fscanf(f, "%d %d %d", &img.pixels[i][j].r, &img.pixels[i][j].g, &img.pixels[i][j].b);
        }
    }

    fclose(f);
    return img;
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
    printf("9. Quitter le programme");
}

#endif

