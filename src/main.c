/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:00:41 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/16 20:33:20 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game.h"

int	main(int argc, char **argv)
{
	t_level_description	level_description;
	t_game				game;

	if (parse(argc, argv, &level_description))
		return (1);
	if (game_setup(&game, &level_description))
	{
		parsed_model_destroy(&level_description);
		return (1);
	}
	parsed_model_destroy(&level_description);	
	return (0);
}
