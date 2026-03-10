/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 07:57:15 by tcunha            #+#    #+#             */
/*   Updated: 2025/06/04 14:34:17 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*joint_string;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joint_string = malloc(len_s1 + len_s2 + 1);
	if (!joint_string)
		return (NULL);
	ft_strlcpy(joint_string, s1, len_s1 + 1);
	ft_strlcat(joint_string, s2, len_s1 + len_s2 + 1);
	return (joint_string);
}
