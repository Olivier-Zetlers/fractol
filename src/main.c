#include "fractol.h"

static int	setup_mlx_hooks(t_app_ctx *app)
{
	mlx_loop_hook(app->mlx, &render_loop, app);
	mlx_hook(app->win, KEY_PRESS, KEY_PRESS_MASK, &keyboard_handle_event, app);
	mlx_hook(app->win, BUTTON_PRESS,
		BUTTON_PRESS_MASK, &mouse_handle_zoom, app);
	mlx_hook(app->win, DESTROY_NOTIFY, NO_EVENT_MASK, &app_close_and_exit, app);
	return (1);
}

int	main(int ac, char **av)
{
	t_app_ctx	app;

	bzero(&app, sizeof(t_app_ctx));
	if (!validate_cli_arguments(ac, av, &app))
		return (EXIT_FAILURE);
	if (!initialize_app_ctx(&app))
	{
		write(STDERR_FILENO, "Error: Failed to initialize MLX\n", 32);
		return (EXIT_FAILURE);
	}
	setup_mlx_hooks(&app);
	render_full_image(&app);
	mlx_loop(app.mlx);
	return (EXIT_SUCCESS);
}
