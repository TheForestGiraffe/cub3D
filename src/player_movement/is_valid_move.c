/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:11:36 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/12 14:48:27 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	is_valid_move(t_game *game, double new_x, double new_y)
{
	double	buffer;

	buffer = 0.2;
	if (game->model.grid[(int)new_y][(int)(new_x + buffer)] == '1' ||
		game->model.grid[(int)new_y][(int)(new_x - buffer)] == '1' ||
		game->model.grid[(int)(new_y + buffer)][(int)(new_x)] == '1' ||
		game->model.grid[(int)(new_y - buffer)][(int)(new_x)] == '1')
		return (0);
	return (1);
}
