/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:41:05 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/05 14:50:28 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len_1;
	int		len_2;
	char	*buf;

	if (!s1 || !s2)
		return (NULL);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	buf = malloc(len_1 + len_2 + 1 * sizeof(char));
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, s1, len_1 + 1);
	ft_strlcat(buf, s2, len_1 + len_2 + 1);
	return (buf);
}
