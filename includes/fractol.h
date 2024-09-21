/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:51:29 by mohhusse          #+#    #+#             */
/*   Updated: 2024/09/21 16:05:10 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 600

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP
}	t_fractal_type;

typedef struct s_fractol
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	double			zx;
	double			zy;
	double			ab_zx;
	double			ab_zy;
	double			c_re;
	double			c_im;
	double			tmp;
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double			zoom;
	int				max_iter;
	double			smooth_iter;
	unsigned int	color;
	t_fractal_type	type;
	double			julia_re;
	double			julia_im;
}	t_fractol;

typedef struct s_palette
{
	unsigned char	r1;
	unsigned char	g1;
	unsigned char	b1;
	unsigned char	r2;
	unsigned char	g2;
	unsigned char	b2;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_palette;

// Fractals
void			julia(t_fractol *f, double c_re, double c_im);
void			mandelbrot(t_fractol *f);
void			burning_ship(t_fractol *f);

// Color
void			calculate_color(t_fractol *f, int *i);

// Events
int				handle_mouse(int button, int x, int y, t_fractol *f);
int				handle_key(int key, t_fractol *f);

// Initialization
void			init_fractol(t_fractol *f);
void			init_julia(t_fractol *f, int argc, char **argv);

// Args
void			parse_args(int argc, char **argv);

// Utils
void			help_message(void);
double			ft_atof(char *str);
int				ft_isspace(char c);
int				ft_close(void *param);
void			init_fractol(t_fractol *f);

#endif