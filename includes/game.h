#ifndef GAME_H
# define GAME_H

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

struct	s_list;

typedef struct	s_game
{
	void			*mlx;
	void			*win;
	struct s_list	*gc;
}	t_game;

#endif
