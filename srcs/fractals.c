/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:27:28 by mohhusse          #+#    #+#             */
/*   Updated: 2024/09/21 16:07:32 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia(t_fractol *f, double c_re, double c_im)
{
	int		i[3];

	i[0] = 0;
	while (i[0] < HEIGHT)
	{
		i[1] = 0;
		while (i[1] < WIDTH)
		{
			f->zx = f->min_re + i[1] * (f->max_re - f->min_re) / WIDTH;
			f->zy = f->min_im + i[0] * (f->max_im - f->min_im) / HEIGHT;
			i[2] = 0;
			while (f->zx * f->zx + f->zy * f->zy < 4 && i[2] < f->max_iter)
			{
				f->tmp = f->zx * f->zx - f->zy * f->zy + c_re;
				f->zy = 2.0 * f->zx * f->zy + c_im;
				f->zx = f->tmp;
				i[2]++;
			}
			calculate_color(f, i);
		}
		i[0]++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	mandelbrot(t_fractol *f)
{
	int	i[3];

	i[0] = 0;
	while (i[0] < HEIGHT)
	{
		i[1] = 0;
		while (i[1] < WIDTH)
		{
			f->c_re = f->min_re + i[1] * (f->max_re - f->min_re) / WIDTH;
			f->c_im = f->min_im + i[0] * (f->max_im - f->min_im) / HEIGHT;
			f->zx = 0.0;
			f->zy = 0.0;
			i[2] = 0;
			while (f->zx * f->zx + f->zy * f->zy < 4 && i[2] < f->max_iter)
			{
				f->tmp = f->zx * f->zx - f->zy * f->zy + f->c_re;
				f->zy = 2.0 * f->zx * f->zy + f->c_im;
				f->zx = f->tmp;
				i[2]++;
			}
			calculate_color(f, i);
		}
		i[0]++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	burning_ship_helper(t_fractol *f)
{
	f->ab_zx = fabs(f->zx);
	f->ab_zy = fabs(f->zy);
	f->tmp = f->ab_zx * f->ab_zx - f->ab_zy * f->ab_zy + f->c_re;
	f->zy = 2.0 * f->ab_zx * f->ab_zy + f->c_im;
	f->zx = f->tmp;
}

void	burning_ship(t_fractol *f)
{
	int	i[3];

	i[0] = 0;
	while (i[0] < HEIGHT)
	{
		i[1] = 0;
		while (i[1] < WIDTH)
		{
			f->c_re = f->min_re + i[1] * (f->max_re - f->min_re) / WIDTH;
			f->c_im = f->min_im + i[0] * (f->max_im - f->min_im) / HEIGHT;
			f->zx = 0.0;
			f->zy = 0.0;
			i[2] = 0;
			while (f->zx * f->zx + f->zy * f->zy < 4 && i[2] < f->max_iter)
			{
				burning_ship_helper(f);
				i[2]++;
			}
			calculate_color(f, i);
		}
		i[0]++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
