/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:54:19 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/10 19:01:48 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

struct	s_list;

typedef enum e_error_type
{
	none,
	et_mlx_init,
	et_win_init,
	et_alloc_fail,
	et_img_fail,
	et_count
}	t_error_type;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	struct s_list	*gc;
}	t_game;

#endif
