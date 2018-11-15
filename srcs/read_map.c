/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:48:16 by jschille          #+#    #+#             */
/*   Updated: 2018/11/07 23:15:47 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_sqrt.h"
#include "t_point.h"
#include "head.h"
#include "creation.h"
#include "max_sqrt.h"

t_point			*mod_po(t_point *po, int x, int y)
{
	po->x = x;
	po->y = y;
	return (po);
}

t_point			*check_line(int x, int y, t_point *p)
{
	int			i;
	t_point		*po;

	po = (t_point*)malloc(sizeof(t_point));
	po->x = 0;
	po->y = 0;
	i = x;
	while (i >= p->x)
	{
		if (g_map[y][i] == g_chars[1])
			po = mod_po(po, i, y);
		--i;
	}
	i = y;
	while (i >= p->y)
	{
		if (g_map[i][x] == g_chars[1])
		{
			po->x = x;
			po->y = i;
		}
		--i;
	}
	return (po);
}

int				is(int x, int y)
{
	if (x >= g_col - 1 || y >= g_str)
		return (0);
	return (1);
}

t_sqrt			*read_map(int xt, int yt, t_sqrt *max, t_point *point)
{
	t_sqrt		*tmp;
	t_point		*po;

	if (is(xt, yt) == 0 || max->lenx > g_col - 1 - xt || max->leny > g_str - yt)
	{
		free(point);
		return (max);
	}
	po = check_line(xt, yt, point);
	if (po->x == 0 && po->y == 0 && g_map[yt][xt] != g_chars[1])
	{
		tmp = create_sqrt(point->x, point->y, xt, yt);
		max = max_sqrt(max, tmp);
		free(tmp);
		return (read_map(xt + 1, yt + 1, max, point));
	}
	else
	{
		tmp = max_sqrt(read_map(po->x + 1, point->y, max,
		create_point(po->x + 1, point->y)), read_map(point->x, po->y + 1,
		max, create_point(point->x, po->y + 1)));
		max = max_sqrt(max, tmp);
		free(point);
		return (max);
	}
}
