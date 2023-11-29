/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:18:44 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/29 16:05:30 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_thing(t_basic choses, int fd)
{
	//int		size;
	t_coord	coord;
	int		flag;
	char	*line;
	char	**coords;
	int		i;
	int		x;
	int		y;
	int		z;

	flag = 0;
	y = -10;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_printf("line: %s\n", line);
		coords = ft_split(line, ' ');
		y += 10;
		i = 0;
		while (coords[i])
		{
			x = i;
			z = ft_atoi(coords[i]);
			x *= 10;
			z *= 10;
			coord.x = (x - z) / sqrt(2);
			coord.y = (x + 2 * y + z) / sqrt(6);
			mlx_pixel_put(choses.mlx_ptr, choses.win_ptr, coord.x + 70, coord.y + 70, 9891839);
			ft_printf("x: %d, y: %d, z: %d\n", x, y, z);
			ft_printf("coord.x: %d, coord.y: %d\n", coord.x, coord.y);
			i++;
		}
	}
}
