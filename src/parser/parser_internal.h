#ifndef PARSER_INTERNAL_H
# define PARSER_INTERNAL_H

# define FINISHED 0x3F

# include "parser.h"

int		parser_map(t_map *map, int fd);
int		parser_retrieve_grid(struct s_list **list, int fd);
int		parser_validate_grid(t_map *map);
int		parser_textures(t_map *map, int fd);
void	set_flag(int *status, t_element element);
int		has_flag(int status, t_element element);
int		is_finished(int status);
void	skip_spaces(char **str);
void	free_array(char **array);

#endif
