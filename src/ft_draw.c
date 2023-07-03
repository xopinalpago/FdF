/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:12:23 by rmeriau           #+#    #+#             */
/*   Updated: 2023/06/30 14:51:55 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_line(int i, int j, t_data *data)
{
	t_Point2D	pa;
	t_Point2D	pb;

	pa = project_isometric(j, i, data->map[i][j], data);
	pa.color = get_color(data->map[i][j], data->z_ext.x, data->z_ext.y);
	pb = project_isometric(j, (i + 1), data->map[i + 1][j], data);
	pb.color = get_color(data->map[i + 1][j], data->z_ext.x, data->z_ext.y);
	draw(pa, pb, &data->img);
}

void	draw_col(int i, int j, t_data *data)
{
	t_Point2D	pa;
	t_Point2D	pc;

	pa = project_isometric(j, i, data->map[i][j], data);
	pa.color = get_color(data->map[i][j], data->z_ext.x, data->z_ext.y);
	pc = project_isometric((j + 1), i, data->map[i][j + 1], data);
	pc.color = get_color(data->map[i][j + 1], data->z_ext.x, data->z_ext.y);
	draw(pa, pc, &data->img);
}

void	draw_line_except(int i, int j, t_data *data)
{
	t_Point2D	pa;
	t_Point2D	pb;

	pa = project_isometric(j, i + 1, data->map[i + 1][j], data);
	pa.color = get_color(data->map[i + 1][j], data->z_ext.x, data->z_ext.y);
	pb = project_isometric(j + 1, (i + 1), data->map[i + 1][j + 1], data);
	pb.color = get_color(data->map[i + 1][j + 1], data->z_ext.x, data->z_ext.y);
	draw(pa, pb, &data->img);
}

void	draw_col_except(int i, int j, t_data *data)
{
	t_Point2D	pa;
	t_Point2D	pc;

	pa = project_isometric(j, i, data->map[i][j], data);
	pa.color = get_color(data->map[i][j], data->z_ext.x, data->z_ext.y);
	pc = project_isometric(j, (i + 1), data->map[i + 1][j], data);
	pc.color = get_color(data->map[i + 1][j], data->z_ext.x, data->z_ext.y);
	draw(pa, pc, &data->img);
}

int	draw(t_Point2D p1, t_Point2D p2, t_img *img)
{
	t_Color	color_step;
	t_param	param;

	init_param(p1, p2, &param);
	color_step = init_color(p1, p2, param);
	while (p1.x != p2.x || p1.y != p2.y)
	{
		img_pix_put(img, p1.x, p1.y, rgb_to_hex(p1.color));
		p1.color = step_color(p1.color, color_step);
		param.err2 = 2 * param.err;
		if (param.err2 > -param.dy)
		{
			param.err -= param.dy;
			p1.x += param.sx;
		}
		if (param.err2 < param.dx)
		{
			param.err += param.dx;
			p1.y += param.sy;
		}
	}
	return (0);
}
