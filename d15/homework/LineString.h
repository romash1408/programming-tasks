#ifndef LINESTRING_H
#define LINESTRING_H

#include <stdio.h>
#include "Point.h"

enum
{
	LS_MAX_POINTS = 100
};

typedef struct
{
	int size;
	Point points[LS_MAX_POINTS];
} LineString;

char* line_string_print_coordinates(const LineString ls, char* str);

char* line_string_print(const LineString ls, char* str);

void line_string_add_point(LineString *ls, const Point pt);

#endif /*LINESTRING_H*/
