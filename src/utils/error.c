/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:02:01 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/10 19:02:15 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdlib.h>
#include <unistd.h>

static char	*error_fetch_message(t_error_type error)
{
	if (error == et_mlx_init)
		return ("Failure to get mlx pointer");
	else if (error == et_win_init)
		return ("Failure to get window pointer");
	else if (error == et_alloc_fail)
		return ("Failure to allocate memory");
	else if (error == et_img_fail)
		return ("Failure to create image");
	else
		return ("Unknown error");
}

static void	error_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}

void	fatal_error(t_game *game, t_error_type error)
{
	char	*message;

	message = error_fetch_message(error);
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, message, ft_strlen(message));
	write(STDERR_FILENO, "\n", 1);
	error_exit(game);
}
