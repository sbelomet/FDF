/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:11:02 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/01 14:19:28 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ABS(Value) ((Value<0)?(-Value):(Value))

# include "../libs/minilibx_macos/mlx.h"
# include "../libs/ft_printf/include/ft_printf.h"
# include "../libs/ft_printf/include/libft.h"
# include "get_next_line.h"
# include <math.h>

typedef struct s_palette
{
	int					color;
	struct s_palette	*prev;
	struct s_palette	*next;
}						t_palette;

typedef struct s_coord
{
	int				x;
	int				y;
	int				z;
	struct s_coord	*next;
}					t_coord;

typedef struct s_basic
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;
	t_coord	*coords;
}			t_basic;


void		ft_draw_line(int x0, int y0, int x1, int y1, void *mlx_ptr, void *win_ptr, int color);
t_palette	*ft_new_color(int color);
void		ft_palette_add(t_palette **palette, t_palette *new);
void		ft_draw_coords(t_basic choses, double angle);
t_coord		*ft_new_coord(int x, int y, int z);
void		ft_coord_add(t_coord **coord, t_coord *new);
t_coord		*ft_get_coords(int fd);

#endif