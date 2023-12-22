/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:28:24 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/16 20:08:51 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static int	is_flag(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	proc_command(va_list args, char flag, int *len)
{
	int	tmp;

	tmp = 0;
	if (flag == 'c')
		tmp = ft_putchar_fd_printf(va_arg(args, int), 1);
	else if (flag == 's')
		tmp = ft_putstr_fd_printf(va_arg(args, char *), 1);
	else if (flag == 'p')
		tmp = ft_pointer(va_arg(args, size_t));
	else if (flag == 'd' || flag == 'i')
		tmp = ft_putnbr_fd_printf(va_arg(args, int), 1);
	else if (flag == 'u')
		tmp = ft_u_putnbr_fd_printf(va_arg(args, unsigned int), 1);
	else if (flag == 'x')
		tmp = ft_puthex_fd_printf(va_arg(args, int), 0, 1);
	else if (flag == 'X')
		tmp = ft_puthex_fd_printf(va_arg(args, int), 1, 1);
	else if (flag == '%')
		tmp = ft_putchar_fd_printf('%', 1);
	if (tmp < 0)
		return (-1);
	else
		return (*len += tmp);
	return (*len);
}

static int	parse_strs(const char *strs, va_list args, int *len_ptr)
{
	int	i;
	int	len;

	i = -1;
	len = *len_ptr;
	while (strs[++i])
	{
		if (strs[i] == '%' && is_flag(strs[i + 1]))
		{
			len = proc_command(args, strs[i + 1], &len);
			if (len < 0)
				return (-1);
			i++;
		}
		else
		{
			len += ft_putchar_fd_printf(strs[i], 1);
			if (len < 0)
				return (-1);
		}
	}
	*len_ptr = len;
	return (0);
}

int	ft_printf(const char *strs, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, strs);
	if (parse_strs(strs, args, &len) < 0)
	{
		va_end(args);
		return (-1);
	}
	va_end(args);
	return (len);
}
