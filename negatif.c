#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f_in, *f_out;
    char type[3];
    int largeur, hauteur, max;
    int r, g, b;

    //  Ouvrir le fichier source (image originale)
    f_in = fopen("image.ppm", "r");
    if (f_in == NULL) {
        printf("Erreur : impossible d’ouvrir image.ppm\n");
        return 1;
    }

    // Lire l’en-tête du fichier PPM
    fscanf(f_in, "%s", type); // P3 ou P6
    if (type[0] != 'P' || type[1] != '3') {
        printf("Erreur : format non supporté (doit être P3)\n");
        fclose(f_in);
        return 1;
    }

    fscanf(f_in, "%d %d", &largeur, &hauteur);
    fscanf(f_in, "%d", &max);

    //  Créer le fichier de sortie
    f_out = fopen("image_negative.ppm", "w");
    if (f_out == NULL) {
        printf("Erreur : impossible de créer le fichier de sortie\n");
        fclose(f_in);
        return 1;
    }

    //  Écrire l’en-tête du nouveau fichier
    fprintf(f_out, "P3\n");
    fprintf(f_out, "%d %d\n", largeur, hauteur);
    fprintf(f_out, "%d\n", max);

    //  Lire chaque pixel et écrire son négatif
    for (int i = 0; i < largeur * hauteur; i++) {
        fscanf(f_in, "%d %d %d", &r, &g, &b);
        fprintf(f_out, "%d %d %d\n", max - r, max - g, max - b);
    }

  // Fermer les fichiers
    fclose(f_in);
    fclose(f_out);

    printf("✅ Négatif créé dans 'image_negative.ppm'\n");
    return 0;
}