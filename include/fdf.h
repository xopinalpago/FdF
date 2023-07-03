/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:12:39 by rmeriau           #+#    #+#             */
/*   Updated: 2023/07/03 15:54:39 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define W 2000
# define H 1000

# include "../libft/libft.h"
# include "../minilibx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_param
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	err2;
	int	num_pixels;
}	t_param;

typedef struct s_Color
{
	int	r;
	int	g;
	int	b;
}	t_Color;

typedef struct s_Point2D
{
	int		x;
	int		y;
	t_Color	color;
}	t_Point2D;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	int			**map;
	int			l;
	int			c;
	t_Point2D	z_ext;
}	t_data;

int			**get_map(char *file, int l, int c);
int			get_nb_col(char *file);
int			get_size_map(char *file, t_data *data);
t_Point2D	get_min_max_z(t_data *data);

int			handle_keypress(int keysym, t_data *data);
int			close_handler(t_data *data);

t_Point2D	project_isometric(int x, int y, int z, t_data *data);
t_Point2D	except_proj(t_Point2D point2d);
void		img_pix_put(t_img *img, int x, int y, int color);

int			draw(t_Point2D a, t_Point2D b, t_img *img);
int 		draw_special(t_data *data);
void		init_param(t_Point2D p1, t_Point2D p2, t_param *param);
void		draw_line(int i, int j, t_data *data);
void		draw_col(int i, int j, t_data *data);
void		draw_line_except(int i, int j, t_data *data);
void		draw_col_except(int i, int j, t_data *data);

int			rgb_to_hex(t_Color color);
t_Color		get_color(int z, int minZ, int maxZ);
t_Color		interpol_color(t_Color color1, t_Color color2, float t);
t_Color		init_color(t_Point2D p1, t_Point2D p2, t_param param);
t_Color		step_color(t_Color color_add, t_Color color_step);

void		free_int(int **tableau, int nb_line);
void		free_char(char **tableau);
void		ft_free(t_data *data);

#endif
