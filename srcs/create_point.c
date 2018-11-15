/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:26:06 by jschille          #+#    #+#             */
/*   Updated: 2018/11/07 20:01:41 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_point.h"

t_point	*create_point(int tx, int ty)
{
	t_point	*ptr;

	ptr = (t_point*)malloc(sizeof(t_point));
	if (ptr == 0)
		return (0);
	ptr->x = tx;
	ptr->y = ty;
	return (ptr);
}
