/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:57:58 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/08 23:49:13 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "raycaster.h"
#include "raycaster_internal.h"
#include <math.h>

static void	steps_and_initial_side_dists_init(t_game *game, t_temp *tmp)
{
	t_game_player	*player;

	player = &game->player;
	if (tmp->ray_dir_x < 0)
	{
		tmp->step_x = -1;
		tmp->side_dist_x = (player->x - tmp->map_x) * tmp->delta_dist_x;
	}
	else
	{
		tmp->step_x = 1;
		tmp->side_dist_x = (tmp->map_x + 1.0 - player->x) * tmp->delta_dist_x;
	}
	if (tmp->ray_dir_y < 0)
	{
		tmp->step_y = -1;
		tmp->side_dist_y = (player->y - tmp->map_y) * tmp->delta_dist_y;
	}
	else
	{
		tmp->step_y = 1;
		tmp->side_dist_y = (tmp->map_y + 1.0 - player->y) * tmp->delta_dist_y;
	}
}

void	ray_init(t_game *game, t_ray *ray, t_temp *tmp, int screen_x)
{
	ray->screen_x = screen_x;
	tmp->camera_x = (2.0 * screen_x) / (double)game->mlx.width - 1;
	tmp->ray_dir_x = game->player.dir_x
		+ (game->player.plane_x * tmp->camera_x);
	tmp->ray_dir_y = game->player.dir_y
		+ (game->player.plane_y * tmp->camera_x);
	tmp->map_x = (int)game->player.x;
	tmp->map_y = (int)game->player.y;
	if (tmp->ray_dir_x == 0)
		tmp->delta_dist_x = 1e30;
	else
		tmp->delta_dist_x = fabs(1.0 / tmp->ray_dir_x);
	if (tmp->ray_dir_y == 0)
		tmp->delta_dist_y = 1e30;
	else
		tmp->delta_dist_y = fabs(1.0 / tmp->ray_dir_y);
	steps_and_initial_side_dists_init(game, tmp);
}
