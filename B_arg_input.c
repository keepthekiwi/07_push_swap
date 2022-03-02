/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_arg_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:30:28 by skillian          #+#    #+#             */
/*   Updated: 2022/03/02 16:49:41 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	init_stack(t_element **stack, char **args)
{
	int		i;
	char	**arr;

	i = 1;
	while (args[i])
	{
		just_digit_checker(args[i]);
		no_letter_checker(args[i]);							// wenn digit checker funktioniert, braucge ich das dann noch?
		if (quotation_arg_checker(args[i]))
		{
			arr = ft_split(args[i], ' ');
			while (*arr)
			{
				add_back(stack, new_element(atoi(*arr)));	//eigene atoi nehmen!!!
				arr++;
			}
		}
		else
			add_back(stack, new_element(atoi(args[i])));	//eigene atoi nehmen!!!
		i++;
	}
}

void	just_digit_checker(char *str)						//hier noch space mit beqhandeln //was jetzt mit vorzeichen???? +-
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9' )
			return ;
		str++;
	}
	exit(ft_printf("Error, not just digits.\n"));
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
			return (0);
		if (!last->next)
			break ;
		last = last->next;
	}
	last->next = new;
	return (1);
}

void	no_letter_checker(char *str)
{
	// if(!str)
	// 	return (false);
	while (*str)
	{
		if (ft_isalpha(*str) == 1)
			exit(ft_printf("Error, found letter.\n"));
		str++;
	}
	return ;
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
