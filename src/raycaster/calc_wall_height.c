/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_wall_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:57:58 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/08 23:42:35 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "raycaster.h"
#include "raycaster_internal.h"

void	calc_wall_height(t_game *game, t_ray *ray)
{
	ray->wall_height = (int)(game->mlx.height / ray->perp_wall_dist);
	ray->wall_top = -ray->wall_height / 2 + game->mlx.height / 2;
	if (ray->wall_top < 0)
		ray->wall_top = 0;
	ray->wall_bottom = ray->wall_height / 2 + game->mlx.height / 2;
	if (ray->wall_bottom >= game->mlx.height)
		ray->wall_bottom = game->mlx.height - 1;
}
