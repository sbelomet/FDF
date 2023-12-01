/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:45:29 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/01 14:00:32 by sbelomet         ###   ########.fr       */
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

t_coord	*ft_get_coords(int fd)
{
	char	*line;
	char	**linesplit;
	int		y;
	int		x;
	static t_coord	*coords;
	
	y = -10;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_printf("line: %s\n", line);
		linesplit = ft_split(line, ' ');
		y += 10;
		x = 0;
		while (linesplit[x])
		{
			ft_coord_add(&coords, ft_new_coord(x * 10, y, ft_atoi(linesplit[x]) * 10));
			ft_printf("x: %d, y: %d, z: %d\n", coords->x, coords->y, coords->z);
			x++;
		}
	}
	return (coords);
}
