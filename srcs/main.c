/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:10:11 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/28 15:39:45 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_on_click(int button, int x, int y, void *param)
{
	static int x0 = -1;
	static int y0 = -1;
	static int x1 = -1;
	static int y1 = -1;
	t_basic *basic;
	static t_palette *palette = NULL;

	if (!palette)
	{
		ft_palette_add(&palette, ft_new_color(524963));
		ft_palette_add(&palette, ft_new_color(16731025));
		ft_palette_add(&palette, ft_new_color(16742006));
		ft_palette_add(&palette, ft_new_color(16764235));
	}

	basic = (t_basic *)param;
	if (button == 1)
	{
		x0 = x;
		y0 = y;
	}
	else if (button == 2)
	{
		x1 = x;
		y1 = y;
	}
	if (x0 > -1 && y0 > -1 && x1 > -1 && y1 > -1)
	{
		ft_draw_line(x0, y0, x1, y1, basic->mlx_ptr, basic->win_ptr, palette->color);
		palette = palette->next;
	}
	ft_printf("button: %d, x: %d, y: %d\n", button, x, y);
	return (0);
}

int	main(void)
{
	t_basic choses;

	choses.mlx_ptr = mlx_init();
	choses.win_ptr = mlx_new_window(choses.mlx_ptr, 500, 500, "mlx 42");
	
	int	i = 0;
	int j;

	while (i < 300)
	{
		j = 0;
		while (j < 300)
		{
			mlx_pixel_put(choses.mlx_ptr, choses.win_ptr, i, j, 9891839);
			j++;
		}
		i++;
	}
	mlx_string_put(choses.mlx_ptr, choses.win_ptr, 150, 150, 11735826, "HAHAHAHA");

	int	x0 = 203;
	int	y0 = 375;
	int	x1 = 281;
	int	y1 = 259;

	ft_draw_line(x0, y0, x1, y1, choses.mlx_ptr, choses.win_ptr, 3547652);
	mlx_pixel_put(choses.mlx_ptr, choses.win_ptr, x0, y0, 15503198);
	mlx_pixel_put(choses.mlx_ptr, choses.win_ptr, x1, y1, 15503198);

	mlx_mouse_hook(choses.win_ptr, ft_on_click, &choses);
	mlx_loop(choses.mlx_ptr);
}
