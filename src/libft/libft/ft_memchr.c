/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:23:28 by arnaud            #+#    #+#             */
/*   Updated: 2023/10/10 22:54:14 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_ptr;
	size_t				i;

	i = -1;
	s_ptr = (unsigned char *)s;
	while (++i < n)
	{
		if (s_ptr[i] == (unsigned char)c)
			return ((void *)s + i);
	}
	return (NULL);
}
