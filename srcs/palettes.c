/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:33:30 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/19 12:53:48 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	palette_one(int z)
{
	if (z <= -5)
		return (0x003366);
	if (z <= -2)
		return (0x1962E1);
	else if (z <= 0)
		return (0x99CCFF);
	else if (z <= 8)
		return (0x009A00);
	else if (z <= 20)
		return (0xFFB266);
	else if (z <= 25)
		return (0xC16100);
	else if (z >= 30)
		return (0x945700);
	else if (z <= 40)
		return (0x693502);
	else
		return (0xFFFFFF);
}

int	palette_two(double percent)
{
	if (percent < 0.1)
		return (0xE40303);
	else if (percent < 0.3)
		return (0xFF8C00);
	else if (percent < 0.5)
		return (0xFFED00);
	else if (percent < 0.6)
		return (0x008026);
	else if (percent < 0.8)
		return (0x24408E);
	else
		return (0x732982);
}

int	palette_three(double percent)
{
	if (percent < 0.2)
		return (0x55CDFD);
	else if (percent < 0.4)
		return (0xF6AAB7);
	else if (percent < 0.6)
		return (0xFFFFFF);
	else if (percent < 0.8)
		return (0xF6AAB7);
	else
		return (0x55CDFD);
}

int	palette_four(double percent)
{
	if (percent < 0.2)
		return (0xD42C00);
	else if (percent < 0.4)
		return (0xFD9855);
	else if (percent < 0.6)
		return (0xFFFFFF);
	else if (percent < 0.8)
		return (0xD161A2);
	else
		return (0xA20161);
}

int	palette_five(double percent)
{
	if (percent < 0.2)
		return (0xFA4288);
	else if (percent < 0.4)
		return (0);
	else if (percent < 0.6)
		return (0x71197F);
	else if (percent < 0.8)
		return (0xFFFFFF);
	else
		return (0x071195);
}
