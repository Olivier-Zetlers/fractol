#include "fractol.h"

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
	render_full_image(app);
	return (0);
}
