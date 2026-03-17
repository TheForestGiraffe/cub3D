/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 21:04:04 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/16 21:10:07 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	parser_validate_input(int argc, char **argv)
{
	char	*suffix;

	if (argc != 2)
		fatal_error(NULL, et_usage_fail);
	suffix = ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]));
	if (!suffix || suffix[4] != '\0')
		fatal_error(NULL, et_usage_fail);
}

void	parse_map(int argc, char **argv)
{
	parser_validate_input(argc, argv);
}
