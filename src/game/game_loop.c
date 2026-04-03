/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:01:37 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/03 20:08:47 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <unistd.h>
#include <stdio.h>

// TODO: Remove test print

int	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	printf("game_loop() running\n");
	usleep(1000000);
	return (0);
}
