/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:37:49 by mohhusse          #+#    #+#             */
/*   Updated: 2024/09/21 16:05:45 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	help_message(void)
{
	ft_printf("\033[31mError!\033[0m\n");
	ft_printf("\033[35mUsage: ./fractol [type] [values]\033[0m\n\n");
	ft_printf("---------------------------\n");
	ft_printf("Fractals:\n\nUse julia or j for julia sets.\n");
	ft_printf("Use mandelbrot or m for mandelbrot sets.\n");
	ft_printf("Use burning or b for burning ship sets.\n");
	ft_printf("---------------------------\n");
	ft_printf("You can only insert values for julia sets ");
	ft_printf("it must contain a decimal point.\n");
	ft_printf("Example: ./fractol julia 0.285 -0.03\n\n");
	exit(1);
}

int	ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
