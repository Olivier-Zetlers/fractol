#include "../inc/fractol.h"

/* This function is now responsible for ALL cleanup, regardless of 
   how far initialization proceeded. It must be safe to call at any
   point, even with partially initialized structures. */
void	app_cleanup_resources(t_app_ctx *app)
{
	/* Check each resource individually - any of them might be NULL
	   if initialization failed partway through */
	
	if (app->image.ptr)
	{
		/* Only destroy the image if it was created */
		mlx_destroy_image(app->mlx, app->image.ptr);
		app->image.ptr = NULL;  /* Prevent double-free */
	}
	
	if (app->win)
	{
		/* Only destroy window if it exists */
		mlx_destroy_window(app->mlx, app->win);
		app->win = NULL;
	}
	
	if (app->mlx)
	{
		/* Clean up the MLX context last, as other resources depend on it */
		mlx_destroy_display(app->mlx);
		free(app->mlx);
		app->mlx = NULL;
	}
}

/* Separate function for cleanup + exit, used by event handlers */
int	app_close_and_exit(t_app_ctx *app)
{
	app_cleanup_resources(app);
	exit(EXIT_SUCCESS);
	return (1);
}

/* BACKUP
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
*/
