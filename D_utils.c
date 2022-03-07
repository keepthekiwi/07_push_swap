/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:35:53 by skillian          #+#    #+#             */
/*   Updated: 2022/03/07 17:25:14 by skillian         ###   ########.fr       */
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

void	indexing(t_element **stack)
{
	t_element	*tmp;
	t_element	*to_check;

	to_check = *stack;
	while (to_check)
	{
		tmp = *stack;
		while (tmp)
		{
			if (to_check->value > tmp->value)
				to_check->index++;
			tmp = tmp->next;
		}
		to_check = to_check->next;
	}
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

int	get_length(t_element *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	print_list(t_element *stack)
{
	ft_printf("stack:\n");
	while (stack)
	{
		ft_printf("%i\n", stack->value);
		stack = stack->next;
	}
}