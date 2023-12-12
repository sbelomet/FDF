/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:34:51 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/12 12:08:53 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close_win(void *param)
{
	t_base	*base;
	t_coord	*tmp1;
	t_coord	*tmp2;

	base = (t_base *)param;
	mlx_destroy_image(base->mlx_ptr, base->img_ptr);
	mlx_destroy_window(base->mlx_ptr, base->win_ptr);
	tmp1 = base->coords;
	if (tmp1)
	{
		while (tmp1->next)
		{
			tmp2 = tmp1->next;
			free(tmp1);
			tmp1 = tmp2;
		}
	}
	free(base->usrin);
	free(base->mlx_ptr);
	free(base);
	exit(0);
}

int	ft_on_key_down(int key, void *param)
{
	t_base	*base;

	base = (t_base *)param;
	ft_printf("key: %d\n", key);
	if (key == KEY_ESC)
		ft_close_win(base);
	else if (key == KEY_UP)
		base->usrin->altitude += 0.01;
	else if (key == KEY_DOWN)
		base->usrin->altitude -= 0.01;
	ft_draw(base);
	return (0);
}

void	ft_hooks(t_base *base)
{
	mlx_hook(base->win_ptr, 17, 0, ft_close_win, base);
	mlx_hook(base->win_ptr, 2, 0, ft_on_key_down, base);
}
