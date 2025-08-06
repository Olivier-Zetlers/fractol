#include "../inc/fractol.h"

void	print_usage_and_exit(void)
{
	write(STDERR_FILENO, "Usage: ./fractol <type> [parameters]\n", 38);
	write(STDERR_FILENO, "[parameters] must be between -2 and 2\n", 39);
	write(STDERR_FILENO, "\nFractal types:\n", 16);
	write(STDERR_FILENO, "  mandelbrot\n", 13);
	write(STDERR_FILENO, "  julia [real] [imaginary]\n", 27);
	write(STDERR_FILENO, "\nExamples:\n", 11);
	write(STDERR_FILENO, "  ./fractol mandelbrot\n", 23);
	write(STDERR_FILENO, "  ./fractol julia\n", 18);
	write(STDERR_FILENO, "  ./fractol julia -0.8 0.156\n", 29);
	write(STDERR_FILENO, "  ./fractol julia 0.3 0.5\n", 26);
	exit(EXIT_FAILURE);
}
