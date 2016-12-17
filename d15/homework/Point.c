#include <stdio.h>
#include "Point.h"

char* point_print_coordinates(const Point pt, char* str)
{
	return str + sprintf(str, "%d %d", pt.x, pt.y);
}
	
char* point_print(const Point pt, char* str)
{
	str += sprintf(str, "Point (");
	str = point_print_coordinates(pt, str);
	return str + sprintf(str, ")");
}
