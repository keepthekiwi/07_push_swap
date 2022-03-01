/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:13:07 by skillian          #+#    #+#             */
/*   Updated: 2022/02/27 17:26:12 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"


//wo nutze ich diese? brauche an sich nur neue node, da stake schon erstellt
// typedef struct befuellen / Ein Element erstellen
t_element	*create_stake_and_first_node(int value)	// t_stack ist neue Node (also Element in Stack) 9:47
{
	t_element *new_node;							// new_node Element erstellen (greift oben auf den typedef struct zu)

	new_node = malloc(sizeof(t_element));			// Speicher dafuer freimachen
	new_node->value = value;						// Zahl der Node/Element
	new_node->next = NULL;							// erste Node (Tail) zeigt auf NULL
	return (new_node);
}

// // Neues Element hinzufuegen (push)
// void	push(t_element **stack, int value)
// {
// 	t_element *new_node;							// New Block erstellen (siehe oben typedef)

// 	new_node = malloc(sizeof(t_element));
// 	new_node->value = value;
// 	new_node->next = *stack;						// stakaddresse, also addresse vom naechsten element (also was zuletzt hinzugefuegt wurde)
// 	*stack = new_node;								// Pointer (Next) auf neue Node setzen
// }


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



// // Oberstes Element entfernen (pop)
// void	pop(t_element **stack)						// element** stake wird initialisiert
// {
// 	struct s_element *tmp_ptr;

// 	if(*stack != NULL)
// 	{
// 		ft_printf("Element popped: %i\n",(*stack) -> value);
// 		tmp_ptr = *stack;							// tmp_ptr mit dem Wert(?) vom aktuelen *stack befuellen-> zum Zwischenspeichern///=stack ist das komplette ding/quasi copy =*stack ist der value von stack, =&stack ist die Adresse
// 		*stack = (*stack) -> next;					// warum klammern wichtig???
// 		free(tmp_ptr);
// 	}
// 	else
// 		ft_printf("The stack is empty.\n");
// }

// Oberstes Element (Head) im Stack anzeigen
void	top(t_element *stack)
{
	if(stack != NULL)
		ft_printf("Element on top: %i\n", stack -> value);
	else
		ft_printf("Stack is empty.\n");
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


void	print_list(t_element *stack)
{
	ft_printf("stack:\n");
	while (stack)
	{
		ft_printf("%i\n", stack->value);
		stack = stack->next;
	}
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

