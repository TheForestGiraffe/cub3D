/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:53:02 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/08 17:01:58 by pecavalc         ###   ########.fr       */
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
	double		per_wall_dist;
	double		wall_x;
	t_wall_dir	wall_dir;
	int			line_top;
	int			line_bottom;
	int			line_height;  
}	t_ray;

t_ray	*cast_rays(t_game *game);

#endif