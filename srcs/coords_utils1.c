/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:45:29 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/05 15:47:29 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_coord	*ft_last_coord(t_coord **coords)
{
	t_coord	*tmp;

	tmp = *coords;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

t_coord	*ft_new_coord(int x, int y, int z)
{
	t_coord	*res;

	res = (t_coord *)malloc(sizeof(t_coord));
	if (!res)
		return (NULL);
	res->x = x;
	res->y = y;
	res->z = z;
	res->linebreak = 0;
	res->down = NULL;
	res->next = NULL;
	return (res);
}

void	ft_coord_add(t_coord **coords, t_coord *new)
{
	t_coord	*last;

	if (*coords)
	{
		last = ft_last_coord(coords);
		last->next = new;
	}
	else
		*coords = new;
}

t_coord	*ft_finddown(t_coord *coord, int tablen)
{
	int		i;
	t_coord	*tmp;

	i = 0;
	tmp = coord;
	while (i++ < tablen)
	{
		if (tmp->next)
			tmp = tmp->next;
		else
			return (NULL);
	}
	return (tmp);
}

t_coord	*ft_get_coords(int fd)
{
	char	*line;
	char	**linesplit;
	int		y;
	int		x;
	t_coord	*coords;

	y = -20;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_printf("line: %s\n", line);
		linesplit = ft_split(line, ' ');
		y += 20;
		x = 0;
		while (linesplit[x])
		{
			ft_coord_add(&coords, ft_new_coord(x * 20, y, ft_atoi(linesplit[x]) * 20));
			ft_printf("x: %d, y: %d, z: %d\n", coords->x, coords->y, coords->z);
			x++;
		}
		ft_last_coord(&coords)->linebreak = 1;
		free(line);
		ft_free_array(linesplit);
	}
	return (coords);
}
