/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:04:58 by sbelomet          #+#    #+#             */
/*   Updated: 2023/12/19 13:46:32 by sbelomet         ###   ########.fr       */
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

# define TITLE "-| Fil De Fer |-"

# define WIDTH 1000
# define HEIGHT 720
# define A_WIDTH 300
# define A_HEIGHT 400

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_COMMA 43
# define KEY_PERIOD 47
# define KEY_ESC 53
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_FIVE 23
# define KEY_SIX 22
# define KEY_N_ONE 83
# define KEY_N_THREE 85
# define KEY_N_SEVEN 89

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
	int				basecolor;
	int				color;
	double			per;
	struct s_coord	*down;
	struct s_coord	*next;
}					t_coord;

typedef struct s_usrin
{
	double	altitude;
	double	zoom;
	double	basezoom;
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
	int			max;
	int			min;
	t_coord		*coords;
	t_usrin		*usrin;
}				t_base;

/* Error Handling */
void	ft_error(char *message);

/* Hooks Handling */
void	ft_hooks(t_base *base);
int		ft_close_win(void *param);
int		ft_on_mouse_up(int button, int x, int y, void *param);
int		ft_on_mouse_down(int button, int x, int y, void *param);
int		ft_on_mouse_move(int x, int y, void *param);
void	ft_key_altitude(t_base *base, int key);
void	ft_key_rotate(t_base *base, int key);
void	ft_key_view(t_base *base, int key);

/* Coords Utils */
t_coord	*ft_get_coords(int fd, t_base *base);
int		get_color(char *z);
t_coord	*ft_last_coord(t_coord *coords);
void	ft_reset_coords(t_base *base);
void	ft_max_points(t_base *base);
void	ft_get_percent(t_base *base);

/* Drawing */
void	ft_draw(t_base *base);
void	ft_draw_line(t_coord p1, t_coord p2, t_base *base);
void	ft_pixel_put(t_base *base, int x, int y, int color);
void	ft_draw_menu(t_base *base);

/* Color */
int		ft_color(t_coord start, t_coord end, int current, char mode);
void	ft_set_color(t_base *base, int key);
double	ft_percent(int start, int end, int current);

/* Movement */
void	ft_altitude(t_base *base);
void	ft_zoom(t_base *base);
void	ft_translate(t_base *base);

/* Rotation Matrices */
void	ft_rotatex(t_coord **coords, double angle);
void	ft_rotatey(t_coord **coords, double angle);
void	ft_rotatez(t_coord **coords, double angle);
void	ft_rotation(t_base *base);

/* Palettes */
int		palette_one(int z);
int		palette_two(double percent);
int		palette_three(double percent);
int		palette_four(double percent);
int		palette_five(double percent);

#endif