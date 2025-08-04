#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <minilibx-linux/mlx.h>
# include <ctype.h> // DELETE WHEN REPLACING isdigit by ft_isdigit
# include <string.h> // DELETE WHEN REPLACING strcmpt by ft_strcmp

/* ---------- X11 event types ---------- */
/* These values are standard X11 event type codes */
# define KEY_PRESS        2
# define BUTTON_PRESS     4
# define DESTROY_NOTIFY   17

/* ---------- X11 event masks ---------- */
/* These determine which events we want to receive */
# define KEY_PRESS_MASK   1L
# define BUTTON_PRESS_MASK 4L
# define NO_EVENT_MASK    0L

/* ---------- X11 key codes ---------- */
/* Standard keyboard key codes for Linux X11 */
# define KEY_ESCAPE       65307
# define KEY_LEFT         65361
# define KEY_RIGHT        65363
# define KEY_UP           65362
# define KEY_DOWN         65364

/* ---------- Mouse button codes ---------- */
/* Standard mouse button codes */
# define MOUSE_SCROLL_UP   4
# define MOUSE_SCROLL_DOWN 5

/* ---------- constants ---------- */
# define WIN_WIDTH      800
# define WIN_HEIGHT     600

/* Default viewport boundaries */
# define DEFAULT_MIN_R  -2.0
# define DEFAULT_MAX_R  2.0
# define DEFAULT_MIN_I  -1.5
# define DEFAULT_MAX_I  1.5
# define DEFAULT_MAX_ITER 50

/* Default Julia set parameters */
# define DEFAULT_JULIA_R -0.8
# define DEFAULT_JULIA_I 0.156

/* Interaction constants */
# define PAN_FACTOR     0.1
# define ZOOM_FACTOR    0.1
# define ITER_ZOOM_STEP 2
# define ITER_MANUAL_STEP 10
# define JULIA_PARAM_STEP 0.01

/* Iteration limits */
# define MIN_ITER_LIMIT 10
# define MAX_ITER_LIMIT 500

/* ---------- custom types ---------- */
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
}	t_app_ctx;

int		initialize_app_ctx(t_app_ctx *app);
int		validate_cli_arguments(int ac, char **av, t_app_ctx *app);
int		render_loop(t_app_ctx *app);
void	render_full_image(t_app_ctx *app);
void	render_draw_pixel(t_app_ctx *app, int x, int y);
int		psychedelic_palette(int iteration, int max_iteration);
int		keyboard_handle_event(int keycode, t_app_ctx *app);
int		mouse_handle_zoom(int button, int x, int y, t_app_ctx *app);
double	str_to_double(const char *str);
void	print_usage_and_exit(void);
int		app_close_and_exit(t_app_ctx *app);
void	keyboard_handle_zoom_out(t_app_ctx *app, double zoom_r, double zoom_i);
void	keyboard_handle_navigation(int keycode, t_app_ctx *app);
void	keyboard_handle_view_controls(int keycode, t_app_ctx *app);
void	keyboard_handle_julia_params(int keycode, t_app_ctx *app);
void	keyboard_handle_iterations(int keycode, t_app_ctx *app);
int		keyboard_handle_event(int keycode, t_app_ctx *app);
int		app_close_and_exit(t_app_ctx *app);
#endif
