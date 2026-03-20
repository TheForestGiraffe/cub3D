/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:00:41 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/20 20:44:04 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (parser(argc, argv, &map))
		return (1);
	if (game_setup(&game, &map))
	{
		map_destroy(&map);
		return (1);
	}
	map_destroy(&map);
	mlx_loop(game.mlx.mlx);
	return (0);
}
