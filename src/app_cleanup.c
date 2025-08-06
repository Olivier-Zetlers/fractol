#include "../inc/fractol.h"

int	app_close_and_exit(t_app_ctx *app)
{
	int	f_linux;

	if (app->image.ptr)
		mlx_destroy_image(app->mlx, app->image.ptr);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
	f_linux = F_FLAG;
	if (f_linux && app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free(app->mlx);
	}
	exit(EXIT_SUCCESS);
	return (1);
}
