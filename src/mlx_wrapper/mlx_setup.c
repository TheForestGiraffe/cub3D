/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:52:40 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/03 15:11:54 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"
#include "mlx_wrapper_internal.h"
#include "libft.h"
#include "utils.h"

int	mlx_setup(t_game *game)
{
	t_mlx	*mlx;

	if (!game)
		return (1);
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		return (print_error("@mlx_setup", "mlx_init"), 1);
	mlx = &game->mlx;
	mlx->window = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "Cub3D");
	if (!mlx->window)
		return (print_error("@mlx_setup", "mlx_new_window"), 1);
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	if (!mlx->img.img)
		return (print_error("@mlx_setup", "mlx_new_image"), 1);
	mlx->img.address = mlx_get_data_addr(mlx->img.img,
			&mlx->img.bits_per_pixel,
			&mlx->img.line_size, &mlx->img.endian);
	if (!mlx->img.address)
		return (print_error("@mlx_setup", "mlx_get_data_addr"), 1);
	mlx_register_hooks(game);
	return (0);
}
