/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:43:49 by ocartier          #+#    #+#             */
/*   Updated: 2023/06/29 13:17:36 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_char(char const s, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (s == sep[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_wordlen(char const *s, char *sep)
{
	int	len;

	len = 0;
	while (*s && !in_char(*s, sep))
	{
		len++;
		s++;
	}
	return (len);
}

static int	ft_count_words(char const *s, char *sep)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (!in_char(*s, sep))
		{
			count++;
			s += ft_wordlen(s, sep);
		}
		else
			s++;
	}
	return (count);
}

static void	*free_strs(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char *sep)
{
	char	**strs;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	count = ft_count_words(s, sep);
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	strs[count] = NULL;
	i = 0;
	while (*s)
	{
		if (!in_char(*s, sep))
		{
			strs[i] = ft_substr(s, 0, ft_wordlen(s, sep));
			if (!strs[i++])
				return (free_strs(strs));
			s += ft_wordlen(s, sep);
		}
		else
			s++;
	}
	return (strs);
}
