
#include "../include/fdf.h"

void	scale(t_line *line, int scale_factor);
void	translate(t_line *line, int move_x, int move_y);

void	transform(t_view *view, t_line *line)
{
	scale(line, view->scale_factor);
	translate(line, view->move_x, view->move_y);
}

void	scale(t_line *line, int scale_factor)
{
	line->start.x *= scale_factor;
	line->start.y *= scale_factor;
	line->end.x *= scale_factor;
	line->end.y *= scale_factor;
}

void	translate(t_line *line, int move_x, int move_y)
{
	line->start.x += move_x;
	line->start.y += move_y;
	line->end.x += move_x;
	line->end.y += move_y;
}
