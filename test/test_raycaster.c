/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_raycaster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 00:21:17 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/09 23:51:39 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** **
**                              RAYCASTER TEST                                **
** ************************************************************************** **

This test validates the core behavior of the raycasting system by casting
rays in a simple, controlled environment and checking their results.

Setup:
 - Map: 5x5 closed room

     11111
     10001
     10001
     10001
     11111

 - Player is positioned at the center: (2.5, 2.5)
 - Player is facing EAST (dir = {1, 0})
 - Screen size: width = 8, height = 10

What is tested:

 1. Ray generation
    - One ray per screen column (width = 8)
    - Each ray must have the correct screen_x index

 2. Basic validity
    - All rays must have a positive perpendicular distance
    - All rays must hit the EAST wall (face = WEST side of wall)

 3. Center ray correctness (column width / 2)

    Expected geometric result:
    - Player x = 2.5 → wall at x = 4.0 → distance = 1.5

    Expected values:
    - perp_wall_dist ≈ 1.5
    - hit point ≈ (4.0, 2.5)
    - wall_dir = WEST (wall is hit on its west-facing side)
    - wall_x ≈ 0.5 (middle of the wall)

 4. Projection correctness

    Using screen height = 10:
    - wall_height ≈ 10 / 1.5 → 6 (int)
    - wall_top = 2
    - wall_bottom = 8

Purpose:
This test ensures that ray direction, DDA stepping, wall detection,
perpendicular distance calculation, and screen projection are all working
consistently and correctly.

** ************************************************************************** */

#include "game.h"
#include "raycaster.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EPS 1e-6

static int	assert_close(const char *name, double got, double expected)
{
	if (fabs(got - expected) > EPS)
	{
		fprintf(stderr, "FAIL: %s -> got %.6f, expected %.6f\n",
			name, got, expected);
		return (1);
	}
	return (0);
}

static int	assert_int_eq(const char *name, int got, int expected)
{
	if (got != expected)
	{
		fprintf(stderr, "FAIL: %s -> got %d, expected %d\n",
			name, got, expected);
		return (1);
	}
	return (0);
}

static char	**dup_grid(const char **src, int rows)
{
	char	**grid;
	int		i;

	grid = calloc(rows + 1, sizeof(char *));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		grid[i] = strdup(src[i]);
		if (!grid[i])
			return (NULL);
		i++;
	}
	return (grid);
}

static void	free_grid(char **grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

static int	init_test_game(t_game *game)
{
	static const char	*map_rows[] = {
		"11111",
		"10001",
		"10001",
		"10001",
		"11111"
	};

	memset(game, 0, sizeof(*game));
	game->mlx.width = 8;
	game->mlx.height = 10;
	game->model.rows = 5;
	game->model.cols = 5;
	game->model.grid = dup_grid(map_rows, 5);
	if (!game->model.grid)
		return (1);
	game->rays = calloc(game->mlx.width, sizeof(t_ray));
	if (!game->rays)
	{
		free_grid(game->model.grid);
		game->model.grid = NULL;
		return (1);
	}
	game->player.x = 2.5;
	game->player.y = 2.5;
	game->player.dir_x = 1.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.66;
	return (0);
}

static void	print_rays(t_ray *rays, int count)
{
	static const char	*face_name[] = {"NORTH", "SOUTH", "EAST", "WEST"};
	int					i;

	printf("x | dist   | hit_x  | hit_y  | face\n");
	printf("--+--------+--------+--------+------\n");
	i = 0;
	while (i < count)
	{
		printf("%d | %6.3f | %6.3f | %6.3f | %s\n",
			rays[i].screen_x,
			rays[i].perp_wall_dist,
			rays[i].hit_x,
			rays[i].hit_y,
			face_name[rays[i].wall_dir]);
		i++;
	}
}

int	main(void)
{
	t_game		game;
	t_ray		*center;
	int			failed;
	int			i;

	if (init_test_game(&game))
		return (fprintf(stderr, "FAIL: test game init failed\n"), 1);
	cast_rays(&game);
	print_rays(game.rays, game.mlx.width);
	failed = 0;
	i = 0;
	while (i < game.mlx.width)
	{
		failed |= assert_int_eq("screen_x", game.rays[i].screen_x, i);
		if (game.rays[i].perp_wall_dist <= 0.0)
		{
			fprintf(stderr, "FAIL: ray %d has non-positive distance %.6f\n",
				i, game.rays[i].perp_wall_dist);
			failed = 1;
		}
		if (game.rays[i].wall_dir != WEST)
		{
			fprintf(stderr, "FAIL: ray %d expected WEST face, got %d\n",
				i, game.rays[i].wall_dir);
			failed = 1;
		}
		i++;
	}
	center = &game.rays[game.mlx.width / 2];
	failed |= assert_close("center perp_wall_dist", center->perp_wall_dist, 1.5);
	failed |= assert_close("center hit_x", center->hit_x, 4.0);
	failed |= assert_close("center hit_y", center->hit_y, 2.5);
	failed |= assert_close("center wall_x", center->wall_x, 0.5);
	failed |= assert_int_eq("center wall_dir", center->wall_dir, WEST);
	failed |= assert_int_eq("center wall_height", center->wall_height, 6);
	failed |= assert_int_eq("center wall_top", center->wall_top, 2);
	failed |= assert_int_eq("center wall_bottom", center->wall_bottom, 8);
	free(game.rays);
	free_grid(game.model.grid);
	if (failed)
		return (fprintf(stderr, "raycaster unit test: FAILED\n"), 1);
	printf("raycaster unit test: OK\n");
	return (0);
}