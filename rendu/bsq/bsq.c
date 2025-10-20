#include <stdio.h>
#include <stdlib.h>

int w, h;
char e, o, f;

void scpy(char *dest, char *src, size_t n) {
	while (n--) *dest++ = *src++;
}

char *gmap(FILE *file) {
	if (fscanf(file, "%d%c%c%c%c", &h, &e, &o, &f) != 5)
		return NULL;
	char *buffer;
	int n;
	w = getline(&buffer, &n, file) + 1;
	if (!buffer) return NULL;
	char *r = calloc(w * h, sizeof(char));
	scpy(r, buffer, w);
	int total = w;
	int v;
	while (v = getline(&buffer, &n, file)) {
		total += v;
	}
	free(buffer);
	return r;
}

int main(int ac, char **av) {
	FILE *file;
	if (ac < 2) file = stdin;
	else file = fopen(av[1], "r");
	char *map = gmap(file);
	fclose(file);
}
