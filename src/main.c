/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:00:41 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/16 13:11:24 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	main(int argc, char **argv)
{
	t_parsed_model	*parsed_model;

	parsed_model = parse(argc, argv);
	if (!parsed_model)
		return (1);
	
	return (0);
}
