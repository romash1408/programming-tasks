#include "LineString.h"

char* line_string_print_coordinates(const LineString ls, char* str)
{
	if(!ls.size) return str;
	point_print_coordinates(ls.points[0], str);
	for(int i = 1; i < ls.size; ++i)
	{
		str += sprintf(str, ", ");
		str = point_print_coordinates(ls.points[i], str);
	}
	return str;
}
	
char* line_string_print(const LineString ls, char* str)
{
	str += sprintf(str, "LINESTRING (");
	str = line_string_print_coordinates(ls, str);
	return str + sprintf(str, ")");
}

void line_string_add_point(LineString *ls, const Point pt)
{
  if(ls->size == LS_MAX_POINTS) return ;
  ls->points[ls->size++] = (Point){pt.x, pt.y};
}
