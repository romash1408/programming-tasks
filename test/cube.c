#include <stdio.h>

const int MAX_N = 100;

enum C{
	c1 = 0,
	c2 = 1,
	c3 = 2,
	c4 = 3,
	c5 = 4,
	c6 = 5
};

struct pos{
	int x;
	int y;
	enum C c;
};

int cube[6][MAX_N][MAX_N], n;
struct pos s, t, c, v;

void readpos(struct pos *c)
{
	float x, y, z;
	scanf("%f %f %f", &x, &y, &z);
	if(z == 0) { c->c = c4; c->x = n - y; 	c->y = n - x; } else
	if(z == n) { c->c = c2; c->x = n - y; 	c->y = x; } else
	if(y == 0) { c->c = c6; c->x = x; 	c->y = z; } else
	if(y == n) { c->c = c5; c->x = n - x; 		c->y = z; } else
	if(x == 0) { c->c = c1; c->x = n - y; 	c->y = z; } else
	if(x == n) { c->c = c3; c->x = n - y; 	c->y = n - z; }
}

void cp(struct pos *src, struct pos *dst)
{
	dst->c = src->c;
	dst->x = src->x;
	dst->y = src->y;
}

void go(struct pos *o, struct pos *v)
{
	int m = n - 1;
	o->x += v->x; o->y += v->y;
	if(o->x == -1){
		switch(o->c){
			case c1: o->c = c5; o->x = m; break;
			case c2: o->c = c5; o->x = m - o->y; o->y = m; v->x = 0; v->y = -1; break;
			case c3: o->c = c5; o->x = 0; o->y = m - o->y; v->x = 1; break;
			case c4: o->c = c5; o->x = o->y; o->y = 0; v->x = 0; v->y = 1; break;
			case c5: o->c = c3; o->x = 0; o->y = m - o->y; v->x = 1; break;
			case c6: o->c = c1; o->x = m; break;
		}
	} else
	if(o->x == n){
		switch(o->c){
			case c1: o->c = c6; o->x = 0; break;
			case c2: o->c = c6; o->x = o->y; o->y = m; v->x = 0; v->y = -1; break;
			case c3: o->c = c6; o->x = m; o->y = m - o->y; v->x = -1; break;
			case c4: o->c = c6; o->x = m - o->y; o->y = 0; v->x = 0; v->y = 1; break;
			case c5: o->c = c1; o->x = 0; break;
			case c6: o->c = c3; o->x = m; o->y = m - o->y; v->x = -1; break;
		}
	} else
	if(o->y == -1){
		switch(o->c){
			case c1: o->c = c4; o->y = m; break;
			case c2: o->c = c1; o->y = m; break;
			case c3: o->c = c2; o->y = m; break;
			case c4: o->c = c3; o->y = m; break;
			case c5: o->c = c4; o->y = o->x; o->x = 0; v->y = 0; v->x = 1; break;
			case c6: o->c = c4; o->y = m - o->x; o->x = m; v->y = 0; v->x = -1; break;
		}
	} else
	if(o->y == n){
		switch(o->c){
			case c1: o->c = c2; o->y = 0; break;
			case c2: o->c = c3; o->y = 0; break;
			case c3: o->c = c4; o->y = 0; break;
			case c4: o->c = c1; o->y = 0; break;
			case c5: o->c = c2; o->y = m - o->x; o->x = 0; v->y = 0; v->x = 1; break;
			case c6: o->c = c2; o->y = o->x; o->x = m; v->y = 0; v->x = -1; break;
		}
	}
}

int get(struct pos p){
	return cube[p.c][p.x][p.y];
}
void set(struct pos p, int val){
	cube[p.c][p.x][p.y] = val;
}

int main()
{
	scanf("%d", &n);
	readpos(&s);
	readpos(&t);
	cp(&t, &c);
	printf("s: %d %d %d; t: %d %d %d\n", s.c + 1, s.x, s.y, t.c + 1, t.x, t.y);

	
	v.x = 1; v.y = 0;
	for(int i = 0; i <= n * 2; ++i) {set(c, i+1); go(&c, &v);}
	for(int i = n * 2 - 1; i > 0; --i) {set(c, i+1); go(&c, &v);}

	v.x = 0; v.y = 1;
	for(int i = 0; i <= n * 2; ++i) {set(c, i+1); go(&c, &v);}
	for(int i = n * 2 - 1; i > 0; --i) {set(c, i+1); go(&c, &v);}

	for(c.c = 0; c.c < 6; ++c.c){
		printf("\n%d\n", c.c + 1);
		for(c.y = n - 1; c.y >= 0; --c.y){
			for(c.x = 0; c.x < n; ++c.x){
				printf("%d", get(c));
			}
		printf("\n");
		}
	}
	//return 0;

	int min = n * n + 1, here, i;

	cp(&s, &c);
	v.x = 1; v.y = 0; i = 0;
	while((here = get(c)) == 0 ) go(&c, &v), ++i;
	if(here + i < min) min = here + i;

	cp(&s, &c);
	v.x = -1; v.y = 0; i = 0;
	while((here = get(c)) == 0) go(&c, &v), ++i;
	if(here + i < min) min = here + i;

	cp(&s, &c);
	v.x = 0; v.y = 1; i = 0;
	while((here = get(c)) == 0) go(&c, &v), ++i;
	if(here + i < min) min = here + i;

	cp(&s, &c);
	v.x = 0; v.y = -1; i = 0;
	while((here = get(c)) == 0) go(&c, &v), ++i;
	if(here + i < min) min = here + i;

	printf("%d\n", min - 1);

	return 0;
}