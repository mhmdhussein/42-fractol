/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:11:28 by mohhusse          #+#    #+#             */
/*   Updated: 2024/07/27 13:11:30 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_unputnbr(unsigned int nb);
int	ft_printf(const char *format, ...);
int	ft_smalldecimal(unsigned int n);
int	ft_bigdecimal(unsigned int n);
int	ft_p(void *p);
int	process_format_string(const char *format, va_list args);

#endif
