/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup_load_model.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:34:35 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/06 20:49:59 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "game.h"
#include "mlx_wrapper.h"
#include "mlx.h"
#include <stdlib.h>
#include "utils.h"

static int	alloc_grid(t_game *game, t_map *map)
{
	int	i;

	game->model.grid = malloc(sizeof(char *) * (map->rows + 1));
	if (!game->model.grid)
		return (print_error("@load_model", "malloc row"), 1);
	ft_bzero(game->model.grid, sizeof(char *) * (map->rows + 1));
	i = 0;
	while (i < map->rows)
	{
		game->model.grid[i] = malloc(sizeof(char) * (map->cols + 1));
		if (!game->model.grid[i])
		{
			while (i >= 0)
				free(game->model.grid[i--]);
			free(game->model.grid);
			game->model.grid = NULL;
			return (print_error("@load_model", "malloc cols"), 1);
		}
		ft_bzero(game->model.grid[i], map->cols + 1);
		i++;
	}
	return (0);
}

static int	copy_grid(char **map_grid, char **game_grid, int cols, int rows)
{
	int	i;
	int	j;

	if (!map_grid || !game_grid)
		return (print_error("@load_texture", "null input"), 1);
	i = 0;
	j = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			game_grid[i][j] = map_grid[i][j];
			j++;
		}
		i++;
	}
	return (0);
}

static int	load_texture(char *path, t_texture *tex, t_mlx *mlx)
{
	if (!tex || !mlx)
		return (print_error("@load_texture", "null input"), 1);
	tex->img.img = mlx_xpm_file_to_image(mlx->mlx,
			path,
			&tex->width,
			&tex->height);
	if (!tex->img.img)
		return (print_error("@load_texture", "mlx_xpm_file_t..."), 1);
	tex->img.address = mlx_get_data_addr(tex->img.img,
			&tex->img.bits_per_pixel,
			&tex->img.line_size,
			&tex->img.endian);
	if (!tex->img.address)
		return (print_error("@load_textue", "mlx_get_data_addr"), 1);
	return (0);
}

int	load_model(t_game *game, t_map *map)
{
	if (load_texture(map->tex_north, &game->model.tex_north, &game->mlx)
		|| load_texture(map->tex_south, &game->model.tex_south, &game->mlx)
		|| load_texture(map->tex_west, &game->model.tex_west, &game->mlx)
		|| load_texture(map->tex_east, &game->model.tex_east, &game->mlx))
		return (1);
	game->model.floor_color = map->floor_color;
	game->model.ceiling_color = map->ceiling_color;
	game->model.rows = map->rows;
	game->model.cols = map->cols;
	if (alloc_grid(game, map))
		return (1);
	if (copy_grid(map->grid, game->model.grid, map->cols, map->rows))
		return (1);
	game->img = mlx_new_image(game->mlx.mlx, game->mlx.width, game->mlx.height);
	if (!game->img)
		return (1);
	game->img->address = mlx_get_data_addr(game->img,
		&game->img->bits_per_pixel, &game->img->line_size, &game->img->endian);
	return (0);
}
