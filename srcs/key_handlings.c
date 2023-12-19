/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:07:27 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/19 13:13:35 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_altitude(t_base *base, int key)
{
	if (key == KEY_PLUS)
		base->usrin->altitude += 0.01;
	else if (key == KEY_MINUS)
		base->usrin->altitude -= 0.01;
}

void	ft_key_rotate(t_base *base, int key)
{
	if (key == KEY_DOWN)
		base->usrin->anglex += 0.01;
	else if (key == KEY_UP)
		base->usrin->anglex -= 0.01;
	else if (key == KEY_LEFT)
		base->usrin->angley += 0.01;
	else if (key == KEY_RIGHT)
		base->usrin->angley -= 0.01;
	else if (key == KEY_COMMA)
		base->usrin->anglez += 0.01;
	else if (key == KEY_PERIOD)
		base->usrin->anglez -= 0.01;
}

void	ft_key_view(t_base *base, int key)
{
	if (key == KEY_N_ONE)
	{
		base->usrin->anglex = -1.57;
		base->usrin->angley = 0;
		base->usrin->anglez = 0;
	}
	else if (key == KEY_N_THREE)
	{
		base->usrin->anglex = -1.5;
		base->usrin->angley = 1.57;
		base->usrin->anglez = -0.07;
	}
	else if (key == KEY_N_SEVEN)
	{
		base->usrin->anglex = 0;
		base->usrin->angley = 0;
		base->usrin->anglez = 0;
	}
}
