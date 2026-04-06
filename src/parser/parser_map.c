/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:44:43 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/06 13:22:35 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser_internal.h"
#include "utils.h"
#include <stdlib.h>

static void	update_cols(t_map *map, char *line)
{
	int		line_cols;

	line_cols = ft_strlen(line);
	if (line_cols > map->cols)
		map->cols = line_cols;
}

static int	pad_line(char **grid, int len, int cols)
{
	char	*temp;

	temp = malloc(cols + 1);
	if (!temp)
		return (print_error("@pad_line", "Allocation failure"), 1);
	ft_memcpy(temp, *grid, len);
	ft_memset(&temp[len], ' ', cols - len);
	temp[cols] = '\0';
	free(*grid);
	*grid = temp;
	return (0);
}

static int	add_padding(char **grid, int cols)
{
	int	i;
	int	len;

	i = 0;
	while (grid[i])
	{
		len = ft_strlen(grid[i]);
		if (len < cols)
		{
			if (pad_line(&grid[i], len, cols))
				return (1);
		}
		i++;
	}
	return (0);
}

static int	convert_list_to_grid(t_map *map, t_list *list)
{
	int		i;

	map->rows = ft_lstsize(list);
	map->grid = malloc((map->rows + 1) * sizeof(char *));
	if (!map->grid)
		return (print_error("@convert_list_to_grid", "Alloc fail 1"), 1);
	ft_memset(map->grid, 0, (map->rows + 1) * sizeof(char *));
	i = 0;
	while (i < map->rows)
	{
		update_cols(map, (char *)list->content);
		map->grid[i] = ft_strdup((char *)list->content);
		if (!map->grid[i])
		{
			free_array(map->grid);
			return (print_error("@convert_list_to_grid", "Alloc fail 2"), 1);
		}
		list = list->next;
		i++;
	}
	map->grid[map->rows] = NULL;
	if (add_padding(map->grid, map->cols))
		return (1);
	return (0);
}

int	parser_map(t_map *map, int fd)
{
	t_list	*list;

	list = NULL;
	if (parser_retrieve_grid(&list, fd))
		return (ft_lstclear(&list, free), 1);
	if (convert_list_to_grid(map, list))
		return (ft_lstclear(&list, free), 1);
	ft_lstclear(&list, free);
	return (0);
}
