/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:01:11 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/13 15:38:03 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_base	*ft_init(int fd)
{
	t_base	*base;

	base = (t_base *)malloc(sizeof(t_base));
	if (!base)
		ft_error("Malloc failure (base)");
	base->fd = fd;
	base->mlx_ptr = mlx_init();
	if (!base->mlx_ptr)
		ft_error("MLX initialisation failure");
	base->win_ptr = mlx_new_window(base->mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!base->win_ptr)
		ft_error("Window initialisation failure");
	base->img_ptr = mlx_new_image(base->mlx_ptr, WIDTH, HEIGHT);
	if (!base->img_ptr)
		ft_error("Image initialisation failure");
	base->img_data = mlx_get_data_addr(base->img_ptr, &base->bitsperpix,
			&base->size_line, &base->endian);
	base->coords = NULL;
	return (base);
}

t_usrin	*ft_usrin_init()
{
	t_usrin	*usrin;

	usrin = (t_usrin *)malloc(sizeof(t_usrin));
	if (!usrin)
		ft_error("Malloc failure (usrin)");
	usrin->altitude = 1;
	usrin->zoom = 3;
	usrin->xshift = WIDTH >> 1;
	usrin->yshift = HEIGHT >> 1;
	usrin->mousebtn = 0;
	return (usrin);
}

int	main(int ac, char **av)
{
	int		fd;
	t_base	*base;

	if (ac != 2)
		ft_error("Correct usage is ./fdf <path/map.fdf>");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("Couldn't open file");
	base = ft_init(fd);
	base->usrin = ft_usrin_init();
	ft_hooks(base);
	base->coords = ft_get_coords(base->fd, base);
	ft_draw(base);
	mlx_loop(base->mlx_ptr);
}
