/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:34:35 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/26 23:38:16 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_wrapper.h"
#include "game.h"
#include "stddef.h"
#include "stdlib.h"

static void	texture_destroy(t_texture *tex, void *mlx)
{
	if (mlx && tex->img.img)
	{
		mlx_destroy_image(mlx, tex->img.img);
		tex->img.img = NULL;
	}
}

static void	model_destroy(t_model *model, void *mlx)
{
	int	i;

	texture_destroy(&model->tex_north, mlx);
	texture_destroy(&model->tex_south, mlx);
	texture_destroy(&model->tex_west, mlx);
	texture_destroy(&model->tex_east, mlx);
	if (model->grid)
	{
		i = 0;
		while (i < model->rows)
			free(model->grid[i++]);
		free(model->grid);
		model->grid = NULL;
	}
}

void	game_destroy(t_game *game)
{
	model_destroy(&game->model, game->mlx.mlx);
	mlx_destroy(&game->mlx);
}
