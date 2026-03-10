/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:57:23 by tcunha            #+#    #+#             */
/*   Updated: 2025/06/04 15:33:32 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_len;

	if (!*little)
		return ((char *)big);
	l_len = ft_strlen(little);
	i = 0;
	while (big[i] && i + l_len <= len)
	{
		if (big[i] == little[0])
		{
			if (!ft_strncmp(&big[i], little, l_len))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
