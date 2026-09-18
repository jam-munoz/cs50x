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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
	dimensions d;
	d.height = height + 2;
	d.width = width + 2;
	RGBTRIPLE copy[d.height][d.width];
	RGBTRIPLE zero = { 0 };
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			copy[i + 1][j + 1] = image[i][j];
		}
	}
	for (int j = 0; j < d.width; j++)
	{
		copy[0][j] = zero;
		copy[d.height - 1][j] = zero;
	}
	for (int i = 0; i < d.height; i++)
	{
		copy[i][0] = zero;
		copy[i][d.width - 1] = zero;
	}
	for (d.i = 1; d.i <= height; d.i++)
	{
		for (d.j = 1; d.j <= width; d.j++)
		{
			image[d.i - 1][d. j - 1] = edges_color(d, copy);
		}
	}
	return;
}

RGBTRIPLE edges_color(dimensions d, RGBTRIPLE image[d.height][d.width])
{
	typedef struct
	{
		int blue;
		int green;
		int red;
	}	kernel;
	kernel gx;
	kernel gy;
	RGBTRIPLE out;

	gx.blue = -image[d.i - 1][d.j - 1].rgbtBlue + image[d.i - 1][d.j + 1].rgbtBlue +
				-2 * image[d.i][d.j - 1].rgbtBlue + 2 * image[d.i][d.j + 1].rgbtBlue +
				-image[d.i + 1][d.j - 1].rgbtBlue + image[d.i + 1][d.j + 1].rgbtBlue;
	gy.blue = -image[d.i - 1][d.j - 1].rgbtBlue + -2 * image[d.i - 1][d.j].rgbtBlue + -image[d.i - 1][d.j + 1].rgbtBlue +
				image[d.i + 1][d.j - 1].rgbtBlue + 2 * image[d.i + 1][d.j].rgbtBlue + image[d.i + 1][d.j + 1].rgbtBlue;
	gx.green = -image[d.i - 1][d.j - 1].rgbtGreen + image[d.i - 1][d.j + 1].rgbtGreen +
				-2 * image[d.i][d.j - 1].rgbtGreen + 2 * image[d.i][d.j + 1].rgbtGreen +
				-image[d.i + 1][d.j - 1].rgbtGreen + image[d.i + 1][d.j + 1].rgbtGreen;
	gy.green = -image[d.i - 1][d.j - 1].rgbtGreen + -2 * image[d.i - 1][d.j].rgbtGreen + -image[d.i - 1][d.j + 1].rgbtGreen +
				image[d.i + 1][d.j - 1].rgbtGreen + 2 * image[d.i + 1][d.j].rgbtGreen + image[d.i + 1][d.j + 1].rgbtGreen;
	gx.red = -image[d.i - 1][d.j - 1].rgbtRed + image[d.i - 1][d.j + 1].rgbtRed +
				-2 * image[d.i][d.j - 1].rgbtRed + 2 * image[d.i][d.j + 1].rgbtRed +
				-image[d.i + 1][d.j - 1].rgbtRed + image[d.i + 1][d.j + 1].rgbtRed;
	gy.red = -image[d.i - 1][d.j - 1].rgbtRed + -2 * image[d.i - 1][d.j].rgbtRed + -image[d.i - 1][d.j + 1].rgbtRed +
				image[d.i + 1][d.j - 1].rgbtRed + 2 * image[d.i + 1][d.j].rgbtRed + image[d.i + 1][d.j + 1].rgbtRed;

	gx.blue = round(sqrt(gx.blue * gx.blue + gy.blue * gy.blue));
	if (gx.blue > 255)
		gx.blue = 255;
	gx.green = round(sqrt(gx.green * gx.green + gy.green * gy.green));
	if (gx.green > 255)
		gx.green = 255;
	gx.red = round(sqrt(gx.red * gx.red + gy.red * gy.red));
	if (gx.red > 255)
		gx.red = 255;
	out.rgbtBlue = (unsigned int)gx.blue;
	out.rgbtGreen = (unsigned int)gx.green;
	out.rgbtRed = (unsigned int)gx.red;

	return out;
}
