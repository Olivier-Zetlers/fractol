/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozetlers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:20:40 by ozetlers          #+#    #+#             */
/*   Updated: 2025/08/06 20:20:41 by ozetlers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	psychedelic_palette(int iteration, int max_iteration)
{
	double	t;
	double	angle;
	int		r;
	int		g;
	int		b;

	t = (double)iteration / (double)max_iteration;
	angle = t * 6.28318530718 * 4.0;
	r = (int)(127.5 * (1.0 + sin(angle)));
	g = (int)(127.5 * (1.0 + sin(angle + 2.09439510239)));
	b = (int)(127.5 * (1.0 + sin(angle + 4.18879020479)));
	return ((r << 16) | (g << 8) | b);
}
