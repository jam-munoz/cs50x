// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
	// Check command-line arguments
	if (argc != 4)
	{
		printf("Usage: ./volume input.wav output.wav factor\n");
		exit(EXIT_FAILURE);
	}

	// Open files and determine scaling factor
	FILE *input = fopen(argv[1], "rb");
	if (input == NULL)
	{
		printf("Could not open file.\n");
		exit(EXIT_FAILURE);
	}

	FILE *output = fopen(argv[2], "wb");
	if (output == NULL)
	{
		printf("Could not open file.\n");
		exit(EXIT_FAILURE);
	}

	float factor = atof(argv[3]);

	// Copy header from input file to output file
	char buf[HEADER_SIZE];
	size_t n;
	n = fread(buf, sizeof(char), HEADER_SIZE, input);
	if (n != HEADER_SIZE)
	{
		printf("Read error.\n");
		exit(EXIT_FAILURE);
	}
	n = fwrite(buf, sizeof(char), HEADER_SIZE, output);
	if (n != HEADER_SIZE)
	{
		printf("Write error.\n");
		exit(EXIT_FAILURE);
	}
	// Read samples from input file and write updated data to output file
	int16_t buffer;
	while (fread(&buffer, sizeof(int16_t), 1, input) == 1)
	{
		buffer = (float)buffer * factor;
		n = fwrite(&buffer, sizeof(int16_t), 1, output);

		if (n != 1)
		{
			printf("Write error.\n");
			exit(EXIT_FAILURE);
		}
	}
	// Close files
	fclose(input);
	fclose(output);
}
