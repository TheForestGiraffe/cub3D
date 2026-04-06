/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_retrieve_grid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 21:50:57 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/06 13:21:10 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "parser_internal.h"
#include "utils.h"
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

static int	retrieve_grid_into_list(t_list **list, char *line)
{
	t_list	*temp;

	temp = ft_lstnew(line);
	if (!temp)
	{
		ft_lstclear(list, free);
		return (print_error("@retrieve_grid_into_list",
				"Failed to create new t_list node"), 1);
	}
	ft_lstadd_back(list, temp);
	return (0);
}

static int	check_remaining_lines(char *line, int fd)
{
	while (line)
	{
		if (!is_empty_line(line))
		{
			free(line);
			print_error("@check_remaining_lines", "Unexpected end of file");
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	parser_retrieve_grid(t_list **list, int fd)
{
	char	*line;
	int		len;

	line = skip_empty_lines(fd);
	while (!is_empty_line(line))
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (retrieve_grid_into_list(list, line))
			return (1);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	if (check_remaining_lines(line, fd))
		return (1);
	return (0);
}
