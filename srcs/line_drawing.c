/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:54:57 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/08 16:00:42 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_draw_line_desc(t_coord p1, t_coord p2, t_base base)
{
	int	dx;
	int	dy;
	int	yi;
	int	D;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy *= -1;
	}
	D = (2 * dy) - dx;
	while (p1.x++ < p2.x)
	{
		mlx_pixel_put(base.mlx_ptr, base.win_ptr, (int)p1.x, (int)p1.y, p1.color);
		if (D > 0)
		{
			p1.y += yi;
			D = D + (2 * (dy - dx));
		}
		else
			D = D + 2*dy;
	}
}

static void	ft_draw_line_asc(t_coord p1, t_coord p2, t_base base)
{
	int	dx;
	int	dy;
	int	xi;
	int	D;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx *= -1;
	}
	D = (2 * dx) - dy;
	while (p1.y++ < p2.y)
	{
		mlx_pixel_put(base.mlx_ptr, base.win_ptr, (int)p1.x, (int)p1.y, p1.color);
		if (D > 0)
		{
			p1.x += xi;
			D = D + (2 * (dx - dy));
		}
		else
			D = D + 2*dx;
	}
}

void	ft_draw_line(t_coord p1, t_coord p2, t_base base)
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
