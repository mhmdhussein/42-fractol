/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:08:26 by mohhusse          #+#    #+#             */
/*   Updated: 2024/09/21 15:18:44 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int	interpolate_color(unsigned int color1,
unsigned int color2, double t)
{
	t_palette	p;

	p.r1 = (color1 >> 16) & 0xFF;
	p.g1 = (color1 >> 8) & 0xFF;
	p.b1 = color1 & 0xFF;
	p.r2 = (color2 >> 16) & 0xFF;
	p.g2 = (color2 >> 8) & 0xFF;
	p.b2 = color2 & 0xFF;
	p.r = p.r1 + t * (p.r2 - p.r1);
	p.g = p.g1 + t * (p.g2 - p.g1);
	p.b = p.b1 + t * (p.b2 - p.b1);
	return ((p.r << 16) | (p.g << 8) | p.b);
}

void	calculate_color(t_fractol *f, int *i)
{
	f->smooth_iter = i[2] + 1 - log(log2(f->zx * f->zx + f->zy * f->zy));
	if (f->smooth_iter < f->max_iter / 2)
		f->color = interpolate_color(0x0f1c6d, 0xffffff, f->smooth_iter
				/ (f->max_iter / 2));
	else
		f->color = interpolate_color(0xffffff, 0xfca40d, (f->smooth_iter
					- f->max_iter / 2) / (f->max_iter / 2));
	*(int *)(f->addr + (i[0] * f->line_length + i[1] * (f->bpp / 8)))
		= f->color;
	i[1]++;
}
