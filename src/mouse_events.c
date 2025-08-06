/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozetlers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:21:49 by ozetlers          #+#    #+#             */
/*   Updated: 2025/08/06 20:21:51 by ozetlers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	mouse_apply_zoom(t_app_ctx *app, double factor)
{
	double	width;
	double	height;

	width = (app->max_r - app->min_r) * factor;
	height = (app->max_i - app->min_i) * factor;
	app->min_r += width;
	app->max_r -= width;
	app->min_i += height;
	app->max_i -= height;
	if (factor > 0)
		app->max_iter += ITER_ZOOM_STEP;
	else if (factor < 0 && app->max_iter > 30)
		app->max_iter -= ITER_ZOOM_STEP;
}

int	mouse_handle_zoom(int button, int x, int y, t_app_ctx *app)
{
	(void) x;
	(void) y;
	app->flag_redraw = 1;
	if (button == MOUSE_SCROLL_UP)
		mouse_apply_zoom(app, 0.1);
	else if (button == MOUSE_SCROLL_DOWN)
		mouse_apply_zoom(app, -0.1);
	return (0);
}
