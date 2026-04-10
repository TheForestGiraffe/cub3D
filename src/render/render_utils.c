/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 20:33:10 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/08 19:52:39 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	img_put_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*pixel;

	pixel = img->address + y * img->line_size + x * (img->bits_per_pixel / 8);
	*(unsigned int *)pixel = color;
}

unsigned int	img_get_pixel(t_img *img, int x, int y)
{
	char	*pixel;

	pixel = img->address + y * img->line_size + x * (img->bits_per_pixel / 8);
	return (*(unsigned int *)pixel);
}
