
#include "../include/fdf.h"

static void	close_coordinates(t_point **coordinates, int width);

void	close_all(t_fdf *fdf, int exit_code)
{
	close_coordinates(fdf->map->coordinates, fdf->map->max_x);
	free(fdf->map);
	mlx_destroy_image(fdf->mlx_ptr, fdf->image->image);
	free(fdf->image);
	free(fdf->view);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_id);
	//mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	free(fdf);
	error(exit_code);
}

void	close_map(t_fdf *fdf, int exit_code)
{
	close_coordinates(fdf->map->coordinates, fdf->map->max_x);
	free(fdf->map);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_id);
	//mlx_ptr_destroy_display(fdf->mlx_ptr);
	free(fdf);
	error(exit_code);
}

static void	close_coordinates(t_point **coordinates, int width)
{
	int		i;

	i = 0;
	while (i < width)
	{
		free(coordinates[i]);
		i++;
	}
	free(coordinates);
}
