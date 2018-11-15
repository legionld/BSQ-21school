/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_na.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:25:02 by jschille          #+#    #+#             */
/*   Updated: 2018/11/07 23:06:04 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "head.h"

void		create_map_na(void)
{
	int		fd;
	char	ch;

	fd = open("input", O_WRONLY | O_TRUNC | O_CREAT);
	while (read(0, &ch, 1))
		write(fd, &ch, 1);
	if (ch != '\n')
		write(fd, "\n", 1);
	close(fd);
}
