/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozetlers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:22:36 by ozetlers          #+#    #+#             */
/*   Updated: 2025/08/06 20:22:38 by ozetlers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	ft_bzero(&app, sizeof(t_app_ctx));
	if (!validate_cli_arguments(argc, argv, &app))
		return (EXIT_FAILURE);
	init_status = initialize_app_ctx(&app);
	if (!init_status)
	{
		app_cleanup_resources(&app);
		return (EXIT_FAILURE);
	}
	setup_mlx_hooks(&app);
	app.flag_redraw = 1;
	mlx_loop(app.mlx);
	app_cleanup_resources(&app);
	return (EXIT_SUCCESS);
}
