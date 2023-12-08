/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:18:44 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/08 16:05:51 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/* 
void	ft_pixel_put(t_basic *basic, int x, int y, int color)
{
	int	i;

	i = (x * basic->bitsperpix / 8) + (y * basic->size_line);
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
		* (int *)&basic->data[i] = color;
} */
/* 
void	ft_erase_shape(t_basic *basic)
{
	t_coord		*coords;
	t_usrinp	*userinput;

	coords = basic->coords;
	userinput = basic->usr_inputs;
	while (coords->next)
	{
		if (!coords->linebreak)
			ft_draw_line(coords->x * userinput->zoom + 300, coords->y * userinput->zoom + 200,
				coords->next->x * userinput->zoom + 300, coords->next->y * userinput->zoom + 200, *basic, 0);
		if (coords->down)
			ft_draw_line(coords->x * userinput->zoom + 300, coords->y * userinput->zoom + 200,
				coords->down->x * userinput->zoom + 300, coords->down->y * userinput->zoom + 200, *basic, 0);
		coords = coords->next;
	}
} */

void	ft_init_coords(t_base *base)
{
	t_coord	*tmp;

	tmp = base->coords;
	while (tmp)
	{
		tmp->x = tmp->basex;
		tmp->y = tmp->basey;
		tmp->z = tmp->basez;
		tmp = tmp->next;
	}
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
			ft_draw_line(*coords, *coords->next, *base);
		if (1)
			ft_draw_line(*coords, *coords->down, *base);
		mlx_pixel_put(base->mlx_ptr, base->win_ptr, coords->x, coords->y, 0xff0000);
		coords = coords->next;
		y++;
	}
	//mlx_put_image_to_window(choses.mlx_ptr, choses.win_ptr,
	//	choses.img_ptr, 0, 0);
}
