/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr_fd_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:39:36 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/16 20:07:21 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_u_nbr_len(unsigned int nb)
{
	int	len;

	len = 1;
	while (nb > 9)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

int	ft_u_putnbr_fd_printf(unsigned int nb, int fd)
{
	int	len;

	len = ft_u_nbr_len(nb);
	if (nb > 9)
	{
		if (ft_u_putnbr_fd_printf(nb / 10, fd) < 0)
			return (-1);
	}
	if (ft_putchar_fd_printf(nb % 10 + '0', fd) < 0)
		return (-1);
	return (len);
}
