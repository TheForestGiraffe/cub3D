/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 22:05:35 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/21 18:09:01 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <unistd.h>

void	set_flag(int *status, t_element element)
{
	*status |= (1 << element);
}

int	has_flag(int status, t_element element)
{
	return (status & (1 << element));
}

int	is_finished(int status)
{
	return ((status & FINISHED) == FINISHED);
}

void	skip_spaces(char **str)
{
	while (**str && (**str == ' ' || (**str >= '\t' && **str <= '\r')))
		(*str)++;
}

void	print_error(char *file, char *function)
{
	ft_putendl_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd(", ", STDERR_FILENO);
	ft_putendl_fd(function, STDERR_FILENO);
}
