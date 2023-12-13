/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:18:44 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/13 14:09:26 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put(t_base *base, int x, int y, int color)
{
	int	pos;

	pos = (x * base->bitsperpix / 8) + (y * base->size_line);
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
		*(int *) &base->img_data[pos] = color;
}

void	ft_isorotate(t_base *base)
{
	ft_rotatex(&base->coords, -0.3490658503988);
	ft_rotatey(&base->coords, 0.3490658503988);
	ft_rotatez(&base->coords, -0.3490658503988);
}

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

void	ft_draw(t_base *base)
{
	t_coord		*coords;
	int			y;

	ft_memset(base->img_data, 0, WIDTH * HEIGHT * (base->bitsperpix / 8));
	ft_init_coords(base);
	ft_altitude(base);
	ft_isorotate(base);
	ft_zoom(base);
	ft_translate(base);
	coords = base->coords;
	y = 0;
	while (coords->next)
	{
		if (!coords->linebreak)
			ft_draw_line(*coords, *coords->next, base);
		if (coords->down)
			ft_draw_line(*coords, *coords->down, base);
		coords = coords->next;
		y++;
	}
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr,
		base->img_ptr, 0, 0);
}
