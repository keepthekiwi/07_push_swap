/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:29:24 by skillian          #+#    #+#             */
/*   Updated: 2022/03/01 17:45:49 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int main(int argc, char **argv)
{
	(void)	argc;

	t_element	*stack_a;
	t_element	*stack_b;

	stack_a = NULL;
	stack_b = NULL;				//reciht zum createn von stake_b, da NULL Pointer. Aller was ich hier rein schiebe (von a zu b) ist ja schon ge-malloc-ed und aedere nur pointer

	// counter_var(0);				//geht das????
	// position_low_var(0);


	init_stack(&stack_a, argv);				// **(STEP 1)**
	// arg_input(&stack_a, argc, argv);
	// print_list(stack_a);
	
	if (is_sorted(stack_a))					// **(STEP 2)**
		return (0);							//exit bzw exit schon in is_sorted drin

//**Sorting***
	// sort_three(&stack_a);				// **(STEP 3)**
	// sort_four_and_five(&stack_a, &stack_b);	// **(STEP 3)**

	// big_sort(&stack_a, &stack_b);

	// get_min_and_length(&stack_a);
	// print_list(stack_a);


//**Test Operations**
	// push(&stack_a, &stack_b, "pb");
	// swap (&stack_a, "sa");
	// rotate(&stack_a, "ra");
	// rev_rotate(&stack_a, "rra");

	indexing(&stack_a);
	radix(&stack_a, &stack_b);

	// print_list(stack_a);
	// print_list(stack_b);

	return 0;
}
