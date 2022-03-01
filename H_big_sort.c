/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   H_big_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:41:58 by skillian          #+#    #+#             */
/*   Updated: 2022/03/01 19:33:15 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	radix(t_element **stack_a, t_element **stack_b)
{
	t_element	*stack;
	int			length;
	int			max_bits;
	int			i;
	int			j;

	get_min_and_length(stack_a);
	length = (data()->counter);
	max_bits = 0;
	i = 0;

	while ((length >> max_bits) != 0)
		max_bits++;

	while (i < max_bits)
	{
		j = 0;
		while (j < length)
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
