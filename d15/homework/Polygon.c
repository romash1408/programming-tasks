#include "Polygon.h"

char* polygon_print_coordinates(const Polygon pl, char* str)
{
	if(!pl.size) return str;
	str = line_string_print_coordinates(pl.lstrings[0], str);
	for(int i = 1; i < pl.size; ++i)
	{
		str += sprintf(str, "), (");
		str = line_string_print_coordinates(pl.lstrings[i], str);
	}
	return str;
}
	
char* polygon_print(const Polygon pl, char* str)
{
	str += sprintf(str, "POLYGON (");
	str = polygon_print_coordinates(pl, str);
	return str + sprintf(str, ")");
}

void polygon_add_line_string(Polygon *pl, const LineString ls)
{
	if(pl->size == PL_MAX_LSTRINGS) return ;
	LineString *cp = &pl->lstrings[pl->size++];
	for(int i = 0; i < ls.size; ++i)
	{
		line_string_add_point(cp, ls.points[i]);
	}
}
