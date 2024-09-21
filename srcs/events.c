/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:54:31 by mohhusse          #+#    #+#             */
/*   Updated: 2024/09/21 16:07:52 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_key(int key, t_fractol *f)
{
	if (key == 65307)
	{
		mlx_destroy_window(f->mlx, f->win);
		exit(0);
	}
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractol *f)
{
	double	zoom_factor;

	(void)x;
	(void)y;
	if (button == 4 || button == 5)
	{
		if (button == 4)
			zoom_factor = 1.1;
		else
			zoom_factor = 0.9;
		f->zoom *= zoom_factor;
		f->min_re *= zoom_factor;
		f->max_re *= zoom_factor;
		f->min_im *= zoom_factor;
		f->max_im *= zoom_factor;
		if (f->type == JULIA)
			julia(f, f->julia_re, f->julia_im);
		else if (f->type == MANDELBROT)
			mandelbrot(f);
		else if (f->type == BURNING_SHIP)
			burning_ship(f);
	}
	return (0);
}
