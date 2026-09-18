#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
	unsigned int mix;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			mix = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;

			image[i][j].rgbtBlue = mix;
			image[i][j].rgbtGreen = mix;
			image[i][j].rgbtRed = mix;
		}
	}
	return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
	unsigned int r, g ,b;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			r = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
			g = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
			b = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;
			if (r > 255)
				r = 255;
			if (g > 255)
				g = 255;
			if (b > 255)
				b = 255;
			image[i][j].rgbtBlue = b;
			image[i][j].rgbtGreen = g;
			image[i][j].rgbtRed = r;
		}
	}
	return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
	RGBTRIPLE temp;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0, w = width - 1; j <= w; j++, w--)
		{
			temp = image[i][j];
			image[i][j] = image[i][w];
			image[i][w] = temp;
		}
	}
	return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
	// Create a copy of image
	RGBTRIPLE copy[height][width];

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			copy[i][j] = image[i][j];
		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 && j == 0)
			{
				image[i][j].rgbtBlue = (copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
					copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 4;
				image[i][j].rgbtGreen = (copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen +
					copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 4;
				image[i][j].rgbtRed = (copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed +
					copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 4;
			}
			else if (i == height - 1 && j == width - 1)
			{
				image[i][j].rgbtBlue = (copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue +
					copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue) / 4;
				image[i][j].rgbtGreen = (copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen +
					copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen) / 4;
				image[i][j].rgbtRed = (copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed +
					copy[i - 1][j].rgbtRed + copy[i - 1][j - 1].rgbtRed) / 4;
			}
			else if (i == 0 && j == width - 1)
			{
				image[i][j].rgbtBlue = (copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue +
					copy[i + 1][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue) / 4;
				image[i][j].rgbtGreen = (copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen +
					copy[i + 1][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen) / 4;
				image[i][j].rgbtRed = (copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed +
					copy[i + 1][j].rgbtRed + copy[i + 1][j - 1].rgbtRed) / 4;
			}
			else if (i == height - 1 && j == 0)
			{
				image[i][j].rgbtBlue = (copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
					copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue) / 4;
				image[i][j].rgbtGreen = (copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen +
					copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen) / 4;
				image[i][j].rgbtRed = (copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed +
					copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed) / 4;
			}
			else if (i == 0)
			{
				image[i][j].rgbtBlue = (copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i][j - 1].rgbtBlue +
					copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue) / 6;
				image[i][j].rgbtGreen = (copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i][j - 1].rgbtGreen +
					copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen) / 6;
				image[i][j].rgbtRed = (copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i][j - 1].rgbtRed +
					copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed) / 6;
			}
			else if (j == 0)
			{
				image[i][j].rgbtBlue = (copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
					copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue +
					copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue) / 6;
				image[i][j].rgbtGreen = (copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen +
					copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen +
					copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen) / 6;
				image[i][j].rgbtRed = (copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed +
					copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed +
					copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed) / 6;
			}
			else if (i == height - 1)
			{
				image[i][j].rgbtBlue = (copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i][j - 1].rgbtBlue +
					copy[i -1][j].rgbtBlue + copy[i -1][j + 1].rgbtBlue + copy[i -1][j - 1].rgbtBlue) / 6;
				image[i][j].rgbtGreen = (copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i][j - 1].rgbtGreen +
					copy[i -1][j].rgbtGreen + copy[i -1][j + 1].rgbtGreen + copy[i -1][j - 1].rgbtGreen) / 6;
				image[i][j].rgbtRed = (copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i][j - 1].rgbtRed +
					copy[i -1][j].rgbtRed + copy[i -1][j + 1].rgbtRed + copy[i -1][j - 1].rgbtRed) / 6;
			}
			else if (j == width - 1)
			{
				image[i][j].rgbtBlue = (copy[i][j].rgbtBlue + copy[i][j -1].rgbtBlue +
					copy[i + 1][j].rgbtBlue + copy[i + 1][j -1].rgbtBlue +
					copy[i - 1][j].rgbtBlue + copy[i - 1][j -1].rgbtBlue) / 6;
				image[i][j].rgbtGreen = (copy[i][j].rgbtGreen + copy[i][j -1].rgbtGreen +
					copy[i + 1][j].rgbtGreen + copy[i + 1][j -1].rgbtGreen +
					copy[i - 1][j].rgbtGreen + copy[i - 1][j -1].rgbtGreen) / 6;
				image[i][j].rgbtRed = (copy[i][j].rgbtRed + copy[i][j -1].rgbtRed +
					copy[i + 1][j].rgbtRed + copy[i + 1][j -1].rgbtRed +
					copy[i - 1][j].rgbtRed + copy[i - 1][j -1].rgbtRed) / 6;
			}
			else
			{
				image[i][j].rgbtBlue = (copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i][j - 1].rgbtBlue +
					copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue +
					copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue) / 9;
				image[i][j].rgbtGreen = (copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i][j - 1].rgbtGreen +
					copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen +
					copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen) / 9;
				image[i][j].rgbtRed = (copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i][j - 1].rgbtRed +
					copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed +
					copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i - 1][j - 1].rgbtRed) / 9;
			}
		}
	}
	return;
}
