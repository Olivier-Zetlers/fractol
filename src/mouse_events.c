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
	if (factor < 1.0)
		app->max_iter += 2;
	else if (app->max_iter > 30)
		app->max_iter -= 2;
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
