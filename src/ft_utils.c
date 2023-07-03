/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:11:08 by rmeriau           #+#    #+#             */
/*   Updated: 2023/07/03 16:37:58 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_Point2D	get_min_max_z(t_data *data)
{
	t_Point2D	z;
	int			i;
	int			j;

	i = 0;
	j = 0;
	z.x = data->map[i][j];
	z.y = data->map[i][j];
	while (i < data->l)
	{
		j = 0;
		while (j < data->c)
		{
			if (z.x > data->map[i][j])
				z.x = data->map[i][j];
			if (z.y < data->map[i][j])
				z.y = data->map[i][j];
			j++;
		}
		i++;
	}
	return (z);
}

void	init_param(t_Point2D p1, t_Point2D p2, t_param *param)
{
	param->dx = abs(p2.x - p1.x);
	param->dy = abs(p2.y - p1.y);
	if (p1.x < p2.x)
		param->sx = 1;
	else
		param->sx = -1;
	if (p1.y < p2.y)
		param->sy = 1;
	else
		param->sy = -1;
	param->err = param->dx - param->dy;
	if (param->dx > param->dy)
		param->num_pixels = param->dx + 1;
	else
		param->num_pixels = param->dy + 1;
	param->err2 = 0;
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

int	close_handler(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}
