/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:12:25 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/10 20:13:20 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_INTERNAL_H
# define MOVE_INTERNAL_H

# include "game.h"

int	is_valid_x(t_game *game, double new_x, double y);
int	is_valid_y(t_game *game, double x, double new_y);

#endif
