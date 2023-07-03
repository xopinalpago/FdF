/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:43:43 by rmeriau           #+#    #+#             */
/*   Updated: 2023/07/03 19:19:44 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_Color	interpol_color(t_Color color1, t_Color color2, float t)
{
	t_Color	result;

	result.r = color1.r + t * (color2.r - color1.r);
	if (result.r > 255)
		result.r = 255;
	else if (result.r < 0)
		result.r = 0;
	result.g = color1.g + t * (color2.g - color1.g);
	if (result.g > 255)
		result.g = 255;
	else if (result.g < 0)
		result.g = 0;
	result.b = color1.b + t * (color2.b - color1.b);
	if (result.b > 255)
		result.b = 255;
	else if (result.b < 0)
		result.b = 0;
	return (result);
}

t_Color	get_color(int z, int minZ, int maxZ)
{
	t_Color	color1;
	t_Color	color2;
	float	t;

	color1.r = 0;
	color1.g = 0;
	color1.b = 255;
	color2.r = 255;
	color2.g = 255;
	color2.b = 255;
	t = 0;
	if (maxZ != minZ)
		t = (float)(z - minZ) / (float)(maxZ - minZ);
	else
		return (color2);
	return (interpol_color(color1, color2, t));
}

int	rgb_to_hex(t_Color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

t_Color	init_color(t_Point2D p1, t_Point2D p2, t_param param)
{
	t_Color	color_step;

	if (param.num_pixels == 0)
		param.num_pixels = 1;
	color_step.r = (p2.color.r - p1.color.r) / param.num_pixels;
	color_step.g = (p2.color.g - p1.color.g) / param.num_pixels;
	color_step.b = (p2.color.b - p1.color.b) / param.num_pixels;
	return (color_step);
}

t_Color	step_color(t_Color color_add, t_Color color_step)
{
	color_add.r += color_step.r;
	color_add.g += color_step.g;
	color_add.b += color_step.b;
	return (color_add);
}
