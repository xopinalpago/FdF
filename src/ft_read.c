/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:08:44 by rmeriau           #+#    #+#             */
/*   Updated: 2023/07/03 15:54:05 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	fill_map(int **map, int l, int c, int fd)
{
	int		j;
	int		i;
	char	**data;
	char	*line;

	i = -1;
	j = -1;
	while (++i < l)
	{
		map[i] = (int *)malloc(c * sizeof(int));
		line = get_next_line(fd, 0);
		data = ft_split(line, " \n");
		free(line);
		if (!data || !map[i])
			return (0);
		j = -1;
		while (++j < c)
			map[i][j] = ft_atoi(data[j]);
		free_char(data);
	}
	get_next_line(fd, 1);
	return (1);
}

int	**get_map(char *file, int l, int c)
{
	int	**map;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = (int **)malloc(l * sizeof(int *));
	if (!map)
		return (NULL);
	fill_map(map, l, c, fd);
	if (fd >= 0)
		close(fd);
	return (map);
}

int	get_nb_col(char *line)
{
	int		c;
	char	**data;

	data = ft_split(line, " \n");
	if (!data)
		return (0);
	c = 0;
	while (data[c])
		c++;
	free_char(data);
	return (c);
}

int	get_size_map(char *file, t_data *data)
{
	int		l;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd, 0);
	data->c = get_nb_col(line);
	l = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd, 0);
		if (line && data->c != get_nb_col(line))
		{
			free(line);
			get_next_line(fd, 1);
			return (0);
		}
		l++;
	}
	free(line);
	if (fd >= 0)
		close(fd);
	data->l = l;
	return (1);
}
