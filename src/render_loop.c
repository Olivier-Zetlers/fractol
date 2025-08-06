/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozetlers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:22:48 by ozetlers          #+#    #+#             */
/*   Updated: 2025/08/06 20:22:50 by ozetlers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	render_full_image(t_app_ctx *app)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT)
			render_draw_pixel(app, x, y);
	}
	mlx_put_image_to_window(app->mlx, app->win, app->image.ptr, 0, 0);
}

int	render_loop(t_app_ctx *app)
{
	if (app->flag_redraw)
	{
		render_full_image(app);
		app->flag_redraw = 0;
	}
	return (0);
}
