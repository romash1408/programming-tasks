#include <stdio.h>
#include <math.h>

const int maxN = 100;

struct Point
{
	float x, y;
};

struct Segment
{
	struct Point *p1, *p2;
	float distance;
};

struct Segment find_max_segment(struct Point *begin, struct Point *end)
{
	struct Segment ret = {begin, begin, 0};
	for(struct Point *i = begin; i != end; ++i)
	{
		for(struct Point *j = i - 1; j >= begin; --j)
		{
			float s = pow(i->x - j->x, 2) + pow(i->y - j->y, 2);
			if(ret.distance < s)
			{
				ret.p1 = i;
				ret.p2 = j;
				ret.distance = s;
			}
		}
	}
	return ret;
}

int main()
{
	int n = 0;
	struct Point points[maxN];
	
	printf("Input points:\n");
	while(scanf("%f%f", &(points[n].x), &(points[n].y)) == 2 && ++n < maxN);
		
	if(n < 2)
	{
		printf("Nothing to work with\n");
	}
	
	struct Segment max = find_max_segment(points, points + n);
	
	printf("Max distance from (%.2f, %.2f) to (%.2f, %.2f) is %.3f\n", max.p1->x, max.p1->y, max.p2->x, max.p2->y, sqrt(max.distance));
	
	return 0;
}