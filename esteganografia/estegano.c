/**************************************************************

	The program reads an BMP image file and creates a new
	image that is the negative of the input file.

**************************************************************/

#include "qdbmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct txt_file_t {
	char *s;
	int size;
} txt_file_t;


void load_txt_file (char *fname, txt_file_t *file)
{
	FILE *fp;
	size_t result;

	fp = fopen(fname , "rb" );
	assert(fp != NULL);

	// obtain file size:
	fseek (fp , 0 , SEEK_END);
	file->size = ftell (fp);
	rewind (fp);

	// allocate memory to contain the whole file:
	file->s = (char*) malloc (file->size+1);
	assert(file->s != NULL);

	// copy the file into the buffer:
	result = fread (file->s,1,file->size,fp);
	assert(result == file->size);

	// terminate
	fclose (fp);
}

void hide_secret (txt_file_t *txt, BMP *bmp, int width, int height)
{
	int i, j, x, y;
	UCHAR r, g, b, bit;

	BMP_GetPixelRGB( bmp, 0, 0, &r, &g, &b );
	BMP_SetPixelRGB( bmp, 0, 0, txt->size, g, b); // Seta o tamanho do texto no bit 0 0 na posição vermelho

	x = 1;
	y = 0;

	for (i=0; i<txt->size; i++) {
		for (j=0; j<8; j++) {
			bit = (txt->s[i] >> j) & 0x01; // Desloca os bits para a direita, extrai o bit j do txt

			BMP_GetPixelRGB( bmp, x, y, &r, &g, &b ); // Pega o pixel da img

			r = (r & 0xFE) | bit; // Exclui o bit 0 e troca pelo bit do txt

			BMP_SetPixelRGB( bmp, x, y, r, g, b ); // Escreve na foto o rgb com o r alterado para txt

			x++;
			if (x >= width) {
				x = 0;
				y++;
			}
		}
	}
}

void recover_secret (BMP *bmp, int width, int height)
{
	int i, j, x, y;
	UCHAR r, g, b, bit;
	// Recuperar a informação do bit r
	BMP_GetPixelRGB( bmp, 0, 0, &r, &g, &b );

	printf(BMP_GetPixelRGB);

}

/* Creates a negative image of the input bitmap file */
int main( int argc, char **argv )
{
	UCHAR	r, g, b;
	UINT	width, height;
	UINT	x, y;
	BMP*	bmp;
	int capacity_bytes;
	char *input_bmp, *output_bmp, *input_txt;
	txt_file_t txt;

	/* Check arguments */

	if (argc != 4) {
		printf("Usage: %s <input bmp> <input txt> <output bmp>\n", argv[0]);
		return 0;
	}

	input_bmp = argv[1];
	input_txt = argv[2];
	output_bmp = argv[3];

	/* Read an image file */
	bmp = BMP_ReadFile(input_bmp);
	BMP_CHECK_ERROR( stdout, -1 );

	/* Get image's dimensions */
	width = BMP_GetWidth( bmp );
	height = BMP_GetHeight( bmp );

	capacity_bytes = (width * height) / 8;

	load_txt_file(input_txt, &txt);

	printf("width: %u\n", width);
	printf("height: %u\n", height);
	printf("capacity_bytes: %u\n", capacity_bytes);
	printf("secret bytes: %u\n", txt.size);

	if (txt.size > capacity_bytes) {
		printf("não há capacidade para esconder os dados\n");
		return 0;
	}

	hide_secret(&txt, bmp, width, height);
	printf("segredo escondido!\n");


	/* Save result */
	BMP_WriteFile(bmp, output_bmp);
	BMP_CHECK_ERROR( stdout, -2 );

	/* Free all memory allocated for the image */
	BMP_Free( bmp );

	////////////////////////////////////////////////////////////////////

	bmp = BMP_ReadFile(output_bmp);
	BMP_CHECK_ERROR( stdout, -1 );

	/* Get image's dimensions */
	width = BMP_GetWidth( bmp );
	height = BMP_GetHeight( bmp );

	recover_secret (bmp, width, height);

	BMP_Free( bmp );

	return 0;
}
