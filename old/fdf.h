/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:11:02 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/08 10:53:35 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libs/minilibx_macos/mlx.h"
# include "../libs/ft_printf/include/ft_printf.h"
# include "../libs/ft_printf/include/libft.h"
# include "get_next_line.h"
# include <math.h>

# define WIDTH 720
# define HEIGHT 720

typedef struct s_palette
{
	int					color;
	struct s_palette	*prev;
	struct s_palette	*next;
}						t_palette;

typedef struct s_coord
{
	double			x;
	double			y;
	double			z;
	double			basex;
	double			basey;
	double			basez;
	int				linebreak;
	struct s_coord	*down;
	struct s_coord	*next;
}					t_coord;

typedef struct s_usrinp
{
	int	altitude;
	int	zoom;
	int	xshift;
	int	yshift;
}		t_usrinp;

typedef struct s_basic
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*data;
	int			size_line;
	int			bitsperpix;
	int			endian;
	int			fd;
	t_coord		*coords;
	t_usrinp	*usr_inputs;
}			t_basic;

t_palette	*ft_new_color(int color);
void		ft_palette_add(t_palette **palette, t_palette *new);

/* Coords */

t_coord		*ft_new_coord(int x, int y, int z);
void		ft_coord_add(t_coord **coord, t_coord *new);
t_coord		*ft_get_coords(int fd);
void		ft_reset_coords(t_coord **coords);
void		ft_isobaserot(t_basic basic);
void		ft_zoom(t_basic basic);

/* Drawing */

void		ft_draw_line(int x0, int y0, int x1, int y1, t_basic basic, int color);
void		ft_erase_shape(t_basic *basic);
void		ft_draw_coords(t_basic choses);
void		ft_pixel_put(t_basic *basic, int x, int y, int color);

/* Rotation Matrices*/

void		ft_rotatex(t_coord **coords, double angle);
void		ft_rotatey(t_coord **coords, double angle);
void		ft_rotatez(t_coord **coords, double angle);

#endif