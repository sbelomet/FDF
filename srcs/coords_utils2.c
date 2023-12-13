/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:38:46 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/13 14:07:58 by sbelomet         ###   ########.fr       */
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

int	ft_atoi_hex(char *s)
{
	int		i;
	char	c;
	int		res;

	res = 0;
	ft_revstr(s);
	i = 0;
	while (i < 6)
	{
		c = ft_toupper(s[i]);
		if (c >= '0' && c <= '9')
			res += (c - '0') * pow(16, i);
		else if (c >= 'A' && c <= 'F')
			res += (c - 55) * pow(16, i);
		i++;
	}
	return (res);
}

int	get_color(char *z)
{
	int	i;
	int	res;

	i = 0;
	res = 0xFFFFFF;
	while (z[i])
	{
		if (z[i] == ',')
		{
			res = ft_atoi_hex(z);
			break ;
		}
		i++;
	}
	return (res);
}

void	ft_init_coords(t_base *base)
{
	t_coord	*tmp;

	tmp = base->coords;
	while (tmp)
	{
		tmp->x = tmp->basex;
		tmp->y = tmp->basey;
		tmp->z = tmp->basez;
		tmp = tmp->next;
	}
}
