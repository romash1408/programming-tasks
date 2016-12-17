#ifndef POINT_H
#define POINT_H

#include <stdio.h>

typedef struct
{
	int x, y;
} Point;

char* point_print_coordinates(Point pt, char* str);
char* point_print(Point pt, char* str);

#endif /*POINT_H/*
