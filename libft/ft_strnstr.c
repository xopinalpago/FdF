/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:39:34 by rmeriau           #+#    #+#             */
/*   Updated: 2023/05/05 17:02:49 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!big && len == 0)
		return (0);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i + j < len)
	{
		if (big[i + j] == little[j])
		{
			if (little[++j] == '\0')
				return ((char *)big + i);
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return (0);
}
