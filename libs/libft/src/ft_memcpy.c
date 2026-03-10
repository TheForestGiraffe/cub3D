/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:18:17 by tcunha            #+#    #+#             */
/*   Updated: 2025/06/04 11:10:41 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> 

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_dest;
	const unsigned char	*temp_src;

	if (!dest && !src)
		return (NULL);
	temp_dest = dest;
	temp_src = src;
	while (n--)
		*temp_dest++ = *temp_src++;
	return (dest);
}
