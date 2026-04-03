/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 09:30:55 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/03 09:51:55 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <unistd.h>

void	print_test_header(t_test *test)
{
	ft_putstr_fd("Test: ", STDOUT_FILENO);
	ft_putendl_fd(test->description, STDOUT_FILENO);
	ft_putendl_fd("Test Output:", STDOUT_FILENO);
}

void	print_test_result(t_test *test, int result)
{
	if (result == test->expected)
	{
		ft_putendl_fd("Result: [OK]", STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	else
	{
		ft_putendl_fd("Result: [KO]", STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
}

void	print_final_result(t_test_result *result)
{
	ft_putchar_fd('\n', STDOUT_FILENO);
	ft_putnbr_fd(result->passed, STDOUT_FILENO);
	ft_putchar_fd('/', STDOUT_FILENO);
	ft_putnbr_fd(result->total, STDOUT_FILENO);
	ft_putendl_fd(" tests passed\n", STDOUT_FILENO);
}
