/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_internal_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 20:34:27 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/11 09:13:46 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_INTERNAL_H
# define RENDER_INTERNAL_H

# include "game.h"
# include "raycaster.h"

typedef struct s_square
{
	int	x;
	int	y;
	int	size;
	int	color;
}		t_square;

typedef struct s_render
{
	t_texture	*texture;
	int			tex_col;
	double		step;
	double		tex_pos;
}				t_render;

int				img_put_pixel(t_game *game, int x, int y, unsigned int color);
unsigned int	img_get_pixel(t_img *img, int x, int y);
void			render_wall(t_game *game, t_ray *ray);
int				render_minimap(t_game *game);
void			draw_square(t_square *square, t_game *game);

#endif
