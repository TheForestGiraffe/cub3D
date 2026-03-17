/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:34:35 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/17 11:59:19 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "game.h"

// WIP
int	game_init(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
	{
		ft_putstr_fd("Error\ngame_init: mlx_init failed", 2);
		return (1);
	}



	
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->win)
		fatal_error(game, et_win_init);
}

int		game_setup(t_game *game, t_map *map)
{
	if (game_init(game))
		return (1);
	return (0);
}