/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozetlers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:24:09 by ozetlers          #+#    #+#             */
/*   Updated: 2025/08/06 20:16:31 by ozetlers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define BUTTON_PRESS		4
# define DESTROY_NOTIFY		17
# define KEY_PRESS		2

# define BUTTON_PRESS_MASK	4L
# define KEY_PRESS_MASK		1L
# define NO_EVENT_MASK		0L

# ifdef __APPLE__
#  define KEY_DOWN		126
#  define KEY_ESCAPE		53
#  define KEY_LEFT		123
#  define KEY_RIGHT		124
#  define KEY_UP		125
#  define F_FLAG		0
# else
#  define KEY_DOWN		65362
#  define KEY_ESCAPE		65307
#  define KEY_LEFT		65361
#  define KEY_RIGHT		65363
#  define KEY_UP		65364
#  define F_FLAG		1
# endif

# define MOUSE_SCROLL_DOWN	5
# define MOUSE_SCROLL_UP	4

# define WIN_HEIGHT		600
# define WIN_WIDTH		800

# define DEFAULT_MAX_ITER	50
# define DEFAULT_MAX_R		2.0
# define DEFAULT_MIN_R		-2.0
# define DEFAULT_MAX_I		1.5
# define DEFAULT_MIN_I		-1.5

# define DEFAULT_JULIA_I	0.156
# define DEFAULT_JULIA_R	-0.8

# define ITER_MANUAL_STEP	10
# define ITER_ZOOM_STEP		2
# define JULIA_PARAM_STEP	0.01
# define PAN_FACTOR		0.1
# define ZOOM_FACTOR		0.1

# define MAX_ITER_LIMIT		500
# define MIN_ITER_LIMIT		10

typedef struct s_image_buf
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_size;
	int		endian;
}	t_image_buf;

typedef struct s_app_ctx
{
	void		*mlx;
	void		*win;
	t_image_buf	image;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		arg_r;
	double		arg_i;
	int			max_iter;
	int			fractal_choice;
	int			flag_redraw;
}	t_app_ctx;

void	app_cleanup_resources(t_app_ctx *app);
int		app_close_and_exit(t_app_ctx *app);
int		initialize_app_ctx(t_app_ctx *app);
int		keyboard_handle_event(int keycode, t_app_ctx *app);
void	keyboard_handle_iterations(int keycode, t_app_ctx *app);
void	keyboard_handle_julia_params(int keycode, t_app_ctx *app);
void	keyboard_handle_navigation(int keycode, t_app_ctx *app);
void	keyboard_handle_view_controls(int keycode, t_app_ctx *app);
void	keyboard_handle_zoom_out(t_app_ctx *app, double zoom_r, double zoom_i);
int		mouse_handle_zoom(int button, int x, int y, t_app_ctx *app);
void	print_usage_and_exit(void);
void	render_draw_pixel(t_app_ctx *app, int x, int y);
void	render_full_image(t_app_ctx *app);
int		render_loop(t_app_ctx *app);
double	str_to_double(const char *str);
int		psychedelic_palette(int iteration, int max_iteration);
int		validate_cli_arguments(int argc, char *argv[], t_app_ctx *app);

#endif
