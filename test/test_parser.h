/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 09:29:38 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/12 15:04:16 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_PARSER_H
# define TEST_PARSER_H

# define TEST_MAX  8192

# include "parser.h"

typedef struct s_test
{
	t_map	map;
	char	*grid;
	int		expected;
	char	*description;
}	t_test;

typedef struct s_test_result
{
	int		result;
	int		passed;
	int		total;
}	t_test_result;

int		tests_init(t_list **tests, t_test_result *result);
void	print_test_header(t_test *test);
void	print_test_result(t_test *test, int result);
void	print_final_result(t_test_result *result);

#endif
