/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 20:00:25 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/11 08:35:10 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "raycaster.h"
#include "render_internal.h"
#include "mlx.h"

static void	render_ceiling(t_model *model, t_game *game, int x, int draw_start)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		img_put_pixel(game, x, y, model->ceiling_color);
		y++;
	}
}

static void	render_floor(t_game *game, int x, int draw_end)
{
	int	y;

	y = draw_end;
	while (y < game->mlx.height)
	{
		img_put_pixel(game, x, y, game->model.floor_color);
		y++;
	}
}

void	render_stripe(t_game *game, t_ray *ray, int x)
{
	render_ceiling(&game->model, game, x, ray->wall_top);
	render_wall(game, ray);
	render_floor(game, x, ray->wall_bottom);
}

void	render(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->mlx.width)
	{
		render_stripe(game, &game->rays[x], x);
		x++;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
		game->mlx.img.img, 0, 0);
}