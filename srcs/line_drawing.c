/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:54:57 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/19 10:50:31 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_draw_line_desc(t_coord p1, t_coord p2, t_base *base, int dx)
{
	int	dy;
	int	yi;
	int	d;
	int	x;

	dy = p2.y - p1.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy *= -1;
	}
	d = (2 * dy) - dx;
	x = p1.x;
	while (x++ < p2.x)
	{
		ft_pixel_put(base, x, p1.y, ft_color(p1, p2, x, 'x'));
		if (d > 0)
		{
			p1.y += yi;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + 2 * dy;
	}
}

static void	ft_draw_line_asc(t_coord p1, t_coord p2, t_base *base, int dx)
{
	int	dy;
	int	xi;
	int	d;
	int	y;

	dy = p2.y - p1.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx *= -1;
	}
	d = (2 * dx) - dy;
	y = p1.y;
	while (y++ < p2.y)
	{
		ft_pixel_put(base, p1.x, y, ft_color(p1, p2, y, 'y'));
		if (d > 0)
		{
			p1.x += xi;
			d = d + (2 * (dx - dy));
		}
		else
			d = d + 2 * dx;
	}
}

void	ft_draw_line(t_coord p1, t_coord p2, t_base *base)
{
	int	dx;
	int	dy;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (ft_abs(dy) < ft_abs(dx))
	{
		if (p1.x > p2.x)
			ft_draw_line_desc(p2, p1, base, (p1.x - p2.x));
		else
			ft_draw_line_desc(p1, p2, base, dx);
	}
	else
	{
		if (p1.y > p2.y)
			ft_draw_line_asc(p2, p1, base, (p1.x - p2.x));
		else
			ft_draw_line_asc(p1, p2, base, dx);
	}
}
