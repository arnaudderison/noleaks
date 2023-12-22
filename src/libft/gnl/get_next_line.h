/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:16:53 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/20 18:20:14 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 55

# include <stdio.h> //delete
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *str, int to_find);
size_t	ft_strlen_gnl(char const *str);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
void	ft_bzero_gnl(void *s, size_t n);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size);

#endif
