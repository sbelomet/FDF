/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:13:15 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/19 12:08:55 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_percent(int start, int end, int current)
{
	double	pos;
	double	total;

	pos = current - start;
	total = end - start;
	if (total == 0)
		return (1.0);
	else
		return (pos / total);
}

int	ft_get_color(int start, int end, double per)
{
	return ((int)((1 - per) * start + per * end));
}

int	ft_color(t_coord start, t_coord end, int current, char mode)
{
	int		red;
	int		green;
	int		blue;
	double	per;

	if (start.color == end.color)
		return (start.color);
	if (mode == 'x')
		per = ft_percent(start.x, end.x, current);
	else
		per = ft_percent(start.y, end.y, current);
	red = ft_get_color(start.color >> 16, end.color >> 16, per);
	green = ft_get_color((start.color >> 8) & 255, (end.color >> 8) & 255, per);
	blue = ft_get_color(start.color & 255, end.color & 255, per);
	return ((red << 16) | (green << 8) | blue);
}

void	ft_set_color(t_base *base, int key)
{
	t_coord	*tmp;

	tmp = base->coords;
	while (tmp)
	{
		if (key == KEY_ONE)
			tmp->color = tmp->basecolor;
		else if (key == KEY_TWO)
			tmp->color = palette_one(tmp->basez);
		else if (key == KEY_THREE)
			tmp->color = palette_two(tmp->per);
		else if (key == KEY_FOUR)
			tmp->color = palette_three(tmp->per);
		else if (key == KEY_FIVE)
			tmp->color = palette_four(tmp->per);
		else if (key == KEY_SIX)
			tmp->color = palette_five(tmp->per);
		tmp = tmp->next;
	}
}
