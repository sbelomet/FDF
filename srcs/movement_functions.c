/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:09:49 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/15 14:10:21 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_base *base)
{
	t_coord	*tmp;

	tmp = base->coords;
	while (tmp)
	{
		tmp->x *= base->usrin->zoom;
		tmp->y *= base->usrin->zoom;
		tmp = tmp->next;
	}
}

void	ft_altitude(t_base *base)
{
	t_coord	*tmp;

	tmp = base->coords;
	while (tmp)
	{
		tmp->z *= base->usrin->altitude;
		tmp = tmp->next;
	}
}

void	ft_translate(t_base *base)
{
	t_coord	*tmp;

	tmp = base->coords;
	while (tmp)
	{
		tmp->x += (double)base->usrin->xshift;
		tmp->y += (double)base->usrin->yshift;
		tmp = tmp->next;
	}
}
