/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 20:44:57 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/03 23:30:40 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer_internal.h"

int	draw_square(t_square *square, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < square->size)
	{
		j = 0;
		while (j < square->size)
		{
			if (put_pixel(square->x + j, square->y + i, game, square->color))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
