/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 21:04:04 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/20 21:21:48 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <fcntl.h>
#include <unistd.h>

static int	parser_validate_input(int argc, char *file)
{
	char	*suffix;

	if (argc != 2)
		return (ft_putendl_fd("[USAGE] ./cub3D *.cub", 2), 1);
	suffix = ft_strnstr(file, ".cub", ft_strlen(file));
	if (!suffix || suffix[4] != '\0')
		return (ft_putendl_fd("[USAGE] ./cub3D *.cub", 2), 1);
	return (0);
}

int	parser(int argc, char *file, t_map *map)
{
	int	fd;

	if (parser_validate_input(argc, file))
		return (1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error\n@parser, open", 2), 1);
	ft_memset(map, 0, sizeof(t_map));
	if (parser_textures(map, fd))
		return (close(fd), 1);
	if (parser_map(map, fd))
		return (close(fd), 1);
	close(fd);
	return (0);
}
