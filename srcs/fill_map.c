/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:02:05 by jschille          #+#    #+#             */
/*   Updated: 2018/11/07 23:10:41 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include "t_sqrt.h"

void	fill_map(t_sqrt *max)
{
	int i;
	int	j;

	i = max->y;
	while (i <= max->y + max->leny)
	{
		j = max->x;
		while ((j <= max->x + max->lenx) && j < g_col - 1)
		{
			g_map[i][j] = g_chars[2];
			++j;
		}
		++i;
	}
}
