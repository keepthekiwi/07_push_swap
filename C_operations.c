/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:13:07 by skillian          #+#    #+#             */
/*   Updated: 2022/03/01 20:27:27 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// push vpn stack A to B
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

//wie muss Funktion dazu aussehen?
void	swap (t_element **stack, char *str)	//wenn ich funktion nutze, gebe ich *stack pointer rein, daher ist es hier dann **	//kann alles in eine Funktion packen
{
	t_element *tmp;

	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	// tmp = *stack;							//zugriff auf head!!! pointed zum ersten Element // * um wert zu uebernehmen
	// *stack= (*stack)->next;
	// tmp->next = (*stack)->next;				//zugriff auf zweite/naechstes Element
	
	// (*stack)->next = tmp;

	ft_printf("%s\n", str);
}

void	rotate(t_element **stack, char *str)
{
	t_element *tmp;							//EINFACHER: temp pointer = stack pointer   t_element *tmp = *stack
	t_element *last_node;

	if(*stack)
	{
		tmp = *stack;						//erste Node (head)  / *swap ist derPointer der auf Start/Head von Linked List zeigt
		last_node = get_last_node(*stack);	//finden letzter Node (Tail)
		*stack = (*stack)->next;			//erste Node (Head) wird durch zweite Node "ersetzt", Kette wird nachgezogen
		last_node->next = tmp;				//letzte Node(tail) wird mit erster Node(head getauscht)
		tmp->next = NULL;					//erste Node (head) ist jetzt letzte Node(Tail) und zeigt somit auf NULL
		ft_printf("%s\n", str);
	}

	return ;
}

t_element *get_last_node (t_element *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;				//zeigt jetzt auf nachfolgende Node
	return (stack);
}

void	rev_rotate(t_element **stack, char *str)
{
	t_element *tmp;
	t_element *last_node;
	t_element *prev_node;

	tmp = *stack;								//tmp pointer = stack pointer (HEAD)
	
	while((*stack)->next)
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

int is_sorted(t_element *stack) // keinen doppel** weil ich stack nicht modifizieren will
{
	while (stack->next)
	{
		if (stack->value > stack->next->value) //geil!
			return (false);
		stack = stack->next;
	}
	// ft_printf("Stack is sorted\n\n"); // doppel n raus //wieder rein, wenn visualizer weg
	return (true);
}
