/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 10:48:13 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/19 11:56:15 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	lines_fd[MAX_FD][BUFFER_SIZE + 1];
	char		*line;
	int			r;

	line = NULL;
	r = 1;
	if (!lines_fd[fd][0])
		r = read(fd, lines_fd[fd], BUFFER_SIZE);
	while (r > 0)
	{
		line = ft_strjoin_gnl(line, lines_fd[fd]);
		if (!line)
			return (free(line), line = NULL, NULL);
		ft_shift(lines_fd[fd]);
		if (line[ft_strlen_chr(line, '\n')])
			break ;
		r = read(fd, lines_fd[fd], BUFFER_SIZE);
	}
	if (r < 0)
		return (free(line), line = NULL, NULL);
	return (line);
}
