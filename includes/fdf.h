/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:04:58 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/14 15:04:28 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libs/minilibx_macos/mlx.h"
# include "../libs/ft_printf/include/ft_printf.h"
# include "../libs/ft_printf/include/libft.h"
# include "get_next_line.h"
# include <math.h>
# include <stdlib.h>

# define TITLE " -| Fil De Fer |- "

# define WIDTH 720
# define HEIGHT 720

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_COMMA 43
# define KEY_PERIOD 47
# define KEY_ESC 53
# define MOUSE_L 1
# define MOUSE_R 2
# define MOUSEW_UP 4
# define MOUSEW_DOWN 5
# define MOUSE_M 3

typedef struct s_coord
{
	int				basex;
	int				basey;
	int				basez;
	double			x;
	double			y;
	double			z;
	int				linebreak;
	int				color;
	struct s_coord	*down;
	struct s_coord	*next;
}					t_coord;

typedef struct s_usrin
{
	double	altitude;
	double	zoom;
	double	anglex;
	double	angley;
	double	anglez;
	int		xshift;
	int		yshift;
	int		mousebtn;
}			t_usrin;

typedef struct s_base
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
	int			size_line;
	int			bitsperpix;
	int			endian;
	int			fd;
	t_coord		*coords;
	t_usrin		*usrin;
}				t_base;

/* Error Handling */
void	ft_error(char *message);

/* Hooks Handling */
void	ft_hooks(t_base *base);
int		ft_close_win(void *param);
int 	ft_on_mouse_up(int button, int x, int y, void *param);
int 	ft_on_mouse_down(int button, int x, int y, void *param);
int		ft_on_mouse_move(int x, int y, void *param);

/* Coords Utils */
t_coord	*ft_get_coords(int fd, t_base *base);
int		get_color(char *z);
t_coord	*ft_last_coord(t_coord *coords);
void	ft_reset_coords(t_base *base);

/* Drawing */
void	ft_draw(t_base *base);
void	ft_draw_line(t_coord p1, t_coord p2, t_base *base);
void	ft_pixel_put(t_base *base, int x, int y, int color);

/* Rotation Matrices */
void	ft_rotatex(t_coord **coords, double angle);
void	ft_rotatey(t_coord **coords, double angle);
void	ft_rotatez(t_coord **coords, double angle);
void	ft_rotation(t_base *base);

#endif