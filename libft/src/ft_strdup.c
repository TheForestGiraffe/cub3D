/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:05:38 by tcunha            #+#    #+#             */
/*   Updated: 2025/06/04 14:23:37 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*duplicate;
	size_t	len;

	len = ft_strlen(src);
	duplicate = malloc(len + 1);
	if (!duplicate)
		return (NULL);
	return ((char *)ft_memmove(duplicate, src, len + 1));
}
