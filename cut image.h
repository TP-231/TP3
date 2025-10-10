#include <stdio.h>
#include "image.h"
//Enregistrer dans un fichier une partie de l'image 

int cutImage( Image *Img, int l1, int l2, int c1, int c2, const char *fichier_resultat) {
    // Vérification des bornes
    if (l1 < 0 || c1 < 0 || l2 > Img->hauteur || c2 > Img->largeur || l1 >= l2 || c1 >= c2) {
        printf("Valeurs de decoupe invalides !\n");
        return 1;
    }

    int nouvelle_hauteur = l2 - l1;
    int nouvelle_largeur = c2 - c1;

    FILE *f = fopen(fichier_resultat, "w");
    if (!f) {
        perror("Erreur lors de la creation du fichier resultat");
        return 1;
    }

    // Écriture de l'en-tête PPM
    fprintf(f, "P3\n");
    fprintf(f, "%d %d\n", nouvelle_largeur, nouvelle_hauteur);
    fprintf(f, "255\n");

    // Copie des pixels de la zone choisie
    for (int i = l1; i < l2; i++) {
        for (int j = c1; j < c2; j++) {
            Pixel p = Img->pixels[i][j];
            fprintf(f, "%d %d %d ", p.r, p.g, p.b);
        }
        fprintf(f, "\n");
    }

    fclose(f);
    printf("Image decoupee sauvegardee dans %s\n", fichier_resultat);
    return 0;
}
