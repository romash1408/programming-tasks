#include <stdio.h>
#include "Point.h"

char* point_print_coordinates(const Point p, char* str)
{
	return str + sprintf(str, "%d, %d", p.x, p.y);
}
	
char* point_print(const Point p, char* str)
{
	str += sprintf(str, "Point (");
	str = point_print_coordinates(p, str);
	return str + sprintf(str, ")");
}