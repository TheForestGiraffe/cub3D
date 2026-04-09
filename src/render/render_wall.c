/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:59:54 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/08 21:28:58 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "raycaster.h"

static t_texture	*select_texture(t_model *model, t_ray *ray)
{
	if (ray->wall_dir == NORTH)
		return (&model->tex_north);
	if (ray->wall_dir == SOUTH)
		return (&model->tex_south);
	if (ray->wall_dir == WEST)
		return (&model->tex_west);
	return (&model->tex_east);
}

static int	get_texture_x(t_ray *ray, int texture_width)
{
	int	x;

	x = (int)(ray->wall_x * texture_width);
	if (ray->wall_dir == EAST || ray->wall_dir == NORTH)
		x = texture_width - 1 - x;
	return (x);
}

void	render_wall(t_game *game, t_ray *ray)
{
	t_texture	*texture;
	int			texture_x;

	texture = select_texture(&game->model, ray);
	texture_x = get_texture_x(ray, texture->width);
}
