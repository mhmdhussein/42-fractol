/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:07:38 by mohhusse          #+#    #+#             */
/*   Updated: 2024/09/21 15:02:56 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractol(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_length, &f->endian);
	f->min_re = -2.0;
	f->max_re = 2.0;
	f->min_im = -2.0;
	f->max_im = 2.0;
	f->zoom = 1.0;
	f->max_iter = 100;
}

void	init_julia(t_fractol *f, int argc, char **argv)
{
	f->type = JULIA;
	if (argc == 4)
	{
		f->julia_re = ft_atof(argv[2]);
		f->julia_im = ft_atof(argv[3]);
	}
	else
	{
		f->julia_re = -0.7;
		f->julia_im = 0.27015;
	}
}
