#include "bmp.h"
#include <math.h>

typedef struct
{
	int height;
	int width;
	int i;
	int j;
}	dimensions;

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]);

RGBTRIPLE edges_color(dimensions d, RGBTRIPLE image[d.height + 2][d.width + 2]);
