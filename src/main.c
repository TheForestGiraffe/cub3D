/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:00:41 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/16 13:50:07 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game.h"

int	main(int argc, char **argv)
{
	t_parsed_model	parsed_model;
	t_game			game;

	if (parse(argc, argv, &parsed_model))
		return (1);
	if (game_setup(&game, &parsed_model))
	{
		parsed_model_destroy(&parsed_model);
		return (1);
	}
	parsed_model_destroy(&parsed_model);	
	return (0);
}
