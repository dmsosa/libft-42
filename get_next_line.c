/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:21:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/18 17:01:40 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			r;

	if ((fd < 0 || fd > 1023) || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	r = 1;
	if (!buffer[0])
		r = read(fd, buffer, BUFFER_SIZE);
	while (r > 0)
	{
		line = ft_strjoin_gnl(line, buffer);
		ft_shift(buffer);
		if (!line)
			return (NULL);
		if (line[ft_strlen_chr(line, '\n')])
			break ;
		r = read(fd, buffer, BUFFER_SIZE);
	}
	if (r == -1)
		return (free(line), NULL);
	return (line);
}
