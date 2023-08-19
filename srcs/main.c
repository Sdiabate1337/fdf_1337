/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:32:20 by sdiabate          #+#    #+#             */
/*   Updated: 2023/08/19 01:32:26 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

static int	expose_handle(t_fdf *fdf);

int	main(int argc, char **argv)
{
	char	*file_name;
	t_fdf	*fdf;

	if (argc != 2)
		error(1);
	file_name = argv[1];
	fdf = init_fdf(file_name);
	render(fdf);
	mlx_key_hook(fdf->win_id, &key_handle, fdf);
	mlx_hook(fdf->win_id, 17, 1L << 0, close_all_x, fdf);
	mlx_expose_hook(fdf->win_id, &expose_handle, fdf);
	mlx_loop(fdf->mlx_ptr);
}

static int	expose_handle(t_fdf *fdf)
{
	render(fdf);
	return (0);
}
