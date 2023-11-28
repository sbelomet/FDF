/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:49:16 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/28 15:45:36 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_palette	*ft_new_color(int color)
{
	t_palette	*res;

	res = (t_palette *)malloc(sizeof(t_palette));
	if (!res)
		return (NULL);
	res->color = color;
	return (res);
}

void	ft_palette_add(t_palette **palette, t_palette *new)
{
	t_palette	*last;

	if (*palette)
	{
		last = (*palette)->prev;
		(*palette)->prev = new;
		new->next = *palette;
		last->next = new;
		new->prev = last;
	}
	else
	{
		*palette = new;
		(*palette)->prev = *palette;
		(*palette)->next = *palette;
	}
}
