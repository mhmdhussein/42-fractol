/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:12:27 by mohhusse          #+#    #+#             */
/*   Updated: 2024/07/27 13:12:27 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (write (1, "(null)", 6));
	}
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}	
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	else if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
	}
	count += ft_putchar(nb % 10 + '0');
	return (count);
}

int	ft_unputnbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
	}
	count += ft_putchar(nb % 10 + '0');
	return (count);
}

int	ft_smalldecimal(unsigned int n)
{
	char	*hex_digits;
	int		count;

	count = 0;
	hex_digits = "0123456789abcdef";
	if (n < 16)
	{
		write(1, &hex_digits[n], 1);
		return (1);
	}
	else
	{
		count += ft_smalldecimal(n / 16);
		write(1, &hex_digits[n % 16], 1);
	}
	return (count + 1);
}
