/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D_sort_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:23:51 by skillian          #+#    #+#             */
/*   Updated: 2022/02/23 23:43:07 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void 	sort_three(t_element **stack)		//t_element stack kreiieren
{
	int	a;
	int b;
	int c;

	a = (*stack)->value;					//geil das man das so machen kann!!!
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;

	if(is_sorted(*stack))
		return ;

	// 2 3 1
	if (a < b && a > c && b > c)
		rev_rotate(stack, "rra"); //richtige bezeichnung rra wichtig! da visualizer nach den buchtaben das anwendet

	// 2 1 3
	if (a > b && a < c && b < c)
		swap(stack, "sa");

	// 3 2 1
	if (a > b && a > c && b > c) // oder swap und dann rev rotate
	{
		rotate(stack, "ra");
		swap(stack, "sa");
	}

	// 3 1 2
	if (a > b && a > c && b < c)
		rotate(stack, "ra");

	// 1 3 2
	if (a < b && a < c && b > c)
	{
		swap(stack, "sa");
		rotate(stack, "ra");
	}
	// 1 2 3 bleibt
}

