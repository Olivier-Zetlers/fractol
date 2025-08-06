#include "../inc/fractol.h"

static int	parse_fractal_type(const char *name, t_app_ctx *app);
static int	parse_julia_arguments(int argc, char *argv[], t_app_ctx *app);
static int	is_valid_double(const char *str);
static int	validate_julia_range(t_app_ctx *app);

int	validate_cli_arguments(int argc, char *argv[], t_app_ctx *app)
{
	if (argc < 2 || argc > 4)
	{
		print_usage_and_exit();
		return (0);
	}
	if (!parse_fractal_type(argv[1], app))
	{
		print_usage_and_exit();
		return (0);
	}
	if ((app->fractal_choice == 1 && argc != 2)
		|| (app->fractal_choice == 2
			&& (argc == 3
				|| (argc == 4 && !parse_julia_arguments(argc, argv, app)))))
	{
		print_usage_and_exit();
		return (0);
	}
	return (1);
}

static int	parse_fractal_type(const char *name, t_app_ctx *app)
{
	if (!name)
		return (0);
	if (!ft_strncmp(name, "mandelbrot", 11))
	{
		app->fractal_choice = 1;
		return (1);
	}
	if (!ft_strncmp(name, "julia", 6))
	{
		app->fractal_choice = 2;
		app->arg_r = DEFAULT_JULIA_R;
		app->arg_i = DEFAULT_JULIA_I;
		return (1);
	}
	return (0);
}

static int	parse_julia_arguments(int argc, char *argv[], t_app_ctx *app)
{
	int	err;

	err = 0;
	if (argc == 4)
	{
		if (!is_valid_double(argv[2]))
		{
			write(STDERR_FILENO, "Error: Invalid real parameter\n", 30);
			err = 1;
		}
		if (!is_valid_double(argv[3]))
		{
			write(STDERR_FILENO, "Error: Invalid imaginary parameter\n", 35);
			err = 1;
		}
		if (err == 1)
			return (0);
		app->arg_r = str_to_double(argv[2]);
		app->arg_i = str_to_double(argv[3]);
	}
	return (validate_julia_range(app));
}

/*
static int	parse_julia_arguments(int argc, char *argv[], t_app_ctx *app)
{
	if (argc == 4)
	{
		if (!is_valid_double(argv[3]))
		{
			write(STDERR_FILENO, "Error: Invalid imaginary parameter\n", 35);
			return (0);
		}
		app->arg_i = str_to_double(argv[3]);
	}
	return (validate_julia_range(app));
}
*/

static int	validate_julia_range(t_app_ctx *app)
{
	int	err;

	err = 0;
	if (app->arg_r < -2.0 || app->arg_r > 2.0)
	{
		write(STDERR_FILENO, "Error: Real part must be between -2 and 2\n", 43);
		err = 1;
	}
	if (app->arg_i < -2.0 || app->arg_i > 2.0)
	{
		write(STDERR_FILENO, "Error: Imag part must be between -2 and 2\n", 43);
		err = 1;
	}
	if (err == 1)
		return (0);
	return (1);
}

static int	is_valid_double(const char *str)
{
	int	has_digit;

	has_digit = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str != '.')
	{
		if (!ft_isdigit(*str))
			return (0);
		has_digit = 1;
		str++;
	}
	if (*str == '.')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		has_digit = 1;
		str++;
	}
	return (has_digit);
}
