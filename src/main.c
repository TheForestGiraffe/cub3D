/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:00:41 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/17 21:01:54 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game.h"

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
	return (0);
}
