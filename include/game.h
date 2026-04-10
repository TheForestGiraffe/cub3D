/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:54:13 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/10 15:41:06 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "parser.h"
# include "raycaster.h"
# include <stdbool.h>

typedef struct s_img
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}			t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	t_img	img;
}			t_mlx;

typedef struct s_texture
{
	t_img	img;
	int		height;
	int		width;
}			t_texture;

typedef struct s_model
{
	t_texture	tex_north;
	t_texture	tex_south;
	t_texture	tex_west;
	t_texture	tex_east;
	int			floor_color;
	int			ceiling_color;
	char		**grid;
	int			cols;
	int			rows;
}				t_model;

typedef struct s_ctrl
{
	bool	move_forward;
	bool	move_backward;
	bool	move_left;
	bool	move_right;
	bool	turn_left;
	bool	turn_right;
	double	move_speed;
	double	rot_speed;
}			t_ctrl;

typedef struct s_game_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	t_ctrl	ctrl;
}			t_game_player;

typedef struct s_minimap
{
	int		tile_size;
	int		player_size;
	int		player_color;
	int		floor_color;
	int		wall_color;
}			t_minimap;

typedef struct s_game
{
	t_mlx			mlx;
	t_model			model;
	t_game_player	player;
	t_ray			*rays;
	t_minimap		minimap;
}					t_game;

// game_setup.c
int		game_setup(t_game *game, t_map *map);

// game_setup_load_player.c
void	load_player(t_game *game, t_map *map);

// game_setup_load_model.c
int		load_model(t_game *game, t_map *map);

// game_destroy.c
void	game_destroy(t_game *game);

// game_loop.c
int		game_loop(void *param);

#endif
