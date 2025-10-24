#include <stdio.h>
#include <stdlib.h>


int w, h;
char e, o, f;

char **input = NULL;
int **map = NULL;

int idx(int x, int y, int w) { return y * w + x; }
int min3(int a, int b, int c) { return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c); }

void free_input(char **input) {
	for (int y = 0; y < h; y++) {
		if (input[y]) free(input[y]);
	}
	free(input);
}

void free_map(int **map) {
	for (int y = 0; y < h; y++) {
		if (map[y]) free(map[y]);
	}
	free(map);
}

// In the exam there was more things that I checked like the line lenght for evey line...
void get_map(FILE *file) {

	char newline;
	if (fscanf(file, "%d%c%c%c%c", &h, &e, &o, &f, &newline) != 5 || newline != '\n') return;
	if (e == o || e == f || f == o || h <= 0) return;

	map = calloc(h, sizeof(int*));
	if (!map) return;

	input = calloc(h, sizeof(char*));
	if (!input) return;

	char *buffer = NULL;
	size_t n = 0;
	w = getline(&buffer, &n, file) - 1;
	if (!buffer) return;
	input[0] = buffer;

	int *line = calloc(w, sizeof(int));
	if (!line) return;

	for (int x = 0; x < w; x++) {
		line[x] = 1;
		if (buffer[x] == o) line[x] = 0;
	}
	map[0] = line;

	for (int y = 1; y < h; y++) {
		buffer = NULL;
		n = 0;
		getline(&buffer, &n, file);
		if (!buffer) return;
		input[y] = buffer;

		line = calloc(w, sizeof(int));
		if (!line) return;

		map[y] = line;
		for (int x = 0; x < w; x++) {
			if (x == 0)
				map[y][x] = 1;
			else if (input[y][x] == o)
				map[y][x] = 0;
			else
				map[y][x] = 1 + min3(map[y - 1][x], map[y][x - 1], map[y - 1][x - 1]);
		}
	}
}

int main(int ac, char **av) {
	FILE *file;

	if (ac < 2) file = stdin;
	else file = fopen(av[1], "r");

	get_map(file);

	if (!map || !input) {
		fprintf(stderr, "Error: invalid map\n");
		if (!map) free_map(map);
		if (!input) free_input(input);
		return 1;
	}

	int mx = 0, my = 0, mm = 0;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (map[y][x] > mm) {
				mm = map[y][x];
				mx = x; my = y;
			}
		}
	}

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (x > mx - mm && x <= mx && y > my - mm && y <= my) {
				printf("%c", f);
			} else {
				printf("%c", input[y][x]);
			}
		}
		printf("\n");
	}

	fclose(file);
	free_map(map);
	free_input(input);
	return 0;
}
