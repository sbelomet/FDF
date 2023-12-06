/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:17:27 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/06 12:22:53 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_strlen(const char *s);
int		ft_tablen(char **tab);
char	**ft_split(char *s, char c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(int count, int size);
void	ft_free_array(char **array);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
int		ft_abs(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

#endif
