#ifndef POINT_H
#define POINT_H

#include <stdio.h>

typedef struct
{
	int x, y;
} Point;

char* point_print_coordinates(const Point pt, char* str);
char* point_print(const Point pt, char* str);

#endif /*POINT_H/*
