/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:21:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/19 12:10:12 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

//gcc -Wall -Wextra -Werror -Wl,--wrap=malloc -g *.c -o a.out
//valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes ./a.out test.txt

extern void* __real_malloc(size_t size);

void* __wrap_malloc(size_t size) 
{
    // Cambia el 3 por el número de mallocs exitosos que quieras permitir
    static int llamadas_exitosas = 13423;

    if (llamadas_exitosas > 0) {
        llamadas_exitosas--;
        return __real_malloc(size); // Llama al malloc de verdad
    }
    
    return (NULL); // A partir de la cuarta llamada, todas fallan
}

int	main(void)
{
	char	*line;
	int		count;
	int		fd;

	fd = open("el_quijote.txt", O_RDONLY);
	if (!fd)
		return (0);
	count = 0;
	line = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("[%d] the line is: '%s'\n", count, line);
		count++;
		line = get_next_line(fd);
		if (!line)
			return (free(line), 0);
		free(line);
	}
	return (0);
}
