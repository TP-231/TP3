#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

typedef struct {
    int r, g, b; 
} Pixel;

typedef struct {
    int largeur;
    int hauteur;
    Pixel **pixels; 
} Image;

int compare_ints(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

Image appliquer_filtre_median(const Image *image_orig) {
   
    Image image_filtree;
    int h = image_orig->hauteur;
    int l = image_orig->largeur;

    image_filtree.hauteur = h;
    image_filtree.largeur = l;
    
    image_filtree.pixels = (Pixel **)malloc(h * sizeof(Pixel *));
    if (image_filtree.pixels == NULL) return image_filtree; 

    for (int i = 0; i < h; i++) {
        image_filtree.pixels[i] = (Pixel *)malloc(l * sizeof(Pixel));
        if (image_filtree.pixels[i] == NULL) {
            for (int k = 0; k < i; k++) free(image_filtree.pixels[k]);
            free(image_filtree.pixels);
            image_filtree.pixels = NULL;
            return image_filtree;
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < l; x++) {
            int blue_values[9];
            int red_values[9];
            int green_values[9];
            int count = 0;

            
            for (int j = -1; j <= 1; j++) {
                for (int i = -1; i <= 1; i++) {
                    int nx = x + i;
                    int ny = y + j;

                
                    if (nx >= 0 && nx < l && ny >= 0 && ny < h) {
                        Pixel p = image_orig->pixels[ny][nx];
                        red_values[count] = p.r;
                        green_values[count] = p.g;
                        blue_values[count] = p.b;
                        count++;
                    }
                }
            }

            qsort(red_values, count, sizeof(int), compare_ints);
            qsort(green_values, count, sizeof(int), compare_ints);
            qsort(blue_values, count, sizeof(int), compare_ints);

            int median_index = count / 2;
            
            Pixel* new_pixel = &image_filtree.pixels[y][x];
            
            new_pixel->r = red_values[median_index];
            new_pixel->g = green_values[median_index];
            new_pixel->b = blue_values[median_index];
            
            
        }
    }

    return image_filtree;
}


void liberer_image(Image *img) {
    if (img->pixels) {
        for (int i = 0; i < img->hauteur; i++) {
            free(img->pixels[i]);
        }
        free(img->pixels);
        img->pixels = NULL;
    }
}
