#include "../inc/fractol.h"

static void	initialize_viewport(t_app_ctx *app);

int	initialize_app_ctx(t_app_ctx *app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		return (0);
	app->win = mlx_new_window(app->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	if (!app->win)
		return (0);
	app->image.ptr = mlx_new_image(app->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!app->image.ptr)
		return (0);
	app->image.addr = mlx_get_data_addr(app->image.ptr, &app->image.bpp,
			&app->image.line_size, &app->image.endian);
	initialize_viewport(app);
	return (1);
}

static void	initialize_viewport(t_app_ctx *app)
{
	app->min_r = -2.0;
	app->max_r = 2.0;
	app->min_i = -1.5;
	app->max_i = 1.5;
	app->max_iter = 50;
}
