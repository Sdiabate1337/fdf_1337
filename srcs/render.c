/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:34:52 by sdiabate          #+#    #+#             */
/*   Updated: 2023/08/19 01:34:57 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

static void	render_line(t_fdf *fdf, t_point start, t_point end);
static void	apply_colors(t_fdf *fdf, t_point *point);

void	render(t_fdf *fdf)
{
	int	x;
	int	y;

	clear_image(fdf->image, MAX_PIXEL * 4);
	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			if (x < fdf->map->max_x - 1)
				render_line(fdf, fdf->map->coordinates[x][y], \
					fdf->map->coordinates[x + 1][y]);
			if (y < fdf->map->max_y - 1)
				render_line(fdf, fdf->map->coordinates[x][y], \
					fdf->map->coordinates[x][y + 1]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_id, fdf->image->image, 0, 0);
	print_menu(fdf);
}

static void	render_line(t_fdf *fdf, t_point start, t_point end)
{
	start.z *= fdf->view->scale_z;
	end.z *= fdf->view->scale_z;
	apply_colors(fdf, &start);
	apply_colors(fdf, &end);
	fdf->image->line = init_line(start, end, fdf);
	if (!fdf->image->line)
		close_all(fdf, 7);
	rotate(fdf->view, fdf->image->line);
	project(fdf->view, fdf->image->line);
	transform(fdf->view, fdf->image->line);
	bresenham(fdf, fdf->image->line->start, fdf->image->line->end);
	free(fdf->image->line);
}

static void	apply_colors(t_fdf *fdf, t_point *point)
{
	t_color	*col;

	col = NULL;
	if (fdf->view->color_pallet == FALSE)
	{
		if (point->color == -1)
			point->color = LINE_DEFAULT;
	}
	else
	{
		if (point->z >= 0)
		{
			col = color_pallet_init(C_GREY, C_ORANGY);
			point->color = get_color(col, absolute(point->z), \
				absolute(fdf->map->max_z));
			free(col);
		}
		else
		{
			col = color_pallet_init(C_GREY, C_BLUEY);
			point->color = get_color(col, absolute(point->z), \
				absolute(fdf->map->max_z));
			free(col);
		}
	}
}
