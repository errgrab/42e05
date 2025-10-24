#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef unsigned char u8;

static inline int idx(int x, int y, int w) { return y * w + x; }
static void zb(u8 *p, int n) { while (n--) *p++ = 0; }

static int nb(const u8 *g, int w, int h, int x, int y) {
	int c = 0;
	for (int dy = -1; dy <= 1; dy++) {
		for (int dx = -1; dx <= 1; dx++) {
			if (!dx && !dy) continue;
			int nx = x + dx, ny = y + dy;
			if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
			c += g[idx(nx, ny, w)] ? 1 : 0;
		}
	}
	return c;
}

static void step(const u8 *cur, u8 *nxt, int w, int h) {
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			int n = nb(cur, w, h, x, y);
			u8 a = cur[idx(x, y, w)];
			nxt[idx(x, y, w)] = (n == 3 || (a && n == 2)) ? 1 : 0;
		}
	}
}

static void print(const u8 *g, int w, int h) {
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			putchar(g[idx(x, y, w)] ? 'O' : ' ');
		}
		putchar('\n');
	}
}

static void pencil(u8 *g, int w, int h) {
	int x = 0, y = 0, p = 0;
	char c = 0;
	while (read(0, &c, 1) > 0) {
		if (c == 'w') y--;
		if (c == 'a') x--;
		if (c == 's') y++;
		if (c == 'd') x++;
		if (c == 'x') p = !p;
		if (x < 0) x = 0;
		else if (x >= w) x = w - 1;
		if (y < 0) y = 0;
		else if (y >= h) y = h - 1;
		if (p) g[idx(x, y, w)] = 1;
	}
}

int main(int ac, char **av) {
	if (ac != 4) return 1;
	int w = atoi(av[1]);
	int h = atoi(av[2]);
	int it = atoi(av[3]);
	if (w <= 0 || h <= 0 || it < 0) return 1;
	int ncel = w * h;
	u8 *cur = (u8*)calloc(ncel, 1);
	u8 *nxt = (u8*)calloc(ncel, 1);
	if (!cur || !nxt) return 1;
	pencil(cur, w, h);
	for (int i = 0; i < it; i++) {
		zb(nxt, ncel);
		step(cur, nxt, w, h);
		u8 *tmp = cur;
		cur = nxt;
		nxt = tmp;
	}
	print(cur, w, h);
	free(cur);
	free(nxt);
	return 0;
}
