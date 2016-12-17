#include "Polygon.h"

char* polygon_print_coordinates(const Polygon pl, char* str)
{
  for(int i = 0; i < pl.size; ++i)
  {
    if(i > 0) str += sprintf(str, "), ");
    str += sprintf(str, ")");
    str = line-string_print_coordinates(pl.lstrings[i], str);
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
