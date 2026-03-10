/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:36:00 by tcunha            #+#    #+#             */
/*   Updated: 2025/06/04 15:34:20 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	i = ft_strlen(str) + 1;
	while (i--)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
	}
	return (NULL);
}
