/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:26:45 by skillian          #+#    #+#             */
/*   Updated: 2022/03/01 17:41:47 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define	PUSH_SWAP_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<limits.h>
# include	<stdbool.h>
# include	"libft/libft.h"
# include	"ft_printf/ft_printf.h"

typedef struct s_data
{
	int counter;
	int	pos_low;
	int pos_max;
}	t_data;

typedef struct s_element
{
	int value;										// Was wird im ,,Stack-Kasten" gepsiechert? bei Buchstaben char, Zahlen int
	struct s_element *next;							// points to the next Node in the list
	int index;
} t_element;


t_data		*data(void);

void		init_stack(t_element **stack, char **args);
int			add_back(t_element **list, t_element *new);
t_element	*new_element(int new);
t_element	*create_stake_and_first_node(int value);
void		print_list(t_element *stack);


void		push(t_element **stack_1, t_element **stack_2, char *str);
void		pop(t_element **stack);
void		top(t_element *stack);
void		rotate(t_element **stack, char *str);
void		rev_rotate(t_element **stack, char *str);
void		swap (t_element **stack, char *str);

void		arg_input(t_element **stack, int argc, char **argv);
void		get_numbers(t_element **stack, char *str);
t_element	*get_last_node (t_element *stack);
int			int_checker (char *argv);
void		no_letter_checker(char *str);
void		just_digit_checker(char *str);
int			quatation_arg_checker(char *str);

int			is_sorted(t_element *stack);
void 		sort_three(t_element **stack);
void		sort_four_and_five(t_element **stack_a, t_element **stack_b);
void		big_sort(t_element **stack_a, t_element **stack_b);

void		get_min_and_length(t_element **stack);
int			get_max_and_lenght(t_element *stack);

void		indexing(t_element **stack);
int			find_length(t_element **stack);

void radix(t_element **stack_a, t_element **stack_b);

# endif