/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:29:57 by sdiabate          #+#    #+#             */
/*   Updated: 2023/08/19 01:30:14 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

static void	close_coordinates(t_point **coordinates, int width);

int	close_all_x(t_fdf *fdf)
{
	close_coordinates(fdf->map->coordinates, fdf->map->max_x);
	free(fdf->map);
	mlx_destroy_image(fdf->mlx_ptr, fdf->image->image);
	free(fdf->image);
	free(fdf->view);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_id);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	free(fdf);
	error(0);
	return (0);
}

void	close_all(t_fdf *fdf, int exit_code)
{
	close_coordinates(fdf->map->coordinates, fdf->map->max_x);
	free(fdf->map);
	mlx_destroy_image(fdf->mlx_ptr, fdf->image->image);
	free(fdf->image);
	free(fdf->view);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_id);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	free(fdf);
	error(exit_code);
}

void	close_map(t_fdf *fdf, int exit_code)
{
	close_coordinates(fdf->map->coordinates, fdf->map->max_x);
	free(fdf->map);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_id);
	mlx_destroy_display(fdf->mlx_ptr);
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
