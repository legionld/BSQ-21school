/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:25:02 by jschille          #+#    #+#             */
/*   Updated: 2018/11/07 23:36:56 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "head.h"

int			check_fo(char ch)
{
	if (ch != '\n')
		return (2);
	return (0);
}

int			fill_it(int fd)
{
	char	ch;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (read(fd, &ch, 1))
	{
		if (ch == '\n' || ch == '\0')
		{
			if (j != g_col - 1)
			{
				close(fd);
				return (check_fo(ch));
			}
			g_map[i][j] = '\0';
			j = 0;
			i++;
		}
		else
			g_map[i][j++] = ch;
	}
	if (g_map[0][0] != g_chars[0] && g_map[0][0] != g_chars[1])
		return (0);
	return (1);
}

int			malloc_it(int len, char *argv, int symb)
{
	int		fd;
	int		i;
	char	*buf;

	i = 0;
	g_map = (char**)malloc(sizeof(char*) * (len));
	g_map[len - 1] = 0;
	while (i < len - 1)
	{
		g_map[i] = (char*)malloc(sizeof(char) * (g_col + 1));
		++i;
	}
	buf = (char*)malloc(sizeof(char) * (symb - 3));
	fd = open(argv, O_RDONLY);
	i = read(fd, &buf, symb - 3);
	i = read(fd, &g_chars, 4);
	if ((g_str < 1 || g_col < 1) || (g_chars[0] == g_chars[1]) ||
		(g_chars[0] == g_chars[2]) || (g_chars[2] == g_chars[1]))
		return (0);
	return (fill_it(fd));
}

int			create_map(char *argv)
{
	int		len;
	int		fd;
	char	ch;
	int		symb;

	len = 0;
	symb = 0;
	g_col = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &ch, 1))
	{
		if (ch == '\0')
			break ;
		if (ch == '\n')
			++len;
		if (len == 1)
			++g_col;
		if (len == 0)
			++symb;
	}
	g_str = len - 1;
	close(fd);
	return (malloc_it(len, argv, symb));
}
