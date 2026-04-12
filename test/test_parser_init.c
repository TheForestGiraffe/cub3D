/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 09:53:32 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/12 15:04:35 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_parser.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	parse_single_test(char *test_entry, t_test *test)
{
	char	**parts;
	int		i;

	parts = ft_split(test_entry, ';');
	if (!parts || !parts[0] || !parts[1] || !parts[2])
	{
		i = 0;
		while (parts && parts[i])
			free(parts[i++]);
		free(parts);
		return (1);
	}
	test->grid = parts[0];
	test->expected = ft_atoi(parts[1]);
	test->description = parts[2];
	free(parts[1]);
	free(parts);
	return (0);
}

static int	read_test_file(char ***tests)
{
	char	buf[TEST_MAX];
	int		fd;

	fd = open("test/test_parser.conf", O_RDONLY);
	if (fd == -1)
		return (1);
	ft_memset(buf, 0, TEST_MAX);
	read(fd, buf, TEST_MAX - 1);
	close(fd);
	*tests = ft_split(buf, '\n');
	if (!*tests)
		return (1);
	return (0);
}

static int	load_tests(t_list **list)
{
	char	**tests;
	t_test	*single_test;
	int		i;

	tests = NULL;
	*list = NULL;
	if (read_test_file(&tests))
		return (1);
	i = 0;
	while (tests[i])
	{
		single_test = malloc(sizeof(t_test));
		if (!single_test || parse_single_test(tests[i], single_test))
			return (free(single_test), free(tests[i]), 1);
		ft_lstadd_back(list, ft_lstnew(single_test));
		free(tests[i]);
		i++;
	}
	free(tests);
	return (0);
}

int	tests_init(t_list **tests, t_test_result *result)
{
	if (load_tests(tests))
		return (1);
	ft_memset(result, 0, sizeof(t_test_result));
	ft_putendl_fd("\n--- Cub3D Test ---\n", STDOUT_FILENO);
	return (0);
}
