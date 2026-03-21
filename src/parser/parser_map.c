/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:44:43 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/21 12:09:27 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <stdlib.h>

static int	convert_list_to_grid(t_map *map, t_list *list)
{
	int	i;
	int	line_width;

	map->height = ft_lstsize(list);
	map->grid = malloc((map->height + 1) * sizeof(char *));
	if (!map->grid)
		return (print_error("@parser_map", "convert_list_to_grid"), 1);
	i = 0;
	while (i < map->height)
	{
		line_width = ft_strlen((char *)list->content);
		if (line_width > map->width)
			map->width = line_width;
		map->grid[i] = ft_strdup((char *)list->content);
		if (!map->grid[i])
			return (print_error("@parser_map", "convert_list_to_grid"), 1);
		list = list->next;
		i++;
	}
	map->grid[map->height] = NULL;
	return (0);
}
#include <stdio.h>
int	parser_map(t_map *map, int fd)
{
	t_list	*list;

	list = NULL;
	if (parser_retrieve_map(&list, fd))
		return (ft_lstclear(&list, free), 1);
	if (convert_list_to_grid(map, list))
		return (ft_lstclear(&list, free), 1);
	int	i = 0;
	while (i < map->height)
	{
		printf("%s", map->grid[i]);
		i++;
	}
	printf("\n");
	ft_lstclear(&list, free);
	return (0);
}
