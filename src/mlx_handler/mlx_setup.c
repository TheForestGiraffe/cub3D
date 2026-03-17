/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:52:40 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/17 21:52:42 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

//WIP
int	mlx_setup(t_mlx *mlx)
{
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
