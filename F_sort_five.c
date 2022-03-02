/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   F_sort_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:07:57 by skillian          #+#    #+#             */
/*   Updated: 2022/03/02 17:06:42 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort_four_and_five(t_element **stack_a, t_element **stack_b)
{
	while (data()->counter > 3)
	{
		if (data()->pos_low == 1)
		{
			push(stack_a, stack_b, "pb");
			get_min_and_length(stack_a);
		}
		while (data()->pos_low != 1 && data()->pos_low <= 3)
		{
			rotate(stack_a, "ra");
			get_min_and_length(stack_a);
			if (data()->pos_low == 1)
				break ;
		}
		while (data()->pos_low != 1 && data()->pos_low > 3)
		{
			rev_rotate(stack_a, "rra");
			get_min_and_length(stack_a);
			if (data()->pos_low == 1)
				break ;
		}
	}
	sort_three(stack_a);
	while (*stack_b)
		push(stack_b, stack_a, "pa");
}
