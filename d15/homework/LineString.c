#include "LineString.h"

char* line_string_print_coordinates(const LineString ls, char* str)
{
  for(int i = 0; i < ls.size; ++i)
  {
    if(i > 0) str += sprintf(str, ", ");
    str = point_print_coordinates(ls.points[i], str);
  }
	return str;
}
	
char* line_string_print(const LineString ls, char* str)
{
	str += sprintf(str, "LINESTRING (");
	str = line_string_print_coordinates(p, str);
	return str + sprintf(str, ")");
}

void line_string_add_point(LineString *ls, const Point pt)
{
  if(ls->size == LS_MAX_POINTS) return ;
  ls->points[ls->size++] = {pt.x, pt.y};
}
