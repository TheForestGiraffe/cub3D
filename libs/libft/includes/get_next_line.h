/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:43:22 by tcunha            #+#    #+#             */
/*   Updated: 2025/06/16 23:07:37 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <sys/types.h>

char	*get_next_line(int fd);
char	*extract_line(char **buffer, ssize_t line_len);
ssize_t	find_newline(const char *s);
int		update_buffer(ssize_t read_bytes, char **buffer, char *temp_buffer);
char	*line_or_cleanup(char **temp_buffer, char **buffer, ssize_t read_bytes);
void	ft_free(void **ptr);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int		gnl_strlen(char *str);

#endif
