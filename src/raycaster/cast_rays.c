/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:57:58 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/08 16:59:05 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "raycaster.h"

t_ray	*cast_rays(t_game *game)
{
	t_ray	*rays;
	int		screen_x;

	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;

	double	perp_wall_dist;

	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;

	// rays_init();

	screen_x = 0;
	while (screen_x < game->mlx.width)
	{
		// Calc direction ray from player to plane for current screen stripe x
		camera_x = (2 * screen_x)/(double)game->mlx.width -1;
		ray_dir_x = game->player.dir_x + (game->player.dir_x * camera_x);
		ray_dir_y = game->player.dir_y + (game->player.dir_y * camera_x);

		// Initialize the tile we are in
		map_x = game->player.x;
		map_y = game->player.y;	

		// Calc length from one x or y-side to next x or y-side
		if (ray_dir_x  == 0)
			delta_dist_x = 1e30;
		else
			delta_dist_x = fabs(1 / ray_dir_x);
		if (ray_dir_y == 0)
			delta_dist_y == 0;
		else
			delta_dist_y = fabs(1 / ray_dir_y);

		// Calculate step and initial side_dist
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (game->player.x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - game->player.x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (game->player.y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - game->player.y) * delta_dist_y;
		}

		// Perform DDA
		hit = 0;
      	while (hit == 0)
      	{
			// Jump to next map square, either in x-direction, or in y-direction
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			// Check if ray has hit a wall
			if (game->model.grid[map_y][map_x] > 0)
				hit = 1;
	    } 

		// Compute perpendicular distance from wall to camera plane
     	if(side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
      	else
	  		perp_wall_dist = (side_dist_y - delta_dist_y);
		
		// Calculate height of line to draw on screen
		line_height = (int)(game->mlx.height / perp_wall_dist);

		// Calculate lowest and highest pixel to fill in current stripe
		draw_start = -line_height / 2 + game->mlx.height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + game->mlx.height / 2;
		if(draw_end >= game->mlx.height)
			draw_end = game->mlx.height - 1;
			
		x++;
	}

	return (rays);
}
