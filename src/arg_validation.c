#include "fractol.h"

static int	parse_fractal_type(const char *name, t_app_ctx *app);
static int	parse_julia_arguments(int ac, char **av, t_app_ctx *app);
static int	validate_julia_range(t_app_ctx *app);
static int	is_valid_double(const char *str);

int	validate_cli_arguments(int ac, char **av, t_app_ctx *app)
{
	if (ac < 2 || ac > 4)
	{
		print_usage_and_exit();
		return (0);
	}
	if (!parse_fractal_type(av[1], app))
	{
		print_usage_and_exit();
		return (0);
	}
	if (app->fractal_choice == 2 && ac >= 3)
	{
		if (!parse_julia_arguments(ac, av, app))
		{
			print_usage_and_exit();
			return (0);
		}
	}
	return (1);
}

static int	parse_fractal_type(const char *name, t_app_ctx *app)
{
	if (!name)
		return (0);
	if (!strcmp(name, "mandelbrot"))
	{
		app->fractal_choice = 1;
		return (1);
	}
	if (!strcmp(name, "julia"))
	{
		app->fractal_choice = 2;
		app->arg_r = DEFAULT_JULIA_R;
		app->arg_i = DEFAULT_JULIA_I;
		return (1);
	}
	return (0);
}

static int	parse_julia_arguments(int ac, char **av, t_app_ctx *app)
{
	if (ac >= 3)
	{
		if (!is_valid_double(av[2]))
		{
			write(STDERR_FILENO, "Error: Invalid real parameter\n", 30);
			return (0);
		}
		app->arg_r = str_to_double(av[2]);
	}
	if (ac >= 4)
	{
		if (!is_valid_double(av[3]))
		{
			write(STDERR_FILENO, "Error: Invalid imaginary parameter\n", 35);
			return (0);
		}
		app->arg_i = str_to_double(av[3]);
	}
	return (validate_julia_range(app));
}

static int	validate_julia_range(t_app_ctx *app)
{
	if (app->arg_r < -2.0 || app->arg_r > 2.0)
	{
		write(STDERR_FILENO, "Error: Real part must be between -2 and 2\n", 43);
		return (0);
	}
	if (app->arg_i < -2.0 || app->arg_i > 2.0)
	{
		write(STDERR_FILENO, "Error: Imag part must be between -2 and 2\n", 43);
		return (0);
	}
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
		if (!isdigit(*str))
			return (0);
		has_digit = 1;
		str++;
	}
	if (*str == '.')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		has_digit = 1;
		str++;
	}
	return (has_digit);
}
/*
#include "fractol.h"

static int	parse_fractal_type(const char *name, t_app_ctx *app);
static int	parse_julia_parameters(int ac, char **av, t_app_ctx *app);
static int	is_valid_double(const char *str);

int	validate_cli_arguments(int ac, char **av, t_app_ctx *app)
{
	if (ac < 2 || ac > 4)
	{
		print_usage_and_exit();
		return (0);
	}
	if (!parse_fractal_type(av[1], app))
	{
		print_usage_and_exit();
		return (0);
	}
	if (app->fractal_choice == 2 && ac >= 3)
	{
		if (!parse_julia_parameters(ac, av, app))
		{
			print_usage_and_exit();
			return (0);
		}
	}
	return (1);
}

static int	parse_fractal_type(const char *name, t_app_ctx *app)
{
	if (!name)
		return (0);
	if (!strcmp(name, "mandelbrot"))
	{
		app->fractal_choice = 1;
		return (1);
	}
	if (!strcmp(name, "julia"))
	{
		app->fractal_choice = 2;
		app->arg_r = DEFAULT_JULIA_R;
		app->arg_i = DEFAULT_JULIA_I;
		return (1);
	}
	return (0);
}

static int	is_valid_double(const char *str)
{
	int	has_digit;

	has_digit = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str != '.')
	{
		if (!isdigit(*str))
			return (0);
		has_digit = 1;
		str++;
	}
	if (*str == '.')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		has_digit = 1;
		str++;
	}
	return (has_digit);
}

static int	parse_julia_parameters(int ac, char **av, t_app_ctx *app)
{
	if (ac >= 3)
	{
		if (!is_valid_double(av[2]))
		{
			write(STDERR_FILENO, "Error: Invalid real parameter\n", 30);
			return (0);
		}
		app->arg_r = str_to_double(av[2]);
	}
	if (ac >= 4)
	{
		if (!is_valid_double(av[3]))
		{
			write(STDERR_FILENO, "Error: Invalid imaginary parameter\n", 35);
			return (0);
		}
		app->arg_i = str_to_double(av[3]);
	}
	if (app->arg_r < -2.0 || app->arg_r > 2.0)
	{
		write(STDERR_FILENO, "Error: Real part must be between -2 and 2\n", 43);
		return (0);
	}
	if (app->arg_i < -2.0 || app->arg_i > 2.0)
	{
		write(STDERR_FILENO, "Error: Imag part must be between -2 and 2\n", 43);
		return (0);
	}
	return (1);
}
#include "fractol.h"
#include <string.h> // REMOVE WHEN REPLACING strcmp by ft_strcmp

static int	parse_julia_parameters(int ac, char **av, t_app_ctx *app);
static int	validate_fractal_name(const char *name);
int	validate_cli_arguments(int ac, char **av, t_app_ctx *app)
{
	int	choice;

	if (ac != 2)
	{
		print_usage_and_exit();
		return (0);
	}
	choice = validate_fractal_name(av[1]);
	if (!choice)
	{
		print_usage_and_exit();
		return (0);
	}
	app->fractal_choice = choice;
	return (1);
}

int	validate_cli_arguments(int ac, char **av, t_app_ctx *app)
{
	if (ac < 2 || ac > 4)
	{
		print_usage_and_exit();
		return (0);
	}
	if (!parse_fractal_type(av[1], app))
	{
		print_usage_and_exit();
		return (0);
	}
	if (app->fractal_choice == 2 && ac >= 3)
	{
		if (!parse_julia_parameters(ac, av, app))
		{
			print_usage_and_exit();
			return (0);
		}
	}
	return (1);
}


static int	parse_julia_parameters(int ac, char **av, t_app_ctx *app)
{
	if (ac >= 3)
		app->arg_r = str_to_double(av[2]);
	else
		app->arg_r = DEFAULT_JULIA_R;
	
	if (ac >= 4)
		app->arg_i = str_to_double(av[3]);
	else
		app->arg_i = DEFAULT_JULIA_I;
	
	// Validate the parameters are reasonable
	if (app->arg_r < -2.0 || app->arg_r > 2.0 
		|| app->arg_i < -2.0 || app->arg_i > 2.0)
	{
		write(STDERR_FILENO, 
			"Error: Julia parameters should be between -2 and 2\n", 52);
		return (0);
	}
	return (1);
}


static int	validate_fractal_name(const char *name)
{
	if (!name)
		return (0);
	if (!strcmp(name, "mandelbrot"))
		return (1);
	if (!strcmp(name, "julia"))
		return (2);
	return (0);
}
*/
