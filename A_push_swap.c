/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:29:24 by skillian          #+#    #+#             */
/*   Updated: 2022/03/08 17:43:21 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	int			valid_args;
	t_element	*stack_a;
	t_element	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, argv);
	if (!stack_a)
		return (error("Error\n"));
	indexing(&stack_a);
	valid_args = get_length(stack_a);
	if (valid_args == 2 && !is_sorted(stack_a))
		swap(&stack_a, "sa");
	if (valid_args == 3 && !is_sorted(stack_a))
		sort_three(&stack_a);
	if ((valid_args == 4 || valid_args == 5) && !is_sorted(stack_a))
		sort_four_and_five(&stack_a, &stack_b);
	if (valid_args > 5 && !is_sorted(stack_a))
		radix(&stack_a, &stack_b, 0);
	free_stack(&stack_a);
	return (0);
}
