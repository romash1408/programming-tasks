#ifndef POINT_H
#define POINT_H

typedef struct
{
	int x, y;
} Point;

char* point_print_coordinates(Point p, char* str);
char* point_print(Point p, char* str);

#endif /*POINT_H/*