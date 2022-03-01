/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_arg_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:30:28 by skillian          #+#    #+#             */
/*   Updated: 2022/03/01 20:40:57 by skillian         ###   ########.fr       */
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
		no_letter_checker(args[i]);				// wenn digit checker funktioniert, braucge ich das dann noch?

		if (quatation_arg_checker(args[i]))
		{
			arr = ft_split(args[i], ' ');
			while (*arr)
			{
				add_back(stack, new_element(atoi(*arr)));
				arr++;
			}
		}
		else
			add_back(stack, new_element(atoi(args[i])));
		i++;
	}
}

void just_digit_checker(char *str) //hier noch space mit beqhandeln
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9' )
			return ;
		str++;
	}
	exit(ft_printf("Error, not just digits.\n"));
}

// Neues Element am Ende des Strings hinzufuegen (sonst 5 6 7 -> 7 6 5)
int	add_back(t_element **list, t_element *new)
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
	//checker ob Element doppelt drin
	while (last)							
	{
		if (new->value == last->value)
			return (0);
		if (!last->next)
			break ;
		last = last->next;
	}
	//
	last->next = new;
	return (1);
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

void no_letter_checker(char *str)
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

int quatation_arg_checker(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return (1);
		str++;
	}
	return (0);
}
