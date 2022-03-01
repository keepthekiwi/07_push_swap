/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:13:07 by skillian          #+#    #+#             */
/*   Updated: 2022/03/01 20:46:04 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	push(t_element **stack_1, t_element **stack_2, char *str)
{
	t_element	*tmp;

	if (*stack_1)
	{
		tmp = *stack_1;
		*stack_1 = tmp->next;
		tmp->next = *stack_2;
		*stack_2 = tmp;
		// if (ft_strlen(str))
		ft_printf("%s\n", str);
	}
}

void	swap (t_element **stack, char *str)
{
	t_element	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	ft_printf("%s\n", str);
}

void	rotate(t_element **stack, char *str)
{
	t_element	*tmp;
	t_element	*last_node;

	if (*stack)
	{
		tmp = *stack;
		last_node = get_last_node(*stack);
		*stack = (*stack)->next;
		last_node->next = tmp;
		tmp->next = NULL;
		ft_printf("%s\n", str);
	}
	return ;
}

t_element	*get_last_node (t_element *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	rev_rotate(t_element **stack, char *str)
{
	t_element *tmp;
	t_element *last_node;
	t_element *prev_node;

	tmp = *stack;
	
	while ((*stack)->next)
	{
		prev_node = *stack;
		if ((*stack)->next)
			*stack = (*stack)->next;
			last_node = *stack;
	}
	prev_node->next = NULL;
	last_node->next = tmp;
	ft_printf("%s\n", str);
}
