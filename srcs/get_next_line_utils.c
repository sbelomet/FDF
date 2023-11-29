/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:13:28 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/29 11:11:33 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_strchr(char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (s && (i < len + 1))
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		tlen;
	int		i;
	char	*res;

	len_s1 = ft_strlen(s1);
	tlen = len_s1 + ft_strlen(s2);
	res = (char *)malloc(tlen * sizeof(char) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		res[len_s1 + i] = s2[i];
		i++;
	}
	res[len_s1 + i] = '\0';
	return (res);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*res;
	int		strlen;

	i = 0;
	strlen = ft_strlen(s);
	if (len > strlen)
		len = strlen;
	res = (char *)malloc(len * sizeof(char) + 1);
	if (!res)
		return (NULL);
	if (start < strlen)
	{
		while (s[i + start] && i < len)
		{
			res[i] = s[i + start];
			i++;
		}
	}
	res[i] = '\0';
	return (res);
}
