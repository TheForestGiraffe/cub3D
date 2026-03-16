/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:00:41 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/16 21:10:43 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "parse.h"
#include "game.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (parse_map(argc, argv, &map))
		return (1);
	if (game_setup(&game, &map))
	{
		map_destroy(&map);
		return (1);
	}
	map_destroy(&map);	
	return (0);
}
