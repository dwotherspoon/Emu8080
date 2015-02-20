#include <stdio.h>
#include <stdlib.h>
#include "i8080.h"

int main(int argc, char * argv[]) {
	FILE * fp;
	I8080_State * r = init_8080();
	/* Init stuff */
	if ((fp = fopen("test.bin", "rb"))) {
		printf("Read in %lu bytes from test.bin\n\r", fread(r->mem, sizeof(uint8_t), 0xFFFF, fp));
		fclose(fp);

		/* Go */
		run_8080(r);
	}
	else {
		puts("No file; test.bin. Exiting.");
	}

	free(r);

	return 0;
}