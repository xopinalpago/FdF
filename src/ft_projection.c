/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:01:51 by rmeriau           #+#    #+#             */
/*   Updated: 2023/07/03 17:00:41 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_Point2D	except_proj(t_Point2D point2d)
{
	if (point2d.x < 0)
		point2d.x = 0;
	else if (point2d.x >= W)
		point2d.x = W - 1;
	if (point2d.y < 0)
		point2d.y = 0;
	else if (point2d.y >= H)
		point2d.y = H - 1;
	return (point2d);
}

t_Point2D	project_isometric(int x, int y, int z, t_data *data)
{
	t_Point2D	point2d;
	int			factor;
	double		n_z;

	if (((float)((W / (float)data->c) / (H / (float)data->l)) < 0.6) || 
		((float)((H / (float)data->l) / (W / (float)data->c)) < 0.3))
		factor = (W / data->c + H / data->l) / 10;
	else
		factor = (W / data->c + H / data->l) / 4;
	x = x * round(factor);
	y = y * round(factor);
	n_z = 0;
	point2d.x = (x - y) * cos(0.523599);
	if (data->z_ext.y != data->z_ext.x)
	{
		n_z = z / (double)(data->z_ext.y - data->z_ext.x);
		point2d.y = (x + y) * sin(0.523599) - n_z * round(factor) * 1.5;
	}
	else
		point2d.y = (x + y) * sin(0.523599) - z;
	point2d.x += W * 2 / 5;
	point2d.y += H * 1 / 5;
	point2d = except_proj(point2d);
	return (point2d);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}
