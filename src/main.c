#include "game.h"
#include "libft.h"
#include "utils.h"
#include <mlx.h>
#include <stdlib.h>

static void	game_init(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		fatal_error(game, et_mlx_init);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	if (!game->win)
		fatal_error(game, et_win_init);
}

static void	game_destruct(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	main(void)
{
	t_game	game;

	game_init(&game);
	game_destruct(&game);
	return 0;
}
