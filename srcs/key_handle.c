
#include "../include/fdf.h"

static void	key_translate(int keycode, t_fdf *fdf);
static void	key_scale(int keycode, t_fdf *fdf);
static void	key_rotate(int keycode, t_fdf *fdf);
static void	key_project(int keycode, t_fdf *fdf);

int	key_handle(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		close_all(fdf, 0);
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT || keycode == KEY_UP \
		|| keycode == KEY_DOWN)
		key_translate(keycode, fdf);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS || keycode == KEY_Z \
		|| keycode == KEY_X )
		key_scale(keycode, fdf);
	else if (keycode == KEY_A || keycode == KEY_S || keycode == KEY_D \
		|| keycode == KEY_Q || keycode == KEY_W || keycode == KEY_E)
		key_rotate(keycode, fdf);
	else if (keycode == KEY_P || keycode == KEY_I || keycode == KEY_T)
		key_project(keycode, fdf);
	else if (keycode == KEY_C)
	{
		if (fdf->view->color_pallet == FALSE)
			fdf->view->color_pallet = TRUE;
		else
			fdf->view->color_pallet = FALSE;
	}
	else if (keycode == KEY_R)
		reset(fdf);
	render(fdf);
	return (0);
}

static void	key_translate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_RIGHT)
		fdf->view->move_x += 10;
	else if (keycode == KEY_LEFT)
		fdf->view->move_x -= 10;
	else if (keycode == KEY_DOWN)
		fdf->view->move_y += 10;
	else if (keycode == KEY_UP)
		fdf->view->move_y -= 10;
}

static void	key_scale(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PLUS)
		fdf->view->scale_factor += 1;
	else if (keycode == KEY_MINUS)
		fdf->view->scale_factor -= 1;
	else if (keycode == KEY_Z && fdf->view->scale_z > -1)
		fdf->view->scale_z -= 0.1;
	else if (keycode == KEY_X && fdf->view->scale_z < 1)
		fdf->view->scale_z += 0.1;
}

static void	key_rotate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_S)
		fdf->view->alpha -= (5 * ANG_1);
	else if (keycode == KEY_W)
		fdf->view->alpha += (5 * ANG_1);
	else if (keycode == KEY_A)
		fdf->view->gamma -= (5 * ANG_1);
	else if (keycode == KEY_D)
		fdf->view->gamma += (5 * ANG_1);
	else if (keycode == KEY_Q)
		fdf->view->beta -= (5 * ANG_1);
	else if (keycode == KEY_E)
		fdf->view->beta += (5 * ANG_1);
}

static void	key_project(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_P)
		fdf->view->projection = PERSPECTIVE;
	else if (keycode == KEY_I)
		fdf->view->projection = ISOMETRIC;
	else if (keycode == KEY_T)
		fdf->view->projection = TOP;
}
