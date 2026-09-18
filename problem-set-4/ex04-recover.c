#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 512

bool is_jpeg(unsigned char buffer[BUF_SIZE]);

int main(int argc, char *argv[])
{
	// Accept a single command-line argument
	if (argc != 2)
	{
		printf("Usage: ./recover FILE\n");
		exit(EXIT_FAILURE);
	}
	// Open the memory card
	FILE *card = fopen(argv[1], "rb");
	if (card == NULL)
		exit(EXIT_FAILURE);
	// Create a buffer for a block of data
	unsigned char buffer[BUF_SIZE];
	char filename[8];
	int file_number = 0;
	size_t bytes_read;
	FILE *img;
	// While there's still data left to read from the memory card
	while ((bytes_read = fread(buffer, 1, BUF_SIZE, card)) > 0)
	{
		// Create JPEGs from the data
		if (is_jpeg(buffer) == true)
		{
			if (file_number > 0)
				fclose(img);
			sprintf(filename, "%03d.jpg", file_number);
			file_number++;
			img = fopen(filename, "wb");
			if (img == NULL)
				exit(EXIT_FAILURE);
		}
		if (file_number > 0)
			fwrite(buffer, 1, bytes_read, img);
	}
	if (file_number > 0)
		fclose(img);
}

bool is_jpeg(unsigned char buffer[BUF_SIZE])
{
	if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
		return true;
	else
		return false;
}
