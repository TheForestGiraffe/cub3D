/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:57:58 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/09 22:45:38 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "raycaster.h"
#include "raycaster_internal.h"
#include "utils.h"

static void	cast_single_ray(t_game *game, t_ray *ray, int screen_x)
{
	t_temp	tmp;

	ray_init(game, ray, &tmp, screen_x);
	perform_dda(game, &tmp);
	calc_perp_wall_dist(ray, &tmp);
	set_wall_dir(ray, &tmp);
	calc_hit_point(game, ray, &tmp);
	calc_wall_x(ray);
	calc_wall_height(game, ray);
}

void	cast_rays(t_game *game)
{
	int		screen_x;

	screen_x = 0;
	while (screen_x < game->mlx.width)
	{
		cast_single_ray(game, &game->rays[screen_x], screen_x);
		screen_x++;
	}
}
