/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:59:42 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/20 18:19:59 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_join_free(char *s1, char *s2)
{
	char	*ret;

	if (s1)
	{
		ret = ft_strjoin_gnl(s1, s2);
		free(s1);
	}
	else
		ret = ft_strjoin_gnl("", s2);
	return (ret);
}

static char	*get_buffer_file(int fd, char *buffer, char *tmp_buffer)
{
	int	bytes;

	while (!tmp_buffer || !ft_strchr_gnl(buffer, '\n'))
	{
		bytes = read(fd, tmp_buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(tmp_buffer);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		tmp_buffer[bytes] = '\0';
		buffer = ft_join_free(buffer, tmp_buffer);
		if (!buffer)
		{
			free(tmp_buffer);
			return (NULL);
		}
	}
	free(tmp_buffer);
	return (buffer);
}

static char	*get_line(char *buffer)
{
	char	*line;
	int		len;

	if (!buffer)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy_gnl(line, buffer, len + 1);
	return (line);
}

char	*clean_buffer(char *line, char *buffer)
{
	int		start;
	int		end;
	int		size;
	char	*new_buffer;

	if (!line || !buffer)
		return (NULL);
	start = ft_strlen_gnl(line);
	end = ft_strlen_gnl(buffer);
	size = end - start;
	if (size < 0)
		return (NULL);
	if (size == 0)
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(size + 1);
	if (!new_buffer)
		return (NULL);
	ft_strlcpy_gnl(new_buffer, buffer + start, size + 1);
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	tmp_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp_buffer)
		return (NULL);
	buffer = get_buffer_file(fd, buffer, tmp_buffer);
	line = get_line(buffer);
	printf("here");
	buffer = clean_buffer(line, buffer);
	return (line);
}
