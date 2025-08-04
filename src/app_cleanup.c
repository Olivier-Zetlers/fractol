#include "fractol.h"

int	app_close_and_exit(t_app_ctx *app)
{
	if (app->image.ptr)
		mlx_destroy_image(app->mlx, app->image.ptr);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
	if (app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free(app->mlx);
	}
	exit(EXIT_SUCCESS);
}
