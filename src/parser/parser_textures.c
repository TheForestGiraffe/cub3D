/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:39:30 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/17 22:00:38 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

static void	skip_spaces(char **line)
{
	while (**line && (** line == ' ' || (**line >= '\t' && **line <= '\r')))
		(*line)++;
}

static void	process_line(char **line, int fd)
{
	*line = get_next_line(fd);
	if (!*line)
		return ;
	skip_spaces(line);
}

int	parser_textures(t_map *map, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (ft_putendl_fd("Error\n@parser_textures, gnl", 2), 1);
	}

}
