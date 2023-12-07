/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:54:57 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/07 14:37:49 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_draw_line_desc(int x0, int y0, int x1, int y1, t_basic basic, int color)
{
	int	dx;
	int	dy;
	int	yi;
	int	D;

	dx = x1 - x0;
	dy = y1 - y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy *= -1;
	}
	D = (2 * dy) - dx;
	while (x0++ < x1)
	{
		mlx_pixel_put(basic.mlx_ptr, basic.win_ptr, x0, y0, color);
		//ft_pixel_put(&basic, x0, y0, color);
		if (D > 0)
		{
			y0 += yi;
			D = D + (2 * (dy - dx));
		}
		else
			D = D + 2*dy;
	}
}

static void	ft_draw_line_asc(int x0, int y0, int x1, int y1, t_basic basic, int color)
{
	int	dx;
	int	dy;
	int	xi;
	int	D;

	dx = x1 - x0;
	dy = y1 - y0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx *= -1;
	}
	D = (2 * dx) - dy;
	while (y0++ < y1)
	{
		mlx_pixel_put(basic.mlx_ptr, basic.win_ptr, x0, y0, color);
		//ft_pixel_put(&basic, x0, y0, color);
		if (D > 0)
		{
			x0 += xi;
			D = D + (2 * (dx - dy));
		}
		else
			D = D + 2*dx;
	}
}

void	ft_draw_line(int x0, int y0, int x1, int y1, t_basic basic, int color)
{
	int	dx;
	int	dy;

	dx = x1 - x0;
	dy = y1 - y0;
	ft_printf("yoyo\n");
	if (ft_abs(dy) < ft_abs(dx))
	{
		if (x0 > x1)
			ft_draw_line_desc(x1, y1, x0, y0, basic, color);
		else
			ft_draw_line_desc(x0, y0, x1, y1, basic, color);
	}
	else
	{
		if (y0 > y1)
			ft_draw_line_asc(x1, y1, x0, y0, basic, color);
		else
			ft_draw_line_asc(x0, y0, x1, y1, basic, color);
	}
}
