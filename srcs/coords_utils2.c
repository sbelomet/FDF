/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:56:32 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/06 15:35:56 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_reset_coords(t_coord **coords)
{
	t_coord	*tmp;

	tmp = *coords;
	while (tmp)
	{
		tmp->x = tmp->basex;
		tmp->y = tmp->basey;
		tmp->z = tmp->basez;
		tmp = tmp->next;
	}
}

void	ft_isobase(t_basic basic)
{
	t_coord	*tmp;

	tmp = basic.coords;
	ft_zoom(basic);
	ft_rotatex(&basic.coords, -0.34906585039886);
	ft_rotatey(&basic.coords, 0.34906585039886);
	ft_rotatez(&basic.coords, -0.34906585039886);
	while (tmp)
	{
		tmp->basex = tmp->x;
		tmp->basey = tmp->y;
		tmp->basez = tmp->z;
		tmp = tmp->next;
	}
}

void	ft_zoom(t_basic	basic)
{
	t_coord		*tmp;

	tmp = basic.coords;
	while (tmp)
	{
		tmp->x = tmp->basex * basic.usr_inputs->zoom;
		tmp->y = tmp->basey * basic.usr_inputs->zoom;
		tmp = tmp->next;
	}
}
