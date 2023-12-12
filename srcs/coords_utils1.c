/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:56:28 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/12 12:10:15 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	*ft_last_coord(t_coord *coords)
{
	t_coord	*tmp;

	tmp = coords;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

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

t_coord	*ft_get_coords(int fd, t_coord *coords)
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
			ft_coord_add(&coords, ft_new_coord(x, y, linesplit[x]));
			x++;
		}
		ft_last_coord(coords)->linebreak = 1;
		free(line);
		ft_free_array(linesplit);
	}
	ft_finddown(coords, x);
	return (coords);
}
