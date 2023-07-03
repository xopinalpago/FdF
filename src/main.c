/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:37:13 by rmeriau           #+#    #+#             */
/*   Updated: 2023/07/03 16:06:14 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int draw_special(t_data *data)
{
	int	i;

	i = -1;
	if (data->l == 1)
		while (++i < data->c - 1)
			draw_col(0, i, data);
	else if (data->c == 1)
		while (++i < data->l - 1)
			draw_line(i, 0, data);
	else
		return (0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (1);
}

int	render(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (data->win_ptr == NULL)
		return (1);
	if (draw_special(data))
		return(0);
	while (i < data->l - 1)
	{
		j = 0;
		while (j < data->c - 1)
		{
			draw_line(i, j, data);
			draw_col(i, j, data);
			if (i + 1 == data->l - 1)
				draw_line_except(i, j, data);
			j++;
			if (j == data->c - 1)
				draw_col_except(i, j, data);
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}

void	do_fdf(t_data win)
{
	win.mlx_ptr = mlx_init();
	if (win.mlx_ptr == NULL)
		return ;
	win.win_ptr = mlx_new_window(win.mlx_ptr, W, H, "FdF");
	if (win.win_ptr == NULL)
	{
		free(win.win_ptr);
		return ;
	}
	win.img.mlx_img = mlx_new_image(win.mlx_ptr, W, H);
	win.img.addr = mlx_get_data_addr(win.img.mlx_img, &win.img.bpp,
			&win.img.line_len, &win.img.endian);
	mlx_loop_hook(win.mlx_ptr, &render, &win);
	mlx_hook(win.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &win);
	mlx_hook(win.win_ptr, ClientMessage, NoEventMask, close_handler, &win);
	mlx_loop(win.mlx_ptr);
	mlx_destroy_image(win.mlx_ptr, win.img.mlx_img);
	mlx_destroy_display(win.mlx_ptr);
	ft_free(&win);
}

int	main(int argc, char *argv[])
{
	t_data	win;

	if (argc == 2)
	{		
		if (!get_size_map(argv[1], &win))
			return (0);
		if (win.c == 0 || win.l == 0)
			return (0);
		win.map = get_map(argv[1], win.l, win.c);
		if (!win.map)
		{
			ft_free(&win);
			return (0);
		}
		win.z_ext = get_min_max_z(&win);
		do_fdf(win);
	}
	return (0);
}
