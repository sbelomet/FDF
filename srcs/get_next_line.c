/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:12:12 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/29 11:11:35 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*read_to_break(char *stash, int fd)
{
	char	*buffer;
	int		nbchars;
	char	*res_stash;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	nbchars = BUFFER_SIZE;
	while ((ft_strchr(buffer, '\n') == -1) && nbchars == BUFFER_SIZE)
	{
		nbchars = read(fd, buffer, BUFFER_SIZE);
		if (nbchars < 0)
		{
			free(buffer);
			if (stash)
				free(stash);
			return (NULL);
		}
		buffer[nbchars] = '\0';
		res_stash = stash;
		stash = ft_strjoin(res_stash, buffer);
		free(res_stash);
	}
	free(buffer);
	return (stash);
}

char	*get_linetobreak(char *stash)
{
	int		lentolb;
	char	*res_line;

	lentolb = 0;
	while (stash[lentolb] != '\n' && stash[lentolb])
		lentolb++;
	if (!stash || *stash == '\0')
		return (NULL);
	res_line = ft_substr(stash, 0, (size_t)lentolb + 1);
	return (res_line);
}

char	*clean_stash(char *stash)
{
	char	*res_stash;
	int		lentolb;

	lentolb = 0;
	while (stash[lentolb] && stash[lentolb] != '\n')
		lentolb++;
	if (!stash[lentolb])
	{
		free(stash);
		return (NULL);
	}
	res_stash = ft_substr(stash, ft_strchr(stash, '\n') + 1,
			ft_strlen(stash) - ft_strchr(stash, '\n'));
	if (!*res_stash)
	{
		free(res_stash);
		free(stash);
		return (NULL);
	}
	free(stash);
	return (res_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*res;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stash = read_to_break(stash, fd);
	if (!stash)
		return (NULL);
	res = get_linetobreak(stash);
	stash = clean_stash(stash);
	return (res);
}
/*
int	main(void)
{
	int	fd;
	char	*res;
	int		i = 1;

	fd = open("test.txt", O_RDONLY);
	while (i < 10)
	{
		res = get_next_line(fd);
		if (res)
			printf("%d: |%s|\n", i, res);
		i++;
	}
	printf("lest: |%s|\n", res);
}*/
