/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:51:46 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/16 20:05:57 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_len_hex(int nb)
{
	int	len;

	len = 0;
	if (nb < 16)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	ft_puthex_fd_printf(int nb, int isMaj, int fd)
{
	char	base[17];
	int		len;

	if (isMaj == 0)
		ft_strlcpy_printf(base, "0123456789abcdef", 17);
	else
		ft_strlcpy_printf(base, "0123456789ABCDEF", 17);
	len = ft_len_hex(nb);
	if (nb < 0)
	{
		if (ft_putchar_fd_printf('-', fd) < 0)
			return (-1);
		nb = -nb;
	}
	if (nb > 15)
	{
		if (ft_puthex_fd_printf(nb / 16, isMaj, fd) < 0)
			return (-1);
	}
	if (ft_putchar_fd_printf(base[nb % 16], fd) < 0)
		return (-1);
	return (len);
}
