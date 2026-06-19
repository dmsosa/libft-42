/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:21:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/19 10:40:35 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_chr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void	ft_shift(char *buffer)
{
	int	skip;
	int	i;

	i = 0;
	skip = ft_strlen_chr(buffer, '\n');
	if (buffer[skip])
		skip++;
	while (buffer[skip])
		buffer[i++] = buffer[skip++];
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		l1;
	int		l2;
	char	*joined;

	l1 = ft_strlen_chr(s1, 0);
	l2 = ft_strlen_chr(s2, '\n');
	if (s2[l2])
		l2++;
	joined = malloc((l1 + l2 + 1) * sizeof(char));
	if (!joined)
		return (free(s1), NULL);
	ft_strcpy_gnl(joined, s1);
	ft_strcpy_gnl(joined + l1, s2);
	return (free(s1), joined);
}

void	ft_strcpy_gnl(char *dest, char *src)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return ;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i])
		dest[i++] = '\n';
	dest[i] = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*c_ptr;
	size_t			i;

	if (nmemb != 0 && size > (size_t) -1 / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	c_ptr = (unsigned char *) ptr;
	while (i < (nmemb * size))
		c_ptr[i++] = 0;
	return (ptr);
}
