/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   H_big_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:41:58 by skillian          #+#    #+#             */
/*   Updated: 2022/03/02 17:13:18 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	radix(t_element **stack_a, t_element **stack_b, int i)
{
	t_element	*stack;
	int			max_bits;
	int			j;

	get_min_and_length(stack_a);
	max_bits = 0;
	while (((data()->counter) >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < (data()->counter))
		{
			stack = *stack_a;
			if (((stack->index >> i) & 1) == 1)
				rotate(stack_a, "ra");
			else
				push(stack_a, stack_b, "pb");
			j++;
		}
		while (*stack_b)
			push(stack_b, stack_a, "pa");
		i++;
	}
}
