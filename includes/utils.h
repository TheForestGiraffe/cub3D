#ifndef ERROR_H
# define ERROR_H

struct	s_game;

typedef enum e_error_type
{
	none,
	et_mlx_init,
	et_win_init,
	et_alloc_fail,
	et_img_fail,
	et_count
}	t_error_type;

void	fatal_error(struct s_game *game, t_error_type error);

#endif
