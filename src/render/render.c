/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 20:00:25 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/09 18:25:35 by tcunha           ###   ########.fr       */
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

int	render_stripe(t_game *game, t_ray *ray, int x)
{
	render_ceiling(&game->model, &game->mlx.img, x, ray->line_top);
	render_wall(game, ray);
	render_floor(&game->model, &game->mlx.img, x, ray->line_bottom);
	return (0);
}
