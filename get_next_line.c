/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:20:17 by mgenoves          #+#    #+#             */
/*   Updated: 2024/03/20 12:45:42 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*left_o;
	char		*line;
	char		*buff;
	int			bytes_read;

	bytes_read = 1;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	line = fill_line(fd, &left_o, buff, &bytes_read);
	free(buff);
	buff = NULL;
	if ((!line || line[0] == '\0') && bytes_read == 0)
	{
		if (left_o)
			free(left_o);
		return (NULL);
	}
	return (line);
}

char	*fill_line(int fd, char **left_o, char *buff, int *bytes_read)
{
	char	*line;

	line = fill_line_w_left_o(left_o);
	if (!line)
		line = ft_strjoin("", "", 0);
	if (ft_check_nl(line, '\n'))
		return (line);
	while (*bytes_read && !ft_check_nl(buff, '\n'))
	{
		*bytes_read = read(fd, buff, BUFFER_SIZE);
		if (*bytes_read == 0 || *bytes_read == -1)
		{
			if (*line)
				return (line);
			free(line);
			return (NULL);
		}
		buff[*bytes_read] = '\0';
		line = ft_strjoin(line, ft_substr(buff, 0, ft_sc(buff, '\n') + 1), 1);
		if (*left_o && **left_o == '\0')
			free(*left_o);
		*left_o = ft_substr(buff, ft_sc(buff, '\n') + 1, *bytes_read);
	}
	return (line);
}

char	*fill_line_w_left_o(char **left_o)
{
	char	*line;
	int		len_left_o;
	char	*tmp;

	if (*left_o && **left_o != '\0')
	{
		if (ft_check_nl(*left_o, '\n'))
		{
			line = ft_substr(*left_o, 0, ft_sc(*left_o, '\n') + 1);
			len_left_o = ft_strlen(*left_o);
			ft_m(*left_o, *left_o + ft_sc(*left_o, '\n') + 1, len_left_o);
			return (line);
		}
		tmp = ft_substr(*left_o, 0, ft_strlen(*left_o));
		free(*left_o);
		*left_o = NULL;
		return (tmp);
	}
	return (NULL);
}

void	ft_m(void *dest, const void *src, int n)
{
	char	*temp_dest;
	char	*temp_src;
	int		i;

	if (!dest || !src)
		return ;
	temp_dest = (char *) dest;
	temp_src = (char *) src;
	if (temp_src > temp_dest)
	{
		i = 0;
		while (i < n && temp_src[i])
		{
			temp_dest[i] = temp_src[i];
			i++;
		}
		if (i < n)
			while (i < n)
			{
				temp_dest[i] = '\0';
				i++;
			}
	}
	else
		temp_dest[0] = '\0';
}

void	ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*w;

	i = 0;
	w = (char *)s;
	while (i < n)
	{
		w[i] = c;
		++i;
	}
}
