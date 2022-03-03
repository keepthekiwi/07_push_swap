/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_arg_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:30:28 by skillian          #+#    #+#             */
/*   Updated: 2022/03/03 17:29:08 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	init_stack(t_element **stack, char **args)
{
	int		i;
	char	**arr;
	char	**tmp;

	i = 1;
	while (args[i])
	{
		
		arr = ft_split(args[i], ' ');
		tmp = arr
		if (!arr);
			// error idk fo rmalloc error
		while (*arr)
		{
			just_digit_checker(*arr);
			// check if bigger / smaller than max min int
			
			// schrittfolge
			// first romove + sign
			// remove leading zeros maybe 0000123 -> 123 | -000123 -> -123
			// if - strcmp mit min int
			// if  positive strcmp mit max int
			// if strcm is negativ strcmP(MAX_INT, str) return false -> number bigger / smaller than int
			add_back(stack, new_element(ft_atoi(*arr)));
			arr++;
		}
		// free tmp here sonst leaks (da ich arr++ machen und dann andere adresse habe als arr !!! | char ** char * free char **
		i++;
	}
}
//quotations muss ich nicht beachten

void	just_digit_checker(char *str)
{
	int	i;

	i = 1;
	while (*str)
	{
		if (i == 1)
		{
			if (*str == '-' || *str == '+')
			str++;
		}
		i--;
		if (*str >= '0' && *str <= '9')
			str++;
		else
			exit(error("Error, not just digits.\n"));
	}
}

int	quotation_arg_checker(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return (1);
		str++;
	}
	return (0);
}

int	add_back(t_element **list, t_element *new)
/* add element in the end of a string (5 6 7 -> 7 6 5) /
+ Checker of doubles: Line 67*/
{
	t_element	*last;

	if (new == NULL)
		return (0);
	if (*list == NULL)
	{
		*list = new;
		return (1);
	}
	last = *list;
	while (last)
	{
		if (new->value == last->value)
			exit (error("Error, double number\n"));
		if (!last->next)
			break ;
		last = last->next;
	}
	last->next = new;
	return (1);
}

void int_min_max_checker(t_element *stack)
{
	while (stack)
		{
			if ((stack->value) < INT_MIN || (stack->value) > INT_MAX)
				(error("Stack is empty.\n"));
			stack++;
		}
	return;
}
