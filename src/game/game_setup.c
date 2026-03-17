/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:34:35 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/17 16:22:21 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "game.h"

int	game_init(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->mlx.width = 860;
	game->mlx.height = 640;
	game->mlx.img.bits_per_pixel = // TODO
	game->mlx.img.line_size = // TODO
	game->mlx.img.endian = // TODO
}

int	game_setup(t_game *game, t_map *map)
{
	if (game_init(game))
		return (1);
	if (mlx_setup(game))
		return (1);
	return (0);
}