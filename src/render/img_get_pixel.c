/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_get_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 20:33:10 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/11 09:17:59 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

unsigned int	img_get_pixel(t_img *img, int x, int y)
{
	char	*pixel;

	pixel = img->address + y * img->line_size + x * (img->bits_per_pixel / 8);
	return (*(unsigned int *)pixel);
}
