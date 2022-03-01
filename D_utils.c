/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:35:53 by skillian          #+#    #+#             */
/*   Updated: 2022/02/28 17:41:12 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ft_ft_printf in library hinzufuegen
//alle ft_printf zu ft_ft_printf
//doppelte zahlen in input raus
//checken was bei "" und " " als input passiert

#include "./push_swap.h"

//kleinste zahl finden
//schauen ob nach oben oder nach unten kuezer ist, um nach oben zu bringen
//swap zu stack_b
//


void get_min_and_length(t_element **stack)
{
	int i;
	int counter;
	int position_low;
	t_element *tmp;

	tmp = *stack;
	counter = 1;
	position_low = 1;

	i = (*stack)->value;

	while(tmp->next)
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
	data()->pos_low	= position_low;

	// ft_printf("Lowest number: %i\n", i);
	// ft_printf("Counter: %i\n", counter);
	// ft_printf("Position lowest: %i\n", position_low);

	return ;
}

// void big_sort(t_element **stack_a, t_element **stack_b)
// {
// 	find_lowest_nbr_and_length(stack_a);
// 	while (data()->counter >= 3)
// 	{
// 		find_lowest_nbr_and_length(stack_a);

// 		if ((data()->counter / 2) >= data()->pos_low)
// 			{
// 				if (data()->pos_low > 1)
// 					rotate(stack_a, "rr");
// 				push(stack_a, stack_b, "pa");
// 			}

// 		if ((data()->counter / 2) < data()->pos_low)
// 			{
// 				if (data()->pos_low > 1)
// 					rev_rotate(stack_a, "rev_rr");
// 				push(stack_a, stack_b, "pa");
// 			}

// 		if (data()->counter == 3)
// 		{
// 			sort_three(stack_a);
// 			return ;
// 		}
// 	}
// }


t_data	*data(void)
{
	static t_data data;

	return &data;
}


// static int	sort_medium(t_element **stack_a, int size)
// {
// 	int			min;
// 	t_element	*stack_b;

// 	stack_b = NULL;
// 	while (size-- > 3)
// 	{
// 		min = get_min(*stack_a);
// 		if ((*stack_a)->value == min)
// 		{
// 			push(&stack_b, stack_a, 'b');
// 			min = get_min(*stack_a);
// 		}
// 		while ((*stack_a)->value != min)
// 		{
// 			if ((*stack_a)->next->value == min)
// 				stack_a = rrotate(stack_a, 'pa');
// 			else
// 				stack_a = rotate(stack_a, 'pa');
// 		}
// 		push(&stack_b, stack_a, 'b');
// 	}
// 	sort_small(stack_a, 3);
// 	while (stack_b != NULL)
// 		push(stack_a, 'pa');
	
// 	return (0);
// }


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



int	get_max_and_lenght(t_element *stack)
{
	int i;
	int counter;
	int position_max;
	t_element *tmp;

	counter = 1;
	tmp = stack;
	position_max = 1;

	i = stack->value;

	while(tmp->next)
	{
		if (i < tmp->value)
		{
			i = tmp->value;
			position_max = counter;
		}
		counter++;
		tmp = tmp->next;
	}
	data()->counter = counter;
	data()->pos_max	= position_max;

	ft_printf("Position highest: %i\n", position_max);

	return (position_max);
}

///ODER SO

int	find_length(t_element **stack)
{
	int	length;

	length = 0;
	while (*stack)
	{
		*stack = (*stack)->next;
		length++;
	}
	return (length);
}

// int	find_min(t_element **stack)
// {
// 	int	min;
// 	int	current;

// 	current = (*stack)->value;
// 	min = current;
// 	while (*stack)
// 	{
// 		if ((*stack)->value < min)
// 			min = (*stack)->value;
// 		*stack = (*stack)->next;
// 	}
// 	return (min);
// }