/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 20:33:10 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/10 18:39:07 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	img_put_pixel(t_game *game, int x, int y, unsigned int color)
{
	char	*pixel;

	if (x < 0 || x >= game->mlx.width || y < 0 || y >= game->mlx.height)
		return (1);
	pixel = game->mlx.img.address + y * game->mlx.img.line_size + x
		* (game->mlx.img.bits_per_pixel / 8);
	*(unsigned int *)pixel = color;
	return (0);
}

unsigned int	img_get_pixel(t_img *img, int x, int y)
{
	char	*pixel;

	pixel = img->address + y * img->line_size + x * (img->bits_per_pixel / 8);
	return (*(unsigned int *)pixel);
}
