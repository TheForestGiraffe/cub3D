/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 20:02:19 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/09 22:45:51 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

typedef enum e_wall_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_wall_dir;

typedef struct s_ray
{
	int			screen_x;
	double		perp_wall_dist;
	double		hit_x;
	double		hit_y;
	int			wall_height;
	int			wall_top;
	int			wall_bottom;
	double		wall_x;
	t_wall_dir	wall_dir;
}				t_ray;

t_ray	*cast_rays(t_game *game);

#endif
