/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:05:49 by rmeriau           #+#    #+#             */
/*   Updated: 2023/05/03 17:19:16 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_len(long n)
{
	long	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size++);
}

char	*ft_itoa(int n)
{
	long	nl;
	long	len;
	char	*res;

	nl = n;
	len = ft_len(nl);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	len--;
	if (nl < 0)
		nl = -nl;
	while (len >= 0)
	{
		res[len] = (nl % 10) + '0';
		len--;
		nl /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
