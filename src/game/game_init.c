/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:57:56 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/10 18:58:23 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdlib.h>

void	game_init(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		fatal_error(game, et_mlx_init);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	if (!game->win)
		fatal_error(game, et_win_init);
}

void	game_destruct(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
