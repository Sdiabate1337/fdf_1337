
#include "../include/fdf.h"

t_fdf	*init_fdf(char *file_name)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		error(3);
	fdf->map = read_map(file_name);
	if (!fdf->map)
	{
		free(fdf);
		error(4);
	}
	fdf->mlx_ptr = mlx_init();
	fdf->win_x = WINDOW_WIDTH;
	fdf->win_y = WINDOW_HEIGHT;
	fdf->win_id = mlx_new_window(fdf->mlx_ptr, fdf->win_x, fdf->win_y, WINDOW_NAME);
	fdf->image = init_image(fdf->mlx_ptr);
	if (!fdf->image)
		close_map(fdf, 5);
	fdf->view = init_view(fdf->map);
	if (!fdf->view)
		close_all(fdf, 6);
	return (fdf);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->coordinates = NULL;
	map->max_x = 0;
	map->max_y = 0;
	map->max_z = 0;
	map->min_z = 0;
	return (map);
}

t_image	*init_image(void *mlx_ptr)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->image = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	image->buffer = mlx_get_data_addr(image->image, &image->pixel_bits, \
			&image->line_bytes, &image->endian);
	image->line = NULL;
	return (image);
}

t_view	*init_view(t_map *map)
{
	t_view	*view;

	view = malloc(sizeof(t_view));
	if (!view)
		return (NULL);
	view->projection = ISOMETRIC;
	view->color_pallet = FALSE;
	view->scale_factor = scale_to_fit(map);
	view->scale_z = 1;
	view->move_x = WINDOW_WIDTH / 2;
	view->move_y = WINDOW_HEIGHT / 2;
	view->alpha = 0;
	view->beta = 0;
	view->gamma = 0;
	return (view);
}

t_line	*init_line(t_point start, t_point end, t_fdf *fdf)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->start.x = start.x;
	line->start.y = start.y;
	line->start.z = start.z;
	line->start.color = start.color;
	line->end.x = end.x;
	line->end.y = end.y;
	line->end.z = end.z;
	line->end.color = end.color;
	line->transform_z = max((fdf->map->max_z - fdf->map->min_z), \
		max(fdf->map->max_x, fdf->map->max_y));
	return (line);
}
