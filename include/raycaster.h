/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:53:02 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/09 23:07:26 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

typedef struct s_game	t_game;

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

void	cast_rays(t_game *game);

#endif