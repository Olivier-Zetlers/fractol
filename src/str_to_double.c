/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozetlers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:21:59 by ozetlers          #+#    #+#             */
/*   Updated: 2025/08/06 20:22:00 by ozetlers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	ft_isspace(unsigned char c);

static const char	*skip_blanks_and_sign(const char *s, int *sign)
{
	while (*s && ft_isspace((unsigned char)*s))
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

static int	ft_isspace(unsigned char c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}

double	str_to_double(const char *str)
{
	int		sign;
	double	value;
	double	power;

	str = skip_blanks_and_sign(str, &sign);
	value = 0.0;
	while (ft_isdigit((unsigned char)*str))
	{
		value = value * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	power = 1.0;
	while (ft_isdigit((unsigned char)*str))
	{
		value = value * 10.0 + (*str - '0');
		power *= 10.0;
		str++;
	}
	return (sign * (value / power));
}
