#include <stdio.h>

int NoirBlanc(){
	FILE *outFile = fopen("imageNB.ppm", "w"), *inFile = fopen("image.ppm", "r");
	
	int numLigne = 1;
	char format[3];
	int height, width, maxPix;
	
	fscanf(inFile, "%2s", format);
	fprintf(outFile, "%2s\n", format);
	//numLigne++;
	
	fscanf(inFile, "%d %d", &height, &width);
	fprintf(outFile, "%d %d\n", height, width);
	//numLigne++;
	
	fscanf(inFile, "%d", &maxPix);
	fprintf(outFile, "%d\n", maxPix);
	//numLigne++;
	
	int r, g, b, gray;
	for(int i = 0; i < height; i++){
		for(int j = 0; j< width; j++){
			fscanf(inFile, "%d %d %d", &r, &g, &b);
			gray = (r + b + g)/3;
			fprintf(outFile, "%d %d %d  ", gray, gray, gray);
		}
		fprintf(outFile, "\n");
	}
	
	fclose(outFile);
	fclose(inFile);
	
	return 0;
}