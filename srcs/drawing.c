/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:18:44 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/15 15:05:51 by sbelomet         ###   ########.fr       */
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

void	ft_perspective(t_base *base)
{
	t_coord	*tmp;
	double	old;

	tmp = base->coords;
	while (tmp)
	{
		old = tmp->x;
		tmp->x = (1.0 / (2.0 - tmp->z)) * old;
		old = tmp->y;
		tmp->y = (1.0 / (2.0 - tmp->z)) * old;
		tmp = tmp->next;
	}
}

void	ft_background(t_base *base, int width, int height, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			ft_pixel_put(base, x, y, color);
			y++;
		}
		x++;
	}
}

void	ft_draw(t_base *base)
{
	t_coord		*coords;
	int			y;

	ft_background(base, WIDTH, HEIGHT, 0x140c0c);
	ft_reset_coords(base);
	ft_altitude(base);
	ft_rotation(base);
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
	ft_background(base, A_WIDTH, A_HEIGHT, 0x7C4646);
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr,
		base->img_ptr, 0, 0);
	ft_draw_menu(base);
}

void	ft_draw_menu(t_base *base)
{
	mlx_string_put(base->mlx_ptr, base->win_ptr, 65, 35, 0xFFFFFF, TITLE);
	mlx_string_put(base->mlx_ptr, base->win_ptr, 25, 75, 0xFFFFFF,
		"========================");
	mlx_string_put(base->mlx_ptr, base->win_ptr, 35, 115, 0xFFFFFF,
		"COMMANDS");
	mlx_string_put(base->mlx_ptr, base->win_ptr, 35, 145, 0xFFFFFF,
		"Translate: RMB + Move");
	mlx_string_put(base->mlx_ptr, base->win_ptr, 35, 175, 0xFFFFFF,
		"Rotate: LMB + Move");
	mlx_string_put(base->mlx_ptr, base->win_ptr, 35, 205, 0xFFFFFF,
		"Tilt: < OR >");
	mlx_string_put(base->mlx_ptr, base->win_ptr, 35, 235, 0xFFFFFF,
		"Altitude: - OR +");
	mlx_string_put(base->mlx_ptr, base->win_ptr, 35, 265, 0xFFFFFF,
		"Reset: MMB");
}
