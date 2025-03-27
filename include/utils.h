#ifndef UTILS_H
# define UTILS_H

# include "cube.h"

/*---------------------------------------------------------------------------*/
/*                                exit.c                                     */
/*---------------------------------------------------------------------------*/
void	safe_exit(t_data *data);
void	safe_exit_parse(t_data *data, t_lststr **lst_map, char *line, \
						char *error_message);

/*---------------------------------------------------------------------------*/
/*                               lst_str.c                                   */
/*---------------------------------------------------------------------------*/

t_bool	add_content_lst(t_lststr **lst_str, char *new_content);
void	clear_lst_str(t_lststr **lst_str);
size_t	len_lst(t_lststr **lst_str);

/*---------------------------------------------------------------------------*/
/*                        free_double_array                                  */
/*---------------------------------------------------------------------------*/

void	free_double_array(void **array);

/* ************************************************************************** */
/*									ERROR									  */
/* ************************************************************************** */

void	exit_with_msg(char *comment, int code);
void	exit_free_with_msg(char *comment, t_data *data, int code);


/* ************************************************************************** */
/*									VEC_TOOLS								  */
/* ************************************************************************** */

t_vi2d	sum_vec2d(t_vi2d position, t_vi2d to_sum);
t_vi2d	sub_vec2d(t_vi2d position, t_vi2d to_sub);
t_vi2d	mul_vec2d(t_vi2d position, t_vi2d to_mul);

/* ************************************************************************** */
/*									TIME									  */
/* ************************************************************************** */

int	wait_fps(void);

#endif
