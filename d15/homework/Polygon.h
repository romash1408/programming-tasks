#ifndef POLYGON_H
#define POLYGON_H

#include <stdio.h>
#include "LineString.h"

static const PL_MAX_LSTRINGS = 10;

typedef struct
{
	int size;
	LineString lstrings[PL_MAX_LSTRINGS];
} Polygon;

char* polygon_print_coordinates(const Polygon pl, char* str);

char* polygon_print(const Polygon pl, char* str);

void polygon_add_line_string(Polygon *pl, const LineString ls);

#endif LINESTRING_H
