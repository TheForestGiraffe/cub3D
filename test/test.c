/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 09:55:43 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/03 10:34:56 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "test.h"
#include <stdlib.h>

static void	free_test(t_test *test)
{
	free(test->grid);
	free(test->description);
	free(test);
}

static void	test_result_update(t_test_result *result, t_test *test)
{
	result->passed += (result->result == test->expected);
	result->total++;
}

int	main(void)
{
	t_list			*tests;
	t_list			*node;
	t_test			*single_test;
	t_test_result	result;

	if (tests_init(&tests, &result))
		return (1);
	node = tests;
	while (node)
	{
		single_test = node->content;
		ft_memset(&single_test->map, 0, sizeof(t_map));
		print_test_header(single_test);
		result.result = parser(2, single_test->grid, &single_test->map);
		parser_destroy(&single_test->map);
		print_test_result(single_test, result.result);
		test_result_update(&result, single_test);
		node = node->next;
	}
	ft_lstclear(&tests, (void (*)(void *))free_test);
	print_final_result(&result);
	return (result.passed != result.total);
}
