/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:26:12 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/13 13:17:29 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_on_mouse_up(int button, int x, int y, void *param)
{
	t_base	*base;

	base = (t_base *)param;
	base->usrin->mousebtn = 0;
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

int ft_on_mouse_down(int button, int x, int y, void *param)
{
	t_base	*base;

	base = (t_base *)param;
	base->usrin->mousebtn = button;
	ft_printf("mouse button: %d\n", button);
	if (button == MOUSEW_UP)
	{
		base->usrin->zoom += 0.5;
		ft_draw(base);
	}
	else if (button == MOUSEW_DOWN)
	{
		base->usrin->zoom -= 0.5;
		ft_draw(base);
	}
	(void)x;
	(void)y;
	return (0);
}

int	ft_on_mouse_move(int x, int y, void *param)
{
	t_base		*base;
	static int	startx = -1;
	static int	starty = -1;

	base = (t_base *)param;
	if (base->usrin->mousebtn == MOUSE_R)
	{
		ft_printf("mouse pos: %d %d\n", x, y);
		if (startx != -1)
		{
			base->usrin->xshift += x - startx;
			base->usrin->yshift += y - starty;
		}
		startx = x;
		starty = y;
		ft_draw(base);
	}
	else if (startx != -1)
	{
		startx = -1;
		starty = -1;
	}
	return (0);
}
