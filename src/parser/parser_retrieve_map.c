/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_retrieve_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 21:50:57 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/20 21:55:55 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "parser.h"
#include <stdlib.h>

static int	is_empty_line(char *line)
{
	return (!line || line[0] == '\0' || line[0] == '\n');
}

static char	*skip_empty_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (is_empty_line(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

static int	retrieve_map_into_list(t_list **list, char *line)
{
	t_list	*temp;

	temp = ft_lstnew(line);
	if (!temp)
	{
		ft_lstclear(list, free);
		return (print_error("@parser_map", "retrieve_map_into_list"), 1);
	}
	ft_lstadd_back(list, temp);
	return (0);
}

static int	check_remaining_lines(t_list *list, char *line, int fd)
{
	while (line)
	{
		if (!is_empty_line(line))
		{
			free(line);
			ft_lstclear(&list, free);
			print_error("@parser_retrieve_map", "check_remaining_lines");
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	parser_retrieve_map(t_list **list, int fd)
{
	char	*line;

	line = skip_empty_lines(fd);
	while (!is_empty_line(line))
	{
		line[ft_strlen(line) - 1] = '\0';
		if (retrieve_map_into_list(list, line))
			return (1);
		line = get_next_line(fd);
	}
	if (check_remaining_lines(*list, line, fd))
		return (1);
	return (0);
}
