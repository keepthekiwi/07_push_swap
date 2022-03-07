/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   G_avoid_global.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:53:42 by skillian          #+#    #+#             */
/*   Updated: 2022/03/07 17:28:12 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

void	get_min_and_length(t_element **stack)
/* cool method to avoid global variable */
{
	int			i;
	int			counter;
	int			position_low;
	t_element	*tmp;

	tmp = *stack;
	counter = 1;
	position_low = 1;
	i = (*stack)->index;
	while (tmp->next)
	{
		if (i > tmp->index)
		{
			i = tmp->index;
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
