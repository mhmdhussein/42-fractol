/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:36:09 by mohhusse          #+#    #+#             */
/*   Updated: 2024/09/21 16:04:55 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2++)
		if (*s1++ == '\0')
			return (0);
	return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
}

void	check_decimal(char **argv)
{
	int	i;

	if (!ft_strchr(argv[2], '.') || !ft_strchr(argv[3], '.'))
		help_message();
	i = 0;
	while (argv[2][i])
	{
		if (!ft_isspace(argv[2][i]) && argv[2][i] != '.'
			&& !ft_isdigit(argv[2][i]) && argv[2][i] != '-'
				&& argv[2][i] != '+')
			help_message();
		i++;
	}
	i = 0;
	while (argv[3][i])
	{
		if (!ft_isspace(argv[3][i]) && argv[3][i] != '.'
			&& !ft_isdigit(argv[3][i]) && argv[3][i] != '-'
				&& argv[3][i] != '+')
			help_message();
		i++;
	}
	if (ft_atof(argv[2]) > 2.0 || ft_atof(argv[2]) < -2.0
		|| ft_atof(argv[3]) > 2.0 || ft_atof(argv[3]) < -2.0)
		help_message();
}

void	parse_args(int argc, char **argv)
{
	if ((argc != 2 && argc != 4) || (ft_strcmp(argv[1], "julia")
			&& ft_strcmp(argv[1], "j") && ft_strcmp(argv[1], "mandelbrot")
			&& ft_strcmp(argv[1], "m") && ft_strcmp(argv[1], "burning")
			&& ft_strcmp(argv[1], "b")))
		help_message();
	if (ft_strcmp(argv[1], "julia") && ft_strcmp(argv[1], "j") && argc == 4)
		help_message();
	if (argc == 4)
		check_decimal(argv);
}
