/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 20:55:10 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/19 10:37:26 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlen_chr(char *str, char c);
char	*ft_strjoin_gnl(char *dest, char *src);
void	ft_shift(char *buffer);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_strcpy_gnl(char *dest, char *src);

#endif
