/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 20:00:25 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/07 19:00:44 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "raycaster.h"
#include "render_internal.h"

static void	render_ceiling(t_model *model, t_img *img, int x, int draw_start)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		img_put_pixel(img, x, y, model->ceiling_color);
		y++;
	}
}

static void	render_floor(t_model *model, t_img *img, int x, int draw_end)
{
	int	y;

	y = draw_end;
	while (y < model->rows)
	{
		img_put_pixel(img, x, y, model->floor_color);
		y++;
	}
}

static t_texture	*select_texture(t_model *model, t_ray *ray,
		t_game_player *player)
{
	if (ray->side && player->dir_y > 0)
		return (&model->tex_north);
	if (ray->side && player->dir_y < 0)
		return (&model->tex_south);
	if (!ray->side && player->dir_x > 0)
		return (&model->tex_west);
	return (&model->tex_east);
}

int	render_stripe(t_game *game, t_ray *ray, int x)
{
	t_texture	*texture;

	texture = select_texture(&game->model, ray, &game->player);
	render_ceiling(&game->model, &game->mlx.img, x, ray->draw_start);
	render_wall();
	render_floor(&game->model, &game->mlx.img, x, ray->draw_end);
	return (0);
}
