/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 21:04:04 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/03 17:33:04 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser_internal.h"
#include "utils.h"
#include <fcntl.h>
#include <unistd.h>

static int	validate_texture_paths(t_map *map)
{
	int	fd;

	fd = open(map->tex_east, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(map->tex_west, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(map->tex_north, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(map->tex_south, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

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
	if (parser_textures(map, fd))
		return (close(fd), 1);
	if (validate_texture_paths(map))
		return (close(fd), 1);
	if (parser_map(map, fd))
		return (close(fd), 1);
	close(fd);
	if (parser_validate_grid(map))
		return (1);
	return (0);
}
