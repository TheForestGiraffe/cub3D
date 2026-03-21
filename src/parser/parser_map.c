/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:44:43 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/21 19:23:48 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <stdlib.h>

static void	update_width(t_map *map, char *line)
{
	int		line_width;

	line_width = ft_strlen(line);
	if (line_width > map->width)
		map->width = line_width;
}

static int	pad_line(char **grid, int len, int width)
{
	char	*temp;

	temp = malloc(width + 1);
	if (!temp)
		return (print_error("@parser_map", "pad_line"), 1);
	ft_memcpy(temp, *grid, len);
	ft_memset(&temp[len], ' ', width - len);
	temp[width] = '\0';
	free(*grid);
	*grid = temp;
	return (0);
}

static int	add_padding(char **grid, int width)
{
	int	i;
	int	len;

	i = 0;
	while (grid[i])
	{
		len = ft_strlen(grid[i]);
		if (len < width)
		{
			if (pad_line(&grid[i], len, width))
				return (1);
		}
		i++;
	}
	return (0);
}

static int	convert_list_to_grid(t_map *map, t_list *list)
{
	int		i;

	map->height = ft_lstsize(list);
	map->grid = malloc((map->height + 1) * sizeof(char *));
	if (!map->grid)
		return (print_error("@parser_map", "convert_list_to_grid"), 1);
	i = 0;
	while (i < map->height)
	{
		update_width(map, (char *)list->content);
		map->grid[i] = ft_strdup((char *)list->content);
		if (!map->grid[i])
			return (print_error("@parser_map", "convert_list_to_grid"), 1);
		list = list->next;
		i++;
	}
	map->grid[map->height] = NULL;
	if (add_padding(map->grid, map->width))
		return (1);
	return (0);
}

int	parser_map(t_map *map, int fd)
{
	t_list	*list;

	list = NULL;
	if (parser_retrieve_map(&list, fd))
		return (ft_lstclear(&list, free), 1);
	if (convert_list_to_grid(map, list))
		return (ft_lstclear(&list, free), 1);
	ft_lstclear(&list, free);
	return (0);
}
