/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:46:24 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/16 20:06:22 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_int_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_putnbr_fd_printf(int nb, int fd)
{
	int	len;

	len = ft_int_len(nb);
	if (nb < 0)
	{
		if (ft_putchar_fd_printf('-', fd) < 0)
			return (-1);
		nb = -nb;
	}
	if (nb > 9)
	{
		if (ft_putnbr_fd_printf(nb / 10, fd) < 0)
			return (-1);
	}
	if (ft_putchar_fd_printf(48 + nb % 10, fd) < 0)
		return (-1);
	return (len);
}
