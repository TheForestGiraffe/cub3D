/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:17:55 by tcunha            #+#    #+#             */
/*   Updated: 2025/06/04 15:58:42 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		s = ft_strchr(s, c);
		if (!s)
			break ;
	}
	return (count);
}

static void	ft_free(char **array, int i)
{
	while (i--)
		free(array[i]);
	free(array);
}

static int	ft_filler(char const *s, char c, char **array)
{
	int			len;
	int			i;
	const char	*start;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		len = 0;
		start = s;
		while (*s && *s != c)
		{
			len++;
			s++;
		}
		array[i] = ft_substr(start, 0, len);
		if (!array[i])
			return (ft_free(array, i), 0);
		i++;
	}
	return (array[i] = NULL, 1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!array)
		return (NULL);
	if (ft_filler(s, c, array) == 0)
		return (NULL);
	return (array);
}
