/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 19:37:53 by durisosa          #+#    #+#             */
/*   Updated: 2026/05/29 20:20:36 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		mem_count;
	char	*ptr;

	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	mem_count = ft_count_digits(n);
	ptr = malloc(mem_count + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[mem_count--] = 0;
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	while (mem_count > 0)
	{
		ptr[mem_count--] = (n % 10) + 48;
		n /= 10;
	}
	if (ptr[0] != '-')
		ptr[0] = (n % 10) + 48;
	return (ptr);
}
