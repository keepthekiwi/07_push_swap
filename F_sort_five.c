/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   F_sort_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:07:57 by skillian          #+#    #+#             */
/*   Updated: 2022/03/02 21:17:15 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	find_min(t_element *stack, int index)
{
	int res;

	res = 0;
	while (stack)
	{
		if (stack->index == index)
			return (res);
		res++;
		stack = stack->next;
	}
	return (-1);
}

void	sort_four_and_five(t_element **stack_a, t_element **stack_b)
{
	int index;
	int pos;

	index = 0;
	pos = 0;
	while (get_lenght(*stack_a) > 3)
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
			if (pos < (get_lenght(*stack_a) / 2))
				rotate(stack_a, "ra");
			else
				rev_rotate(stack_a, "rra");
		}
		// if (data()->pos_low == 1)
		// {
		// 	push(stack_a, stack_b, "pb");
		// 	get_min_and_length(stack_a);
		// }
		// while (data()->pos_low != 1 && (data()->pos_low) == 2)
		// {
		// 	rotate(stack_a, "ra");
		// 	get_min_and_length(stack_a);
		// 	if (data()->pos_low == 1)
		// 		break ;
		// }
		// while (data()->pos_low != 1 && (data()->pos_low) > 2)
		// {
		// 	rev_rotate(stack_a, "rra");
		// 	get_min_and_length(stack_a);
		// 	if (data()->pos_low == 1)
		// 		break ;
		// }
	}
	sort_three(stack_a);
	while (*stack_b)
		push(stack_b, stack_a, "pa");
}


// void	sort_four_and_five(t_element **stack_a, t_element **stack_b)
// {
// 	while (data()->counter > 3)
// 	{
// 		if (data()->pos_low == 1)
// 		{
// 			push(stack_a, stack_b, "pb");
// 			get_min_and_length(stack_a);
// 		}
// 		while (data()->pos_low != 1 && data()->pos_low <= 3)
// 		{
// 			rotate(stack_a, "ra");
// 			get_min_and_length(stack_a);
// 			if (data()->pos_low == 1)
// 				break ;
// 		}
// 		while (data()->pos_low != 1 && data()->pos_low > 3)
// 		{
// 			rev_rotate(stack_a, "rra");
// 			get_min_and_length(stack_a);
// 			if (data()->pos_low == 1)
// 				break ;
// 		}
// 	}
// 	sort_three(stack_a);
// 	while (*stack_b)
// 		push(stack_b, stack_a, "pa");
// }
