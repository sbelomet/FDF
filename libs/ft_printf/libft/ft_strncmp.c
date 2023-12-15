/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:40:00 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/15 14:53:33 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
int	main(void)
{
	char	s1[50] = "flapjack";
	char	s201[50] = "flapjack";
	char	s202[50] = "fla";
	char	s203[50] = "flapjacks";
	char	s204[50] = "flapjck";

	printf("s201: %d\n", ft_strncmp("abcdefgh", "abcdwxyz", 4));
	printf("s202: %d\n", ft_strncmp("zyxbcdefgh", "abcdwxyz", 0));
	printf("s203: %d\n", ft_strncmp("abcdefgh", "", 0));
	printf("s204: %d\n", ft_strncmp("test\200", "test\0", 6));
}*/
