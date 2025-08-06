/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_calculations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozetlers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:22:14 by ozetlers          #+#    #+#             */
/*   Updated: 2025/08/06 20:22:17 by ozetlers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	image_set_pixel(t_image_buf *buf, int x, int y, int color)
{
	uint32_t	color_val;
	char		*pixel;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	pixel = buf->addr + (y * buf->line_size + x * (buf->bpp / 8));
	color_val = (uint32_t) color;
	ft_memcpy(pixel, &color_val, sizeof(color_val));
}

static int	iterate_julia_set(double x, double y, t_app_ctx *app)
{
	double	zr;
	double	zi;
	double	tmp;
	int		iteration;

	zr = -x;
	zi = y;
	iteration = 0;
	while (iteration < app->max_iter)
	{
		tmp = 2.0 * zr * zi + app->arg_i;
		zr = zr * zr - zi * zi + app->arg_r;
		zi = tmp;
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		iteration++;
	}
	return (iteration);
}

static int	iterate_mandelbrot_set(double x, double y, t_app_ctx *app)
{
	double	zr;
	double	zi;
	double	tmp;
	int		iteration;

	zr = 0.0;
	zi = 0.0;
	iteration = 0;
	while (iteration < app->max_iter)
	{
		tmp = 2.0 * zr * zi + y;
		zr = zr * zr - zi * zi + x;
		zi = tmp;
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		iteration++;
	}
	return (iteration);
}

void	render_draw_pixel(t_app_ctx *app, int x, int y)
{
	double	map_r;
	double	map_i;
	int		iteration;

	map_r = app->min_r + ((double)x * (app->max_r - app->min_r)) / WIN_WIDTH;
	map_i = app->max_i - ((double)y * (app->max_i - app->min_i)) / WIN_HEIGHT;
	if (app->fractal_choice == 1)
		iteration = iterate_mandelbrot_set(map_r, map_i, app);
	else
		iteration = iterate_julia_set(map_r, map_i, app);
	if (iteration == app->max_iter)
		image_set_pixel(&app->image, x, y, 0x000000);
	else
		image_set_pixel(&app->image, x, y,
			psychedelic_palette(iteration, app->max_iter));
}
