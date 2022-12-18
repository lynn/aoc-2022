#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE* Open(const char* filename) {
	FILE *f = fopen(filename, "r");
	if (f == NULL) {
		printf("Failed to open %s\n", filename);
		exit(1);
	}
	return f;
}

int ReadLongParagraph(FILE* f, long* out) {
	char line[11];
	int count = 0;
	for (;;) {
		if (fgets(line, sizeof(line), f) == NULL || line[0] < '0') {
			return count;
		}
		if (sscanf(line, "%ld", out) != 1) {
			printf("Failed to read int at %d (line:%s)\n", ftell(f), line);
			exit(1);
		}
		count++, out++;
	}
}
