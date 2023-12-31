/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:10:11 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/07 14:38:47 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_close_win(void *param)
{
	t_basic	*basic;

	basic = (t_basic *)param;
	mlx_destroy_window(basic->mlx_ptr, basic->win_ptr);
	exit(0);
}

int	ft_on_press(int key, void *param)
{
	t_basic 		*basic;
	t_coord			*coords;
	static double	angle = 0;

	basic = (t_basic *)param;
	coords = basic->coords;
	ft_printf("key: %d\n", key);
	if (key == 53)
		ft_close_win(basic);
	if (key == 126)
	{
		angle -= 0.01;
		ft_erase_shape(basic);
		ft_reset_coords(&coords);
		ft_rotatex(&coords, angle);
		//ft_zoom(*basic);
		ft_draw_coords(*basic);
	}
	if (key == 125)
	{
		angle += 0.01;
		ft_erase_shape(basic);
		ft_reset_coords(&coords);
		ft_rotatex(&coords, angle);
		//ft_zoom(*basic);
		ft_draw_coords(*basic);
	}
	return (0);
} 

int	ft_anim(void *param)
{
	t_basic 		*basic;
	t_coord			*coords;
	static double	angle = 0;

	basic = (t_basic *)param;
	coords = basic->coords;
	angle += 0.01;
	ft_erase_shape(basic);
	ft_reset_coords(&coords);
	ft_rotatex(&coords, angle);
	ft_rotatey(&coords, angle);
	ft_rotatez(&coords, angle);
	//ft_zoom(*basic);
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
	t_coord			*coords;

	if (!palette)
	{
		ft_palette_add(&palette, ft_new_color(524963));
		ft_palette_add(&palette, ft_new_color(16731025));
		ft_palette_add(&palette, ft_new_color(16742006));
		ft_palette_add(&palette, ft_new_color(16764235));
	}

	basic = (t_basic *)param;
	coords = basic->coords;	
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
		ft_draw_line(x0, y0, x1, y1, *basic, palette->color);
		palette = palette->next;
	}
	ft_printf("button: %d, x: %d, y: %d\n", button, x, y);

	if (button == 4)
	{
		ft_erase_shape(basic);
		basic->usr_inputs->zoom++;
		//ft_zoom(*basic);
		ft_draw_coords(*basic);
	}
	if (button == 5)
	{
		ft_erase_shape(basic);
		basic->usr_inputs->zoom--;
		//ft_zoom(*basic);
		ft_draw_coords(*basic);
	}
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
	choses.mlx_ptr = mlx_init();
	choses.win_ptr = mlx_new_window(choses.mlx_ptr, 720, 720, "FDF HAHAHAHAHAHAHA");
	//choses.img_ptr = mlx_new_image(choses.mlx_ptr, 720, 720);
	ft_printf("AAAAAAAAA\n");
	//choses.data = mlx_get_data_addr(choses.img_ptr, &choses.bitsperpix, &choses.size_line, &choses.endian);
	ft_printf("BBBBBBB\n");
	choses.coords = ft_get_coords(choses.fd);
	ft_printf("wawawawawawawawawa\n");
	choses.usr_inputs = (t_usrinp *)malloc(sizeof(t_usrinp));
	choses.usr_inputs->zoom = 20;
	ft_printf("scared \n");
	ft_isobaserot(choses);
	//ft_zoom(choses);
	ft_printf("CCCCCCC\n");
	ft_draw_coords(choses);
	mlx_mouse_hook(choses.win_ptr, ft_on_click, &choses);
	mlx_key_hook(choses.win_ptr, ft_on_press, &choses);
	//mlx_loop_hook(choses.mlx_ptr, ft_anim, &choses);
	mlx_hook(choses.win_ptr, 17, 0, ft_close_win, &choses);
	mlx_loop(choses.mlx_ptr);
}
