/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_arg_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:30:28 by skillian          #+#    #+#             */
/*   Updated: 2022/03/08 15:45:37 by skillian         ###   ########.fr       */
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
		if (!arr)
			error("Error\n");
		tmp = arr;
		while (*arr)
		{
			just_digit_checker(*arr);
			int_min_max_checker(*arr);
			add_back(stack, new_element(ft_atoi(*arr)));
			arr++;
		}
		free_split(tmp);
		i++;
	}
}

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
			exit(error("Error\n"));
	}
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
			exit (error("Error\n"));
		if (!last->next)
			break ;
		last = last->next;
	}
	last->next = new;
	return (1);
}

int	int_min_max_checker(char *ptr)
{
	int					i;
	long long int		num;

	i = ft_strlen(ptr);
	if (i > 11)
		exit(error("Error\n"));
	if (i < 10)
		return (0);
	num = ft_atoi(ptr);
	if (num > INT_MAX || num < INT_MIN)
		exit(error("Error\n"));
	return (0);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = 0;
		i++;
	}
	free(arr);
	arr = 0;
}
