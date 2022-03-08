/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:26:45 by skillian          #+#    #+#             */
/*   Updated: 2022/03/08 16:56:36 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<limits.h>
# include	<stdbool.h>
# include	"libft/libft.h"
# include	"ft_printf/ft_printf.h"

typedef struct s_data
{
	int					counter;
	int					pos_low;
	int					pos_max;
}	t_data;

typedef struct s_element
{
	int					value;
	struct s_element	*next;
	int					index;
}	t_element;

t_data		*data(void);

void		init_stack(t_element **stack, char **args);
int			add_back(t_element **list, t_element *new);
t_element	*new_element(int new);

void		push(t_element **stack_1, t_element **stack_2, char *str);
void		swap(t_element **stack, char *str);
void		rotate(t_element **stack, char *str);
void		rev_rotate(t_element **stack, char *str);

void		arg_input(t_element **stack, int argc, char **argv);
t_element	*get_last_node(t_element *stack);
int			int_checker(char *argv);
void		just_digit_checker(char *str);
int			quotation_arg_checker(char *str);
int			is_sorted(t_element *stack);
void		get_min_and_length(t_element **stack);
int			get_length(t_element *stack);
int			error(char *str);
int			int_min_max_checker(char *ptr);
void		free_stack(t_element **stack);
void		free_split(char **arr);

void		indexing(t_element **stack);
void		sort_two(t_element **stack);
void		sort_three(t_element **stack);
void		sort_four_and_five(t_element **stack_a, t_element **stack_b);
void		big_sort(t_element **stack_a, t_element **stack_b);
void		radix(t_element **stack_a, t_element **stack_b, int i);

#endif