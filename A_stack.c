/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:29:24 by skillian          #+#    #+#             */
/*   Updated: 2022/03/02 21:57:44 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	int			valid_args;
	t_element	*stack_a;
	t_element	*stack_b;

	(void)argc;
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, argv);
	if (!stack_a)
		return (ft_printf("Stack is empty.\n"));
	if (is_sorted(stack_a))
		return (ft_printf("Stack is sorted.\n"));
	indexing(&stack_a);
	valid_args = get_length(stack_a);
	if (valid_args <= 3)
		sort_three(&stack_a);
	if (valid_args <= 5)
		sort_four_and_five(&stack_a, &stack_b);
	else
		radix(&stack_a, &stack_b, 0);
	return (0);
}
