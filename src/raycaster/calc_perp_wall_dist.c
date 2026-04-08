/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_perp_wall_dist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:57:58 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/08 23:46:18 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "raycaster.h"
#include "raycaster_internal.h"

void	calc_perp_wall_dist(t_ray *ray, t_temp *tmp)
{
	if (tmp->side == 0)
		ray->perp_wall_dist = (tmp->side_dist_x - tmp->delta_dist_x);
	else
		ray->perp_wall_dist = (tmp->side_dist_y - tmp->delta_dist_y);
}
