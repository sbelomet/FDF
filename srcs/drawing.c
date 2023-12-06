/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:18:44 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/06 13:20:17 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_erase_shape(t_basic *basic)
{
	t_coord	*coords;

	coords = basic->coords;
	while (coords->next)
	{
		if (!coords->linebreak)
			ft_draw_line(coords->x + 300, coords->y + 200, coords->next->x + 300, coords->next->y + 200, basic->mlx_ptr, basic->win_ptr, 0);
		if (coords->down)
			ft_draw_line(coords->x + 300, coords->y + 200, coords->down->x + 300, coords->down->y + 200, basic->mlx_ptr, basic->win_ptr, 0);
		coords = coords->next;
	}
}

void	ft_draw_coords(t_basic choses)
{
	t_coord	*coords;

	coords = choses.coords;
	while (coords->next)
	{
		if (!coords->linebreak)
			ft_draw_line(coords->x + 300, coords->y + 200, coords->next->x + 300, coords->next->y + 200, choses.mlx_ptr, choses.win_ptr, 11735826);
		if (coords->down)
			ft_draw_line(coords->x + 300, coords->y + 200, coords->down->x + 300, coords->down->y + 200, choses.mlx_ptr, choses.win_ptr, 11735826);
		coords = coords->next;
	}
}
