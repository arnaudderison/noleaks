/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:00:59 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/16 20:05:21 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_pointer(size_t adrr, char *base)
{
	char	string[17];
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (adrr != 0)
	{
		string[i++] = base[adrr % 16];
		adrr /= 16;
	}
	while (i--)
	{
		if (ft_putchar_fd_printf(string[i], 1) < 0)
			return (-1);
		len += 1;
	}
	return (len);
}

int	ft_pointer(size_t addr)
{
	int	len;
	int	result;

	if (write(1, "0x", 2) < 0)
		return (-1);
	len = 2;
	if (addr == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		len++;
	}
	else
	{
		result = print_pointer(addr, "0123456789abcdef");
		if (result < 0)
			return (-1);
		len += result;
	}
	return (len);
}
