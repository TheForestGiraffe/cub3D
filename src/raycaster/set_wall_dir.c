/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:57:58 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/08 23:45:52 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "raycaster.h"
#include "raycaster_internal.h"

void	set_wall_dir(t_ray *ray, t_temp *tmp)
{
	if (tmp->side == 0)
	{
		if (tmp->ray_dir_x > 0)
			ray->wall_dir = WEST;
		else
			ray->wall_dir = EAST;
	}
	else
	{
		if (tmp->ray_dir_y > 0)
			ray->wall_dir = NORTH;
		else
			ray->wall_dir = SOUTH;
	}
}
