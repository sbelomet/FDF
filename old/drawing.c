/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:18:44 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/08 09:58:12 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_pixel_put(t_basic *basic, int x, int y, int color)
{
	int	i;

	i = (x * basic->bitsperpix / 8) + (y * basic->size_line);
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
		* (int *)&basic->data[i] = color;
}

void	ft_erase_shape(t_basic *basic)
{
	t_coord		*coords;
	t_usrinp	*userinput;

	coords = basic->coords;
	userinput = basic->usr_inputs;
	while (coords->next)
	{
		if (!coords->linebreak)
			ft_draw_line(coords->x * userinput->zoom + 300, coords->y * userinput->zoom + 200,
				coords->next->x * userinput->zoom + 300, coords->next->y * userinput->zoom + 200, *basic, 0);
		if (coords->down)
			ft_draw_line(coords->x * userinput->zoom + 300, coords->y * userinput->zoom + 200,
				coords->down->x * userinput->zoom + 300, coords->down->y * userinput->zoom + 200, *basic, 0);
		coords = coords->next;
	}
}

void	ft_draw_coords(t_basic choses)
{
	t_coord		*coords;
	t_usrinp	*userinput;

	coords = choses.coords;
	userinput = choses.usr_inputs;
	ft_printf("draw coords\n");
	while (coords->next)
	{
		if (!coords->linebreak)
			ft_draw_line(coords->x * userinput->zoom + 300, coords->y * userinput->zoom + 200,
				coords->next->x * userinput->zoom + 300, coords->next->y * userinput->zoom + 200, choses, 11735826);
		if (coords->down)
			ft_draw_line(coords->x * userinput->zoom + 300, coords->y * userinput->zoom + 200,
				coords->down->x * userinput->zoom + 300, coords->down->y * userinput->zoom + 200, choses, 11735826);
		coords = coords->next;
	}
	//mlx_put_image_to_window(choses.mlx_ptr, choses.win_ptr,
	//	choses.img_ptr, 0, 0);
}
