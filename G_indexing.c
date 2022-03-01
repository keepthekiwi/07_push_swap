/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   G_indexing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:53:42 by skillian          #+#    #+#             */
/*   Updated: 2022/03/01 17:48:02 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void indexing(t_element **stack)		//kann auch hier tmp unterbringen
{

	t_element	*tmp;
	t_element	*to_check;

	to_check = *stack;
	while(to_check)
	{
		tmp = *stack;
		while (tmp)
		{
			if (to_check->value > tmp->value)
				to_check->index++;
			// if (to_check == check_with)
				// ft_printf("error, double number");
			tmp = tmp->next;
		}
		// printf("Hier: val - %d, index - %d\n", to_check->value, to_check->index); /////
		to_check = to_check->next;
	}
}
