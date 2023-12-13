/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:56:28 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/13 15:51:45 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	*ft_new_coord(int x, int y, char *z)
{
	t_coord	*res;
	int		i;

	res = (t_coord *)malloc(sizeof(t_coord));
	if (!res)
		ft_error("Malloc faliure (coord)");
	i = 0;
	res->basez = ft_atoi(z);
	res->basex = x;
	res->basey = y;
	res->linebreak = 0;
	res->color = get_color(z);
	res->next = NULL;
	res->down = NULL;
	return (res);
}

void	ft_coord_add(t_coord **coords, t_coord *new)
{
	t_coord	*last;

	if (*coords)
	{
		last = ft_last_coord(*coords);
		last->next = new;
	}
	else
	{
		*coords = new;
	}
}

void	ft_finddown(t_coord *coord, int tablen)
{
	int		i;
	t_coord	*tmp1;
	t_coord	*tmp2;
	int		flag;

	tmp1 = coord;
	flag = 0;
	while (tmp1)
	{
		i = 0;
		tmp2 = tmp1;
		while (i++ < tablen)
		{
			if (tmp2->next)
				tmp2 = tmp2->next;
			else
			{
				flag = 1;
				break ;
			}
		}
		if (!flag)
			tmp1->down = tmp2;
		tmp1 = tmp1->next;
	}
}

void	ft_print_list(t_coord *coords)
{
	t_coord	*tmp;

	tmp = coords;
	while (tmp)
	{
		ft_printf("x: %d, y: %d' z: %d, color: %d, next: %p\n",
			(int)tmp->basex, (int)tmp->basey, (int)tmp->basez, tmp->color, tmp->next);
		tmp = tmp->next;
	}
}

void	ft_get_coords_meta(t_base *base, int x, int y)
{
	t_coord	*tmp;
	int		big;

	ft_finddown(base->coords, x);
	tmp = base->coords;
	while (tmp)
	{
		tmp->basex -= x >> 1;
		tmp->basey -= y >> 1;
		tmp = tmp->next;
	}
	big = ft_max(x, y);
	ft_printf("big: %d\n", big);
	if (big <= 20)
		base->usrin->zoom = 30;
}

t_coord	*ft_get_coords(int fd, t_base *base)
{
	char	*line;
	char	**linesplit;
	int		y;
	int		x;

	y = -1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		linesplit = ft_split(line, ' ');
		y++;
		x = 0;
		while (linesplit[x])
		{
			ft_coord_add(&base->coords, ft_new_coord(x, y, linesplit[x]));
			x++;
		}
		ft_last_coord(base->coords)->linebreak = 1;
		free(line);
		ft_free_array(linesplit);
	}
	ft_get_coords_meta(base, x, y);
	return (base->coords);
}
