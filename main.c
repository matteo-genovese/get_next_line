/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:23:03 by mgenoves          #+#    #+#             */
/*   Updated: 2024/03/14 18:25:02 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*str;
	// int		count;

	// count = -1;
	fd = open("./test.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		printf("%s", str);
		if (!str)
			break ;
		free(str);
	}
}
