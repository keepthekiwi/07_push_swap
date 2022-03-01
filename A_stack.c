/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:29:24 by skillian          #+#    #+#             */
/*   Updated: 2022/03/01 20:39:38 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int main(int argc, char **argv)
{
	(void)		argc;
	int			valid_args;
	t_element	*stack_a;
	t_element	*stack_b;

	stack_a = NULL;
	stack_b = NULL;	

	init_stack(&stack_a, argv);				//hier noch rein, if 0 dann exit... (also kein valid argument)

	if (is_sorted(stack_a))
		return (0);							//exit bzw exit schon in is_sorted drin

	get_min_and_length(&stack_a);
	valid_args = data()->counter;

	if (valid_args == 0)					// geht ueberhaut 0??
		return (0);
	if (valid_args <= 3)					//data counter woanders wieder geaendert???
		sort_three(&stack_a);				//hier eit drin, sonst wird <=5 noch getriggert
	if (valid_args <= 5)
		sort_four_and_five(&stack_a, &stack_b);
	else
	{
		indexing(&stack_a);
		radix(&stack_a, &stack_b);
	}
	return (0);
}
