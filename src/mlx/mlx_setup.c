/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:52:40 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/17 16:21:05 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* mlx_setup wraps:
	mlx_init
	mlx_new_window
	mlx_new_image
	mlx_get_data_addr and
	*/
// TODO: pass mlx instead of game
int	mlx_setup(t_game *game)
{
	t_mlx	*mlx;

	mlx = &game->mlx;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (ft_putstr_fd("Error\n@mlx_setup, mlx_init", 2), 2);
	mlx->window = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "Cub3D");
	if (!mlx->window)
		return (ft_putstr_fd("Error\n@mlx_setup, mlx_new_window", 2), 2);
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	if (!mlx->img.img)
		return (ft_putstr_fd("Error\n@mlx_setup, mlx_new_image", 2), 2);
	mlx->img.address = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_size, &mlx->img.endian);
	if (!mlx->img.address)
		return (ft_putstr_fd("Error\n@mlx_setup, mlx_get_data_addr", 2), 2);
	return (0);
}
