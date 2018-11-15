/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:36:53 by jschille          #+#    #+#             */
/*   Updated: 2018/11/07 23:38:54 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "t_sqrt.h"
#include "t_point.h"
#include "creation.h"
#include "head.h"
#include "create_map.h"
#include "fill_map.h"
#include "print_map.h"
#include "read_map.h"
#include "free_map.h"
#include <fcntl.h>

int			first_point(t_sqrt *max)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_str)
	{
		j = 0;
		while (j < g_col - 1)
		{
			if (g_map[i][j] == g_chars[0])
			{
				max->x = j;
				max->y = i;
				return (0);
			}
			++j;
		}
		++i;
	}
	return (1);
}

int			check_f(int check)
{
	if (check == 0)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	if (check == 2)
	{
		write(2, "\nmap error\n", 10);
		return (0);
	}
	return (1);
}

void		body(char *ar)
{
	t_sqrt	*max;
	t_point *point;
	int		check;

	point = create_point(0, 0);
	max = create_sqrt(0, 0, point->x, point->y);
	check = create_map(ar);
	if (check_f(check) == 0)
	{
		return ;
	}
	if (first_point(max))
	{
		print_map();
		free_map();
		return ;
	}
	else
	{
		max = read_map(0, 0, max, point);
		fill_map(max);
		print_map();
		free_map();
	}
}

int			main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc < 2)
	{
		create_map_na();
		body("input");
	}
	else
	{
		while (argv[i])
		{
			body(argv[i]);
			++i;
		}
	}
	return (0);
}
