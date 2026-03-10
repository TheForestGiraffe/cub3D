/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:43:47 by tcunha            #+#    #+#             */
/*   Updated: 2025/12/13 18:42:05 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

ssize_t	find_newline(const char *s)
{
	ssize_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*extract_line(char **buffer, ssize_t new_line)
{
	char	*line;
	char	*new_buffer;
	size_t	total_len;
	size_t	rest_len;

	total_len = gnl_strlen(*buffer);
	rest_len = total_len - (new_line + 1);
	line = malloc(new_line + 2);
	if (!line)
		return (ft_free((void **)buffer), NULL);
	ft_memcpy(line, *buffer, (new_line + 1));
	line[new_line + 1] = '\0';
	if (rest_len > 0)
	{
		new_buffer = malloc(rest_len + 1);
		if (!new_buffer)
			return (ft_free((void **)buffer), *buffer = NULL, free(line), NULL);
		ft_memcpy(new_buffer, (*buffer) + (new_line + 1), rest_len);
		new_buffer[rest_len] = '\0';
	}
	else
		new_buffer = NULL;
	return (ft_free((void **)buffer), *buffer = new_buffer, line);
}

int	update_buffer(ssize_t read_bytes, char **buffer, char *temp_buffer)
{
	char	*new_buffer;
	size_t	buffer_len;

	if (*buffer)
		buffer_len = gnl_strlen(*buffer);
	else
		buffer_len = 0;
	new_buffer = ft_realloc(*buffer, buffer_len, read_bytes + buffer_len + 1);
	if (!new_buffer)
		return (ft_free((void **)&temp_buffer), ft_free((void **)buffer), 0);
	*buffer = new_buffer;
	ft_memcpy(*buffer + buffer_len, temp_buffer, read_bytes);
	(*buffer)[buffer_len + read_bytes] = '\0';
	return (ft_free((void **)&temp_buffer), 1);
}

char	*line_or_cleanup(char **temp_buffer, char **buffer, ssize_t read_bytes)
{
	char	*leftover;

	ft_free((void **)temp_buffer);
	if (!read_bytes && *buffer)
	{
		leftover = *buffer;
		*buffer = NULL;
		return (leftover);
	}
	if (read_bytes < 0 && *buffer)
		ft_free((void **)buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*temp_buffer;
	ssize_t			read_bytes;
	ssize_t			new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_free((void **)&buffer), NULL);
	new_line = 0;
	while (1)
	{
		new_line = find_newline(buffer);
		if (new_line != -1)
			return (extract_line(&buffer, new_line));
		temp_buffer = malloc(BUFFER_SIZE + 1);
		if (!temp_buffer)
			return (ft_free((void **)&buffer), NULL);
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			return (line_or_cleanup(&temp_buffer, &buffer, read_bytes));
		temp_buffer[read_bytes] = '\0';
		if (!update_buffer(read_bytes, &buffer, temp_buffer))
			return (NULL);
	}
}
