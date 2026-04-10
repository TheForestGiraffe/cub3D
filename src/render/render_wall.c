/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:59:54 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/10 18:17:17 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "raycaster.h"
#include "render_internal.h"

static t_texture	*select_wall_texture(t_model *model, t_ray *ray)
{
	if (ray->wall_dir == NORTH)
		return (&model->tex_north);
	if (ray->wall_dir == SOUTH)
		return (&model->tex_south);
	if (ray->wall_dir == WEST)
		return (&model->tex_west);
	return (&model->tex_east);
}

static int	get_texture_col(t_ray *ray, int tex_width)
{
	int	col;

	col = (int)(ray->wall_x * tex_width);
	if (ray->wall_dir == EAST || ray->wall_dir == NORTH)
		col = tex_width - 1 - col;
	return (col);
}

static void	init_wall_render(t_game *game, t_ray *ray, t_render *render)
{
	render->texture = select_wall_texture(&game->model, ray);
	render->tex_col = get_texture_col(ray, render->texture->width);
	render->step = (double)render->texture->height / (double)ray->wall_height;
	render->tex_pos = (ray->wall_top - game->mlx.height / 2.0
			+ ray->wall_height / 2.0) * render->step;
}

static void	draw_wall_column(t_render *render, t_ray *ray, t_game *game)
{
	int				screen_y;
	int				tex_row;
	unsigned int	color;

	screen_y = ray->wall_top;
	while (screen_y <= ray->wall_bottom)
	{
		tex_row = (int)render->tex_pos & (render->texture->height - 1);
		render->tex_pos += render->step;
		color = img_get_pixel(&render->texture->img, render->tex_col, tex_row);
		img_put_pixel(game, ray->screen_x, screen_y, color);
		screen_y++;
	}
}

void	render_wall(t_game *game, t_ray *ray)
{
	t_render	render;

	init_wall_render(game, ray, &render);
	draw_wall_column(&render, ray, game);
}
