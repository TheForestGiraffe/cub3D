/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:39:01 by tcunha            #+#    #+#             */
/*   Updated: 2025/06/04 14:08:35 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 

static int	ft_numlen(int n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	int				len;
	unsigned int	num;

	num = n;
	len = ft_numlen(num);
	nbr = malloc(len + 1);
	if (!nbr)
		return (NULL);
	nbr[len--] = '\0';
	if (num == 0)
		return (nbr[0] = '0', nbr);
	if (n < 0)
	{
		nbr[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		nbr[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (nbr);
}
