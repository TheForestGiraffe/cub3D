/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_hit_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:57:58 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/08 23:45:09 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "raycaster.h"
#include "raycaster_internal.h"

void	calc_hit_point(t_game *game, t_ray *ray, t_temp *tmp)
{
	ray->hit_x = game->player.x + tmp->ray_dir_x * ray->perp_wall_dist;
	ray->hit_y = game->player.y + tmp->ray_dir_y * ray->perp_wall_dist;
}
