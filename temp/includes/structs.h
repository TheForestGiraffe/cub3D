/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:54:19 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/16 13:54:36 by pecavalc         ###   ########.fr       */
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
	et_usage_fail,
	et_count
}	t_error_type;

#endif
