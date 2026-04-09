/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_wall_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:57:58 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/08 23:45:30 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "raycaster.h"
#include "raycaster_internal.h"
#include <math.h>

void	calc_wall_x(t_ray *ray)
{
	if (ray->wall_dir == EAST || ray->wall_dir == WEST)
		ray->wall_x = ray->hit_y;
	else
		ray->wall_x = ray->hit_x;
	ray->wall_x -= floor(ray->wall_x);
}
