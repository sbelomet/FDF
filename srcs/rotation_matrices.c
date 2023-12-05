/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:00:00 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/05 10:58:22 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_rotatex(t_coord **coords, double angle)
{
	int		oldy;
	int		oldz;
	t_coord	*tmp;

	tmp = *coords;
	while (tmp)
	{
		oldy = tmp->y;
		oldz = tmp->z;
		tmp->y = oldy * cos(angle) + oldz * sin(angle);
		tmp->z = oldy * -sin(angle) + oldz * cos(angle);
		tmp = tmp->next;
	}
}

void	ft_rotatey(t_coord **coords, double angle)
{
	int		oldx;
	int		oldz;
	t_coord	*tmp;

	tmp = *coords;
	while (tmp)
	{
		oldx = tmp->x;
		oldz = tmp->z;
		tmp->x = oldx * cos(angle) + oldz * -sin(angle);
		tmp->z = oldx * sin(angle) + oldz * cos(angle);
		tmp = tmp->next;
	}
}

void	ft_rotatez(t_coord **coords, double angle)
{
	int		oldx;
	int		oldy;
	t_coord	*tmp;

	tmp = *coords;
	while (tmp)
	{
		oldx = tmp->x;
		oldy = tmp->y;
		tmp->x = oldx * cos(angle) + oldy * sin(angle);
		tmp->y = oldx * -sin(angle) + oldy * cos(angle);
		tmp = tmp->next;
	}
}
