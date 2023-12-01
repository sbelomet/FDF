/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:18:44 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/01 14:53:57 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_coords(t_basic choses, double angle)
{
	t_coord	*coords;
	int		x;
	int		y;
	int		z;

	(void)angle;
	coords = choses.coords;
	while (coords)
	{
		x = coords->x * (sqrt(2) / 2) + coords->y * 0 + coords->z * -(sqrt(2) / 2);
		y = coords->x * (sqrt(6) / 6) + coords->y * (sqrt(6) / 3) + coords->z * (sqrt(6) / 6);
		z = coords->x * (sqrt(3) / 3) + coords->y * -(sqrt(3) / 3) + coords->z * (sqrt(3) / 3);
		mlx_pixel_put(choses.mlx_ptr, choses.win_ptr, x + 100, y + 100, 11735826);
		ft_printf("\n");
		ft_printf("x: %d, y: %d, z: %d\n", coords->x, coords->y, coords->z);
		ft_printf("x: %d, y: %d, z: %d\n", x, y, z);
		coords = coords->next;
	}
}
