#include "fractol.h"

static const char	*skip_blanks_and_sign(const char *s, int *sign)
{
	while (*s && isspace((unsigned char)*s))
		s++;
	*sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			*sign = -1;
		s++;
	}
	return (s);
}

double	str_to_double(const char *str)
{
	int		sign;
	double	value;
	double	power;

	str = skip_blanks_and_sign(str, &sign);
	value = 0.0;
	while (isdigit((unsigned char)*str))
	{
		value = value * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	power = 1.0;
	while (isdigit((unsigned char)*str))
	{
		value = value * 10.0 + (*str - '0');
		power *= 10.0;
		str++;
	}
	return (sign * (value / power));
}
