/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:14:37 by rmeriau           #+#    #+#             */
/*   Updated: 2023/05/05 16:52:39 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l_dest;
	size_t	l_src;

	if ((!dst || !src) && size == 0)
		return (0);
	l_dest = ft_strlen(dst);
	l_src = ft_strlen(src);
	i = 0;
	if (size == 0 || size <= l_dest)
	{
		return (size + l_src);
	}
	while (src[i] != '\0' && i < size - l_dest - 1)
	{
		dst[l_dest + i] = src[i];
		i++;
	}
	dst[l_dest + i] = '\0';
	return (l_dest + l_src);
}
