/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   E_sort_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:23:51 by skillian          #+#    #+#             */
/*   Updated: 2022/03/01 20:30:05 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void 	sort_three(t_element **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;

	if (is_sorted(*stack))
		return ;
	if (a < b && a > c && b > c)
		rev_rotate(stack, "rra");
	if (a > b && a < c && b < c)
		swap(stack, "sa");
	if (a > b && a > c && b > c)
	{
		rotate(stack, "ra");
		swap(stack, "sa");
	}
	if (a > b && a > c && b < c)
		rotate(stack, "ra");
	if (a < b && a < c && b > c)
	{
		swap(stack, "sa");
		rotate(stack, "ra");
	}
}
