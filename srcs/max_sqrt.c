/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_sqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:36:14 by jschille          #+#    #+#             */
/*   Updated: 2018/11/07 21:23:54 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_sqrt.h"

t_sqrt	*sqrt_copy(t_sqrt *s1, t_sqrt *s2)
{
	s1->x = s2->x;
	s1->y = s2->y;
	s1->lenx = s2->lenx;
	s1->leny = s2->leny;
	return (s1);
}

t_sqrt	*max_sqrt(t_sqrt *s1, t_sqrt *s2)
{
	if (s1->lenx < s2->lenx)
		return (sqrt_copy(s1, s2));
	else if (s1->lenx > s2->lenx)
		return (s1);
	else
	{
		if (s1->y < s2->y)
			return (s1);
		else if (s1->y > s2->y)
			return (sqrt_copy(s1, s2));
		else
		{
			if (s1->x <= s2->x)
				return (s1);
			return (sqrt_copy(s1, s2));
		}
	}
}
