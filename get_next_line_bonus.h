/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:16:27 by mgenoves          #+#    #+#             */
/*   Updated: 2024/02/29 17:12:48 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*fill_line(int fd, char **left_o, char *buffer, int *bytes_read);
char	*fill_line_w_left_o(char **left_o);
void	ft_memset(void *s, int c, size_t n);
int		ft_sc(const char *s, int c);
int		ft_check_nl(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2, int flag);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_m(void *dest, const void *src, int n);
size_t	ft_strlen(const char *s);

#endif
