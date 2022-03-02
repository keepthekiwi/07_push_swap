/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:35:53 by skillian          #+#    #+#             */
/*   Updated: 2022/03/02 16:47:27 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	is_sorted(t_element *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	get_min_and_length(t_element **stack)
{
	int			i;
	int			counter;
	int			position_low;
	t_element	*tmp;

	tmp = *stack;
	counter = 1;
	position_low = 1;
	i = (*stack)->value;
	while (tmp->next)
	{
		if (i > tmp->value)
		{
			i = tmp->value;
			position_low = counter;
		}
		counter++;
		tmp = tmp->next;
	}
	data()->counter = counter;
	data()->pos_low = position_low;
	return ;
}

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

t_element	*new_element(int nbr)
{
	t_element	*new;

	new = (t_element *) malloc(sizeof(t_element));
	if (!new)
		return (NULL);
	new->value = nbr;
	new->index = 0;
	new->next = NULL;
	return (new);
}

int	get_min(t_element *stack)
{
	int			min;
	t_element	*tmp;

	tmp = stack;
	min = (tmp)->value;
	tmp = (tmp)->next;
	while (tmp != stack)
	{
		if ((tmp)-> value < min)
			min = (tmp)->value;
		tmp = (tmp)->next;
	}
	return (min);
}
