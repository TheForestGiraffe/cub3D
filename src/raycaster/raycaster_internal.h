/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:53:02 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/08 23:42:40 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_INTERNAL_H
# define RAYCASTER_INTERNAL_H

# include "raycaster.h"

typedef struct s_temp
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	int		side;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
}			t_temp;

void	ray_init(t_game *game, t_ray *ray, t_temp *tmp, int screen_x);
void	perform_dda(t_game *game, t_temp *tmp);
void	calc_perp_wall_dist(t_ray *ray, t_temp *tmp);
void	set_wall_dir(t_ray *ray, t_temp *tmp);
void	calc_hit_point(t_game *game, t_ray *ray, t_temp *tmp);
void	calc_wall_x(t_ray *ray);
void	calc_wall_height(t_game *game, t_ray *ray);

#endif