/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:54:57 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/12 15:28:57 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_grad(int current, t_coord start, t_coord end)
{
	double	fac;
	int		red;
	int		green;
	int		blue;

	if (start.color == end.color)
		return (start.color);
	fac = ft_abs((double)current - start.y) / ft_abs(end.y - start.y);
	printf("fac: %f\n", fac);
	red = ft_abs((start.color >> 16) - (end.color >> 16));
	green = ft_abs(((start.color >> 8) & 255) - ((end.color >> 8) & 255));
	blue = ft_abs((start.color & 255) - (end.color & 255));
	red *= fac;
	green *= fac;
	blue *= fac;
	red += ft_abs(start.color >> 16);
	green += ft_abs((start.color >> 8) & 255);
	blue += ft_abs(start.color & 255);
	return ((red << 16) | (green << 8) | blue);
}

static void	ft_draw_line_desc(t_coord p1, t_coord p2, t_base *base)
{
	int	dx;
	int	dy;
	int	yi;
	int	d;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy *= -1;
	}
	d = (2 * dy) - dx;
	while (p1.x++ < p2.x)
	{
		ft_pixel_put(base, p1.x, p1.y, ft_grad(p1.x, p1, p2));
		//ft_pixel_put(base, p1.x, p1.y, p1.color);
		if (d > 0)
		{
			p1.y += yi;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + 2 * dy;
	}
}

static void	ft_draw_line_asc(t_coord p1, t_coord p2, t_base *base)
{
	int	dx;
	int	dy;
	int	xi;
	int	d;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx *= -1;
	}
	d = (2 * dx) - dy;
	while (p1.y++ < p2.y)
	{
		ft_pixel_put(base, p1.x, p1.y, ft_grad(p1.y, p1, p2));
		//ft_pixel_put(base, p1.x, p1.y, p1.color);
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
			ft_draw_line_desc(p2, p1, base);
		else
			ft_draw_line_desc(p1, p2, base);
	}
	else
	{
		if (p1.y > p2.y)
			ft_draw_line_asc(p2, p1, base);
		else
			ft_draw_line_asc(p1, p2, base);
	}
}
