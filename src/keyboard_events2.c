#include "fractol.h"

void	keyboard_handle_zoom_out(t_app_ctx *app, double zoom_r, double zoom_i)
{
	app->min_r -= zoom_r;
	app->max_r += zoom_r;
	app->min_i -= zoom_i;
	app->max_i += zoom_i;
	app->max_iter -= ITER_ZOOM_STEP;
}
