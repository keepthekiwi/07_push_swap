/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   G_sort_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:07:57 by skillian          #+#    #+#             */
/*   Updated: 2022/03/08 17:42:17 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	find_min(t_element *stack, int index)
{
	int	pos_min;

	pos_min = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos_min);
		pos_min++;
		stack = stack->next;
	}
	return (-1);
}

void	sort_four_and_five(t_element **stack_a, t_element **stack_b)
{
	int	index;
	int	pos;

	index = 0;
	pos = 0;
	while (get_length(*stack_a) > 3)
	{
		if ((*stack_a)->index == index)
		{
			push(stack_a, stack_b, "pb");
			index++;
			continue ;
		}
		pos = find_min(*stack_a, index);
		while ((*stack_a)->index != index)
		{
			if (pos < (get_length(*stack_a) / 2))
				rotate(stack_a, "ra");
			else
				rev_rotate(stack_a, "rra");
		}
	}
	sort_three(stack_a);
	while (*stack_b)
		push(stack_b, stack_a, "pa");
}
