/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:06:12 by rmeriau           #+#    #+#             */
/*   Updated: 2023/07/03 15:53:48 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_free(t_data *data)
{
	free_int(data->map, data->l);
	free(data->win_ptr);
	free(data->mlx_ptr);
}

void	free_int(int **tableau, int nb_line)
{
	int	i;

	i = 0;
	if (tableau == NULL)
		return ;
	while (i < nb_line)
	{
		free(tableau[i]);
		i++;
	}
	free(tableau);
}

void	free_char(char **tableau)
{
	int	i;

	i = 0;
	if (tableau == NULL)
		return ;
	while (tableau[i] != NULL)
	{
		free(tableau[i]);
		i++;
	}
	free(tableau);
}
