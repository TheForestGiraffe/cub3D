/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 20:33:10 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/06 20:35:17 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	img_put_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*pixel;

	pixel = img->address + y * img->line_size + x * (img->bits_per_pixel / 8);
	*(unsigned int *)pixel = color;
}
