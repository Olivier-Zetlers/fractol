#include "../inc/fractol.h"

int	keyboard_handle_event(int keycode, t_app_ctx *app)
{
	app->flag_redraw = 1;
	if (keycode == KEY_ESCAPE)
		app_close_and_exit(app);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT
		|| keycode == KEY_UP || keycode == KEY_DOWN)
		keyboard_handle_navigation(keycode, app);
	else if (keycode == 'z' || keycode == 'x' || keycode == 'r')
		keyboard_handle_view_controls(keycode, app);
	else if (keycode == 'q' || keycode == 'w'
		|| keycode == 'a' || keycode == 's')
		keyboard_handle_julia_params(keycode, app);
	else if (keycode == 'i' || keycode == 'o')
		keyboard_handle_iterations(keycode, app);
	return (0);
}

void	keyboard_handle_navigation(int keycode, t_app_ctx *app)
{
	double	delta;

	if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
	{
		delta = (app->max_r - app->min_r) * PAN_FACTOR;
		if (keycode == KEY_RIGHT)
			;
		else
			delta = -delta;
		app->max_r += delta;
		app->min_r += delta;
	}
	else
	{
		delta = (app->max_i - app->min_i) * PAN_FACTOR;
		if (keycode == KEY_DOWN)
			;
		else
			delta = -delta;
		app->max_i += delta;
		app->min_i += delta;
	}
}

void	keyboard_handle_view_controls(int keycode, t_app_ctx *app)
{
	double	zoom_r;
	double	zoom_i;

	if (keycode == 'r')
	{
		app->min_r = DEFAULT_MIN_R;
		app->max_r = DEFAULT_MAX_R;
		app->min_i = DEFAULT_MIN_I;
		app->max_i = DEFAULT_MAX_I;
		app->max_iter = DEFAULT_MAX_ITER;
		return ;
	}
	zoom_r = (app->max_r - app->min_r) * ZOOM_FACTOR;
	zoom_i = (app->max_i - app->min_i) * ZOOM_FACTOR;
	if (keycode == 'z')
	{
		app->min_r += zoom_r;
		app->max_r -= zoom_r;
		app->min_i += zoom_i;
		app->max_i -= zoom_i;
		app->max_iter += ITER_ZOOM_STEP;
	}
	else if (keycode == 'x' && app->max_iter > 30)
		keyboard_handle_zoom_out(app, zoom_r, zoom_i);
}

void	keyboard_handle_julia_params(int keycode, t_app_ctx *app)
{
	if (app->fractal_choice != 2)
		return ;
	if (keycode == 'q')
		app->arg_r -= JULIA_PARAM_STEP;
	else if (keycode == 'w')
		app->arg_r += JULIA_PARAM_STEP;
	else if (keycode == 'a')
		app->arg_i -= JULIA_PARAM_STEP;
	else if (keycode == 's')
		app->arg_i += JULIA_PARAM_STEP;
}

void	keyboard_handle_iterations(int keycode, t_app_ctx *app)
{
	if (keycode == 'i' && app->max_iter < MAX_ITER_LIMIT)
		app->max_iter += ITER_MANUAL_STEP;
	else if (keycode == 'o' && app->max_iter > MIN_ITER_LIMIT)
		app->max_iter -= ITER_MANUAL_STEP;
}
