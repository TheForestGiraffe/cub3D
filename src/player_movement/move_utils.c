/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:11:36 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/10 20:16:27 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	is_valid_x(t_game *game, double new_x, double y)
{
	double	buffer;

	buffer = 0.2;
	if (game->model.grid[(int)y][(int)(new_x + buffer)] == '1' ||
		game->model.grid[(int)y][(int)(new_x - buffer)] == '1')
		return (0);
	return (1);
}

int	is_valid_y(t_game *game, double x, double new_y)
{
	double	buffer;

	buffer = 0.2;
	if (game->model.grid[(int)(new_y + buffer)][(int)x] == '1' ||
		game->model.grid[(int)(new_y - buffer)][(int)x] == '1')
		return (0);
	return (1);
}
