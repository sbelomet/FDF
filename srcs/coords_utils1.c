/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:45:29 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/07 14:45:03 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_coord	*ft_last_coord(t_coord **coords)
{
	t_coord	*tmp;

	tmp = *coords;
	ft_printf("i cry %p %p\n", tmp, tmp->next);
	while (tmp->next)
	{
		ft_printf("fun\n");
		tmp = tmp->next;
		ft_printf("gogogogogo\n");
	}
	ft_printf("no way its you\n");
	return (tmp);
}

t_coord	*ft_new_coord(int x, int y, int z)
{
	t_coord	*res;

	res = (t_coord *)malloc(sizeof(t_coord));
	if (!res)
		return (NULL);
	ft_printf("im sorrrryyyyy\n");
	res->basex = x;
	res->basey = y;
	res->basez = z;
	res->x = x;
	res->y = y;
	res->z = z;
	res->linebreak = 0;
	res->down = NULL;
	res->next = NULL;
	ft_printf("where are you\n");
	return (res);
}

void	ft_coord_add(t_coord **coords, t_coord *new)
{
	t_coord	*last;

	ft_printf("fuck all of this %p\n", *coords);
	if (*coords)
	{
		ft_printf("lemme kil em kill em\n");
		last = ft_last_coord(coords);
		last->next = new;
		ft_printf("imma kill em\n");
	}
	else
	{
		*coords = new;
		ft_printf("death is what i bring\n");
	}
}

void	ft_finddown(t_coord **coord, int tablen)
{
	int		i;
	t_coord	*tmp1;
	t_coord	*tmp2;

	tmp1 = *coord;
	while (tmp1)
	{
		i = 0;
		tmp2 = tmp1;
		while (i++ < tablen)
		{
			if (tmp2->next)
				tmp2 = tmp2->next;
			else
				break ;
		}
		tmp1->down = tmp2;
		tmp1 = tmp1->next;
	}
}

t_coord	*ft_get_coords(int fd)
{
	char	*line;
	char	**linesplit;
	int		y;
	int		x;
	t_coord	*coords;

	y = -1;
	ft_printf("inside getcoord\n");
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
			ft_printf("waitawitaiwit\n");
			ft_coord_add(&coords, ft_new_coord(x, y, ft_atoi(linesplit[x])));
			ft_printf("inside getcoordAAAAAAAA\n");
			x++;
		}
		ft_last_coord(&coords)->linebreak = 1;
		free(line);
		ft_free_array(linesplit);
	}
	ft_printf("we ball?????\n");
	ft_finddown(&coords, x);
	return (coords);
}
