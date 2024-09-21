/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:52:01 by mohhusse          #+#    #+#             */
/*   Updated: 2024/09/21 16:04:17 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	f;

	parse_args(argc, argv);
	init_fractol(&f);
	if (!ft_strncmp(argv[1], "julia", 5) || !ft_strncmp(argv[1], "j", 1))
	{
		init_julia(&f, argc, argv);
		julia(&f, f.julia_re, f.julia_im);
	}
	else if (!ft_strncmp(argv[1], "burning", 7) || !ft_strncmp(argv[1], "b", 1))
	{
		f.type = BURNING_SHIP;
		burning_ship(&f);
	}
	else
	{
		f.type = MANDELBROT;
		mandelbrot(&f);
	}
	mlx_key_hook(f.win, handle_key, &f);
	mlx_mouse_hook(f.win, handle_mouse, &f);
	mlx_hook(f.win, 17, 0, ft_close, NULL);
	mlx_loop(f.mlx);
	return (0);
}
