/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:10:11 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/05 13:19:36 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_erase_screen(t_basic *basic)
{
	int	i;
	int	j;

	i = 200;
	while (i++ < 500)
	{
		j = 0;
		while (j++ < 500)
		{
			mlx_pixel_put(basic->mlx_ptr, basic->win_ptr, i, j, 0);
		}
	}
}
 
int	ft_on_press(int key, void *param)
{
	t_basic 		*basic;
	static double	angle = 0;

	basic = (t_basic *)param;
	ft_printf("key: %d\n", key);
	if (key == 53)
		exit(0);
	if (key == 123)
	{
		angle += 0.05;
		ft_erase_screen(basic);
		ft_draw_coords(*basic);
	}
	return (0);
} 

int	ft_anim(void *param)
{
	t_basic 		*basic;
	t_coord			*coords;
	static double	angle;

	basic = (t_basic *)param;
	coords = basic->coords;
	angle -= 0.017;
	ft_erase_screen(basic);
	ft_rotatex(&coords, angle);
	ft_draw_coords(*basic);
	return (0);
}

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

int	main(int ac, char **av)
{
	t_basic choses;
	
	if (ac != 2)
	{
		ft_printf("Usage: ./fdf <map>\n");
		return (1);
	}
	choses.fd = open(av[1], O_RDONLY);
	if (choses.fd < 0)
	{
		ft_printf("ERROR: Unknown file\n");
		return (1);
	}
	
	ft_printf("av[1]: %s, fd: %d\n", av[1], choses.fd);

	choses.mlx_ptr = mlx_init();
	choses.win_ptr = mlx_new_window(choses.mlx_ptr, 720, 720, "FDF HAHAHAHAHAHAHA");

	choses.coords = ft_get_coords(choses.fd);
	
	ft_draw_coords(choses);
	mlx_mouse_hook(choses.win_ptr, ft_on_click, &choses);
	mlx_key_hook(choses.win_ptr, ft_on_press, &choses);
	//mlx_loop_hook(choses.mlx_ptr, ft_anim, &choses);
	mlx_loop(choses.mlx_ptr);
}
