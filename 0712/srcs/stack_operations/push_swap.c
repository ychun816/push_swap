/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:39:11 by yilin             #+#    #+#             */
/*   Updated: 2024/07/12 16:44:44 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int	stack_len;

	a = NULL;
	b = NULL;
	// stack_len = 0;
	stack_len = ft_stacklen(a); 
	/*check input*/
	if (ac == 1 || (ac == 2 && !av[1][0]))
		// return (1);
		// exit(EXIT_FAILURE);
		exit_program((t_stack **)av, "wrong!"); //or return(1) /*or exit(EXIT_FAILURE)? //exit program => put error*/
	if (ac == 2)
		av = ft_split(av[1], ' ');
	avs_to_stack_a(&a, (av + 1)); //Initiate stack `a`, which also handles errors //+1 => skip a.out
	if (!is_stack_sorted(a)) /*check if stack a in order => no need sort => free*/
	{
		//If not, and there are two numbers, swap the first two nodes
		if (stack_len == 2)
			sa(&a);
		//If not, and there are three numbers, call the sort three algorithm
		else if (stack_len == 3)
			sort_stack_3small(&a);
		//If not, and there are more than three numbers, call the sort stacks algorithm
		else
			sort_stack_big(&a, &b);
	}
	free_stack(&a); // Exit the program with a status of 1 (successful completion)
	return (0);
}