/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:44:43 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/20 21:57:24 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <stdlib.h>

int	parser_map(t_map *map, int fd)
{
	t_list	*list;

	list = NULL;
	(void)map;
	if (parser_retrieve_map(&list, fd))
		return (1);
	ft_lstclear(&list, free);
	return (0);
}
