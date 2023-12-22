/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:38:19 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/20 18:20:14 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char const *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	int		size;
	char	*ret;
	int		i;
	int		j;

	i = 0;
	size = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[size] = 0;
	return (ret);
}

char	*ft_strchr_gnl(const char *str, int charac)
{
	if (!str)
		return (NULL);
	while (*str || (char)charac == '\0')
	{
		if (*str == (char)charac)
			return ((char *)str);
		str++;
	}
	if (*str == charac)
		return ((char *)str);
	return (NULL);
}

void	ft_bzero_gnl(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = -1;
	while (++i < n)
		ptr[i] = '\0';
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = ft_strlen_gnl(src);
	if (!size)
		return (len);
	while (++i < size - 1 && src[i])
		dst[i] = src[i];
	dst[i] = 0;
	return (len);
}
