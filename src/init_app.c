#include "../inc/fractol.h"

static void	initialize_viewport(t_app_ctx *app);

/* This function now ONLY handles initialization. All cleanup is
   delegated to the caller through the unified cleanup function. */
int	initialize_app_ctx(t_app_ctx *app)
{
	/* Initialize MLX library */
	app->mlx = mlx_init();
	if (!app->mlx)
	{
		write(STDERR_FILENO, "Error: Cannot initialize MLX (check DISPLAY)\n", 45);
		return (0);
	}
	
	/* Create window */
	app->win = mlx_new_window(app->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	if (!app->win)
	{
		write(STDERR_FILENO, "Error: Cannot create window\n", 28);
		return (0);  /* Caller will handle cleanup */
	}
	
	/* Create image buffer */
	app->image.ptr = mlx_new_image(app->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!app->image.ptr)
	{
		write(STDERR_FILENO, "Error: Cannot create image buffer\n", 34);
		return (0);  /* Caller will handle cleanup */
	}
	
	/* Get image data address */
	app->image.addr = mlx_get_data_addr(app->image.ptr, &app->image.bpp,
			&app->image.line_size, &app->image.endian);
	if (!app->image.addr)
	{
		write(STDERR_FILENO, "Error: Cannot access image memory\n", 34);
		return (0);  /* Caller will handle cleanup */
	}
	
	/* Validate image parameters */
	if (app->image.bpp <= 0 || app->image.line_size <= 0)
	{
		write(STDERR_FILENO, "Error: Invalid image parameters\n", 32);
		return (0);  /* Caller will handle cleanup */
	}
	
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



/* BACKUP
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

*/
