/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:57:58 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/08 23:46:42 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "raycaster.h"
#include "raycaster_internal.h"

void	perform_dda(t_game *game, t_temp *tmp)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (tmp->side_dist_x < tmp->side_dist_y)
		{
			tmp->side_dist_x += tmp->delta_dist_x;
			tmp->map_x += tmp->step_x;
			tmp->side = 0;
		}
		else
		{
			tmp->side_dist_y += tmp->delta_dist_y;
			tmp->map_y += tmp->step_y;
			tmp->side = 1;
		}
		if (game->model.grid[tmp->map_y][tmp->map_x] != '0')
			hit = 1;
	}
}
