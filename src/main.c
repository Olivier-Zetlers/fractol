#include "../inc/fractol.h"

static void	setup_mlx_hooks(t_app_ctx *app)
{
	mlx_loop_hook(app->mlx, &render_loop, app);
	mlx_hook(app->win, KEY_PRESS, KEY_PRESS_MASK, &keyboard_handle_event, app);
	mlx_hook(app->win, BUTTON_PRESS,
		BUTTON_PRESS_MASK, &mouse_handle_zoom, app);
	mlx_hook(app->win, DESTROY_NOTIFY, NO_EVENT_MASK, &app_close_and_exit, app);
}

int	main(int argc, char *argv[])
{
	t_app_ctx	app;
	int			init_status;

	/* Zero the entire structure - this ensures all pointers are NULL,
	   which makes our cleanup function safe to call at any point */
	ft_bzero(&app, sizeof(t_app_ctx));
	
	/* Validate arguments first - no resources allocated yet */
	if (!validate_cli_arguments(argc, argv, &app))
		return (EXIT_FAILURE);
	
	/* Attempt initialization */
	init_status = initialize_app_ctx(&app);
	if (!init_status)
	{
		/* CRITICAL: Clean up any partially initialized resources */
		app_cleanup_resources(&app);
		return (EXIT_FAILURE);
	}
	
	/* If we get here, initialization was successful */
	setup_mlx_hooks(&app);
	app.flag_redraw = 1;
	
	/* Enter the event loop - this only returns when the program ends */
	mlx_loop(app.mlx);
	
	/* In theory, we never reach here because mlx_loop doesn't return,
	   but if it did, we should clean up */
	app_cleanup_resources(&app);
	return (EXIT_SUCCESS);
}



/* BACKUP
static void	setup_mlx_hooks(t_app_ctx *app)
{
	mlx_loop_hook(app->mlx, &render_loop, app);
	mlx_hook(app->win, KEY_PRESS, KEY_PRESS_MASK, &keyboard_handle_event, app);
	mlx_hook(app->win, BUTTON_PRESS,
		BUTTON_PRESS_MASK, &mouse_handle_zoom, app);
	mlx_hook(app->win, DESTROY_NOTIFY, NO_EVENT_MASK, &app_close_and_exit, app);
}

int	main(int argc, char *argv[])
{
	t_app_ctx	app;

	ft_bzero(&app, sizeof(t_app_ctx));
	if (!validate_cli_arguments(argc, argv, &app))
		return (EXIT_FAILURE);
	if (!initialize_app_ctx(&app))
	{
		write(STDERR_FILENO, "Error: Failed to initialize MLX\n", 32);
		return (EXIT_FAILURE);
	}
	setup_mlx_hooks(&app);
	app.flag_redraw = 1;
	mlx_loop(app.mlx);
	return (EXIT_SUCCESS);
}
*/
