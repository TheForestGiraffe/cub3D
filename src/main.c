/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:00:41 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/18 22:45:37 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game.h"

int	main(int argc, char **argv)
{
	t_map	map;
	//t_game	game;

	if (parser(argc, argv[1], &map))
		return (parser_destroy(&map), 1);
	//if (game_setup(&game, &map))
	//{
	//	parser_destroy(&map);
	//	return (1);
	//}
	parser_destroy(&map);
	return (0);
}
