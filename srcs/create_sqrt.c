/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sqrt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:07:33 by jschille          #+#    #+#             */
/*   Updated: 2018/11/07 21:22:26 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_sqrt.h"
#include <stdlib.h>

t_sqrt	*create_sqrt(int x, int y, int px, int py)
{
	t_sqrt	*pt;

	pt = (t_sqrt *)malloc(sizeof(t_sqrt));
	if (pt == NULL)
		return (0);
	pt->x = x;
	pt->y = y;
	pt->lenx = px - x;
	pt->leny = py - y;
	return (pt);
}
