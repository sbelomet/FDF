/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:26:12 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/19 11:10:50 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_on_mouse_up(int button, int x, int y, void *param)
{
	t_base	*base;

	base = (t_base *)param;
	base->usrin->mousebtn = 0;
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

void	ft_mouse_action(int button, t_base *base)
{
	if (button == MOUSEW_UP)
		base->usrin->zoom += 1;
	else if (button == MOUSEW_DOWN)
		base->usrin->zoom -= 1;
	else if (button == MOUSE_M)
	{
		base->usrin->altitude = 1;
		base->usrin->zoom = base->usrin->basezoom;
		base->usrin->xshift = ((WIDTH - A_WIDTH) >> 1) + A_WIDTH;
		base->usrin->yshift = (HEIGHT >> 2) * 3;
		base->usrin->anglex = -0.829066;
		base->usrin->angley = 0.489066;
		base->usrin->anglez = -0.259066;
		ft_set_color(base, KEY_ONE);
	}
	if (base->usrin->zoom < 0)
		base->usrin->zoom = 0;
	ft_draw(base);
}

int	ft_on_mouse_down(int button, int x, int y, void *param)
{
	t_base	*base;

	base = (t_base *)param;
	base->usrin->mousebtn = button;
	if (button == MOUSEW_UP || button == MOUSEW_DOWN || button == MOUSE_M)
		ft_mouse_action(button, base);
	(void)x;
	(void)y;
	return (0);
}

void	ft_mouse_translate(t_base *base, int x, int y, int *start)
{
	if (start[0] != -1)
	{
		base->usrin->xshift += x - start[0];
		base->usrin->yshift += y - start[1];
	}
	start[0] = x;
	start[1] = y;
	ft_draw(base);
}

int	ft_on_mouse_move(int x, int y, void *param)
{
	t_base		*base;
	static int	start[] = {-1, -1};

	base = (t_base *)param;
	if (base->usrin->mousebtn == MOUSE_R)
		ft_mouse_translate(base, x, y, start);
	else if (base->usrin->mousebtn == MOUSE_L)
	{
		if (start[0] != -1)
		{
			base->usrin->angley -= (double)(x - start[0]) / 100;
			base->usrin->anglex += (double)(y - start[1]) / 100;
		}
		start[0] = x;
		start[1] = y;
		ft_draw(base);
	}
	else if (start[0] != -1)
	{
		start[0] = -1;
		start[1] = -1;
	}
	return (0);
}
