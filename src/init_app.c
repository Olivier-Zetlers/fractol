/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozetlers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:16:53 by ozetlers          #+#    #+#             */
/*   Updated: 2025/08/06 20:25:04 by ozetlers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	initialize_viewport(t_app_ctx *app);

///////////////////////////////////////////

static int	initialize_mlx_context(t_app_ctx *app);
static int	create_window_and_image(t_app_ctx *app);
static int	setup_image_buffer(t_app_ctx *app);

/* Main initialization function - now just orchestrates the process */
int	initialize_app_ctx(t_app_ctx *app)
{
	if (!initialize_mlx_context(app))
		return (0);
	if (!create_window_and_image(app))
		return (0);
	if (!setup_image_buffer(app))
		return (0);
	initialize_viewport(app);
	return (1);
}

static int	initialize_mlx_context(t_app_ctx *app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
	{
		write(STDERR_FILENO,
			"Error: Cannot initialize MLX (check DISPLAY)\n", 45);
		return (0);
	}
	return (1);
}

static int	create_window_and_image(t_app_ctx *app)
{
	app->win = mlx_new_window(app->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	if (!app->win)
	{
		write(STDERR_FILENO, "Error: Cannot create window\n", 28);
		return (0);
	}
	app->image.ptr = mlx_new_image(app->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!app->image.ptr)
	{
		write(STDERR_FILENO, "Error: Cannot create image buffer\n", 34);
		return (0);
	}
	return (1);
}

static int	setup_image_buffer(t_app_ctx *app)
{
	app->image.addr = mlx_get_data_addr(app->image.ptr, &app->image.bpp,
			&app->image.line_size, &app->image.endian);
	if (!app->image.addr)
	{
		write(STDERR_FILENO, "Error: Cannot access image memory\n", 34);
		return (0);
	}
	if (app->image.bpp <= 0 || app->image.line_size <= 0)
	{
		write(STDERR_FILENO, "Error: Invalid image parameters\n", 32);
		return (0);
	}
	return (1);
}

/*
int	initialize_app_ctx(t_app_ctx *app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
	{
		write(STDERR_FILENO,
			       "Error: Cannot initialize MLX (check DISPLAY)\n", 45);
		return (0);
	}
	app->win = mlx_new_window(app->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	if (!app->win)
	{
		write(STDERR_FILENO, "Error: Cannot create window\n", 28);
		return (0);
	}
	app->image.ptr = mlx_new_image(app->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!app->image.ptr)
	{
		write(STDERR_FILENO, "Error: Cannot create image buffer\n", 34);
		return (0);
	}
	app->image.addr = mlx_get_data_addr(app->image.ptr, &app->image.bpp,
			&app->image.line_size, &app->image.endian);
	if (!app->image.addr)
	{
		write(STDERR_FILENO, "Error: Cannot access image memory\n", 34);
		return (0);
	}
	if (app->image.bpp <= 0 || app->image.line_size <= 0)
	{
		write(STDERR_FILENO, "Error: Invalid image parameters\n", 32);
		return (0);
	}
	initialize_viewport(app);
	return (1);
}
*/
static void	initialize_viewport(t_app_ctx *app)
{
	app->min_r = -2.0;
	app->max_r = 2.0;
	app->min_i = -1.5;
	app->max_i = 1.5;
	app->max_iter = 50;
}
