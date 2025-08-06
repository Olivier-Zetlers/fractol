/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozetlers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:20:32 by ozetlers          #+#    #+#             */
/*   Updated: 2025/08/06 20:20:34 by ozetlers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	app_cleanup_resources(t_app_ctx *app)
{
	if (app->image.ptr)
	{
		mlx_destroy_image(app->mlx, app->image.ptr);
		app->image.ptr = NULL;
	}
	if (app->win)
	{
		mlx_destroy_window(app->mlx, app->win);
		app->win = NULL;
	}
	if (app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free(app->mlx);
		app->mlx = NULL;
	}
}

int	app_close_and_exit(t_app_ctx *app)
{
	app_cleanup_resources(app);
	exit(EXIT_SUCCESS);
	return (1);
}
