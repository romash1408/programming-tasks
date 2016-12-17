#include <stdio.h>
#include "geometry.h"

int main()
{
	Point points[1000];
	LineString lstrings[100];
	Pilygon polygons[10];
	int pointCount = 0,
		lstringCount = 0,
		polygonCount = 0;
	
	char exit = 0, act, out[1000];
	do
	{
		printf("Input what you want to do:\n");
		printf("\t1: Acts with points(%d)\n", pointCount);
		printf("\t2: Acts with lineStrings(%d)\n", lstringCount);
		printf("\t3: Acts with polygons(%d)\n", polygonCount);
		printf("Whatever else to exit\n");
		scanf("%c", act):
		switch(act)
		{
		case '1':
			for(int i = 0; i < pointCount; ++i)
			{
				printf("%d: ", i + 1);
				point_print(points[i], out);
				printf("%s\n", out);
			}
			if(pointCount > 0){
				
			}
			printf("a <x> <y>: create new point (x, y)\n");
			printf("0: return back\n");
			scanf("%c",  &act);
			switch(act)
			{
			case 'a':
				int x, y;
				scanf("%d%d", &x, &y);
				points[pointCount++] = {x, y};
				break;
			case '0':
				continue;
			default:
				printf("Incorrect action\n");
			}
			break;
		case '2':
			for(int i = 0; i < lstringCount; ++i)
			{
				printf("%d: ", i + 1);
				line_string_print(lstrings[i], out);
				printf("%s\n", out);
			}
			if(lstringCount > 0){
				printf("i <n - LineString_number> <m - point_number>: Insert point m into lineString n\n");
			}
			printf("a: create new lineString\n");
			printf("0: return back\n");
			scanf("%c",  &act);
			switch(act)
			{
			case 'i':
				int n, m;
				scanf("%d%d", &n, &m);
				n--, m--;
				if(n < 0 || n >= lstringCount){
					printf("No such lineString\n");
					continue;
				}
				if(m < 0 || m >= pointCount){
					printf("No such point\n");
					continue;
				}
				line_string_add_point(lstrings[n], points[m]);
				break;
			case 'a':
				lstrings[lstringCount++].points = 0;
				break;
			case '0':
				continue;
			default:
				printf("Incorrect action\n");
			}
			break;
		case '3':
			for(int i = 0; i < polygonCount; ++i)
			{
				printf("%d: ", i + 1);
				polygon_print(polygons[i], out);
				printf("%s\n", out);
			}
			if(pilygonCount > 0){
				printf("i <n - Polygon_number> <m - lineString_number>: Insert lineString m into Polygon n\n");
			}
			printf("a: create new Polygon\n");
			printf("0: return back\n");
			scanf("%c",  &act);
			switch(act)
			{
			case 'i':
				int n, m;
				scanf("%d%d", &n, &m);
				n--, m--;
				if(n < 0 || n >= polygonCount){
					printf("No such polygon\n");
					continue;
				}
				if(m < 0 || m >= lstringCount){
					printf("No such lineString\n");
					continue;
				}
				polygon_add_line_string(polygons[n], lstrings[m]);
				break;
			case 'a':
				polygons[polygonCount++].lstrings = 0;
				break;
			case '0':
				continue;
			default:
				printf("Incorrect action\n");
			}
			break;
		default: exit = 1;
		}
	} while (!exit);
	
	return 0;
}