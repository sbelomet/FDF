/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:18:44 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/05 14:06:45 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_coords(t_basic choses)
{
	t_coord	*coords;
	/* int		x;
	int		y;
	int		z;
 */
	coords = choses.coords;
	ft_rotatex(&coords, -0.349066);
	ft_rotatey(&coords, 0.349066);
	ft_rotatez(&coords, -0.349066);
	while (coords->next)
	{
		/* x = coords->x * (sqrt(2) / 2) + coords->y * 0 + coords->z * -(sqrt(2) / 2);
		y = coords->x * (sqrt(6) / 6) + coords->y * (sqrt(6) / 3) + coords->z * (sqrt(6) / 6);
		z = coords->x * (sqrt(3) / 3) + coords->y * -(sqrt(3) / 3) + coords->z * (sqrt(3) / 3); */
		if (!coords->linebreak)
			ft_draw_line(coords->x + 300, coords->y + 200, coords->next->x + 300, coords->next->y + 200, choses.mlx_ptr, choses.win_ptr, 11735826);
		mlx_pixel_put(choses.mlx_ptr, choses.win_ptr, coords->x + 300, coords->y + 200, 16748732);
		//ft_printf("\n");
		//ft_printf("x: %d, y: %d, z: %d\n", coords->x, coords->y, coords->z);
		//ft_printf("x: %d, y: %d, z: %d\n", x, y, z);
		coords = coords->next;
	}
}
