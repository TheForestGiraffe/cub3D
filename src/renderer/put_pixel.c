/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 20:30:41 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/03 23:30:49 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "utils.h"

int	put_pixel(int x, int y, t_game *game, unsigned int color)
{
	char	*pixel_address;

	if (!game)
		return (print_error("@put_pixel", "NULL input: *game"), 1);
	if (x < 0 || x >= game->mlx.width || y < 0 || y >= game->mlx.height)
		return (print_error("@put_pixel", "x or y out of screen bounds"), 1);
	pixel_address = game->mlx.img.address + (y * game->mlx.img.line_size)
		+ (x * (game->mlx.img.bits_per_pixel / 8));
	*(unsigned int *)pixel_address = color;
	return (0);
}
