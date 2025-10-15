/* Submitted files: *.c, *.h
 * Allowed functions: atoi, read, putchar, malloc, calloc, realloc, free */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void mems(void *ptr, int val, size_t len) {
	for (char *p = ptr; len--; *p++ = (char)val);
}

int main(int ac, char **av) {
	if (ac != 4) return 1;

	int w, h, iter;

	w = atoi(av[1]);
	h = atoi(av[2]);
	iter = atoi(av[3]);

	char fb[2][w][h];
	mems(fb, 0, sizeof(fb));

	{
		char c = 0;
		int x = 0, y = 0, p = 0;
		while (read(0, &c, 1) > 0) {
			switch (c) {
				case 'w': y--; break;
				case 'a': x--; break;
				case 's': y++; break;
				case 'd': x++; break;
				case 'x': p = !p; break;
			}
			if (p) fb[0][x][y] = 'O';
		}
	}

	int n = 0;
	for (n = 0; n < iter; n++) {

		int cur = n % 2;
		int nxt = (n + 1) % 2;

		mems(fb[nxt], 0, sizeof(fb[nxt]));

		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				int cells = 0;
				for (int yy = -1; yy <= 1; yy++) {
					for (int xx = -1; xx <= 1; xx++) {
						if (!xx && !yy) continue;
						int nx = x + xx, ny = y + yy;
						if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
						if (fb[cur][nx][ny]) cells++;
					}
				}
				if (fb[cur][x][y]) {
					fb[nxt][x][y] = (cells == 2 || cells == 3) ? 'O': 0;
				} else {
					fb[nxt][x][y] = (cells == 3) ? 'O' : 0;
				}
			}
		}
	}


	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			putchar(fb[iter % 2][x][y] ? fb[iter % 2][x][y] : ' ');
		}
		putchar('\n');
	}

	return 0;
}
