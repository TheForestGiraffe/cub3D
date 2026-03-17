/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:54:13 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/17 21:16:22 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

struct	s_map;

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
	t_texture	tex_souht;
	t_texture	tex_west;
	t_texture	tex_east;
	int			floor_color;
	int			ceiling_color;
	char		**grid;
	int			width;
	int			height;
}				t_model;

typedef struct s_game_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_game_player;

typedef struct s_game
{
	t_mlx			mlx;
	t_model			model;
	t_game_player	player;
}					t_game;

int		game_setup(t_game *game, struct s_map *map);
int		game_init(t_game *game);
void	game_destroy(t_game *game);

#endif
