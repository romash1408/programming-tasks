#include <stdio.h>

struct Point
{
	double x, y;
};

struct Rect
{
	struct Point lb, rt;
};

char is_point_inside_rectangle(struct Rect r, struct Point p)
{
	return p.x >= r.lb.x && p.x <= r.rt.x && p.y >= r.lb.y && p.y <= r.rt.y;
}

int main()
{
	int x1, y1, x2, y2, tmp;
	printf("Input first point of rectangle: ");
	scanf("%lf%lf", &x1, &y1);
	printf("Input second point of rectangle: ");
	scanf("%lf%lf", &x2, &y2);
	
	if(x1 > x2)
	{
		tmp = x1;
		x1 = x2;
		x2 = tmp;
	}
	if(y1 > y2)
	{
		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}
	
	struct Rect r = {{x1, y1}, {x2, y2}};
	
	
	printf("Input another point: ");
	scanf("%lf%lf", &x1, &y1);
	
	struct Point p = {x1, y1};
	
	if(is_point_inside_rectangle(r, p))
	{
		printf("This point is inside of rectangle!\n");
	}
	else
	{
		printf("This point is outside of rectangle!\n");
	}
}