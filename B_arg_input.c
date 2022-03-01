/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_arg_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:30:28 by skillian          #+#    #+#             */
/*   Updated: 2022/02/28 20:20:37 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

///errror fuer doppel 1 (bz doppelte nummer)!!! noch einfuegen


void arg_input(t_element **stack, int argc, char **argv)
{
	(void) stack; 	//geiler Trick
	(void) argv;	//geiler Trick
	int i;
	i = 1;
	
	if (i >= argc)
		ft_printf("argc is wrong check arg_input\n");
	else
		ft_printf("arg passt, ist >= 1\n");

}

// static int digit_checker(char *str)
// {
// 	if(!str)
// 		return (false);
// 	while(*str)
// 	{
// 		if (ft_isdigit(*str) == 1)
// 			return(true);
// 		str++;
// 	}
// 	return (false);	
// }





// static int space_checker(char *str)
// {
// 	while(*str)
// 	{
// 		if (*str == ' ')
// 			return (true);						// space gefunden
// 		str++;
// 	}
// 	return (false);								// kein space gefunden
// }


//erst arg checken nach buchstaben
//" entfernen"


void	init_stack(t_element **stack, char **args)
{
	int i;
	i = 1;
	char **arr;

	while (args[i])
	{
		just_digit_checker(args[i]);
		no_letter_checker(args[i]);				// wenn digit checker funktioniert, braucge ich das dann noch?

		if(quatation_arg_checker(args[i]))
		{
			arr = ft_split(args[i], ' ');
			while(*arr)
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

// if (str[i] == ' ' || str[i] == '-' || ft_isdigit(str[i])) --> i++;
// if (str[i] == '-' && ft_isdigit[str[i+1]])


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
	return(0);
}




// kann auch beides zusammenbringen, also space und letter

// void get_numbers(t_element **stack, char *str)
// {
// 	char **number_array;
// 	int i;

// 	i = 0;
// 	if (!str)
// 		return ;
// 	number_array = ft_split(str, ' ');
// 	while (number_array[i])
// 	{
// 		push(stack, atoi(number_array[i]));
// 		i++;
// 	}
// 	// if (!number_array)
// 	// 	return (0);
// 	// return (number_array);
// }

// int int_checker (char *argv)			///char???
// {
// 	long long	num;					//long long??? weil int in beide richtungen
// 	num = ft_atoi_l(argv);				///welche funktion mit l war das? angepasst mit long long in funtkion
// 	if (num < INT_MIN || num > INT_MAX)
// 		return (false);
// 	return (true);
// }
