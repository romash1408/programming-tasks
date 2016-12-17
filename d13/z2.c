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

struct Rect make_canonical_rectangle(const struct Rect r)
{
	struct Rect ret;
	
	if(r.lb.x > r.rt.x)
	{
		ret.rt.x = r.lb.x;
		ret.lb.x = r.rt.x;
	}
	else
	{
		ret.lb.x = r.lb.x;
		ret.rt.x = r.rt.x;
	}
	
	if(r.lb.y > r.rt.y)
	{
		ret.rt.y = r.lb.y;
		ret.lb.y = r.rt.y;
	}
	else
	{
		ret.lb.y = r.lb.y;
		ret.rt.y = r.rt.y;
	}
	
	return ret;
}

int main()
{
	double x1, y1, x2, y2, tmp;
	printf("Input first point of rectangle: ");
	scanf("%lf%lf", &x1, &y1);
	printf("Input second point of rectangle: ");
	scanf("%lf%lf", &x2, &y2);
	
	struct Rect r = {{x1, y1}, {x2, y2}};
	r = make_canonical_rectangle(r);
	
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