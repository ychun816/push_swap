/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:39:11 by yilin             #+#    #+#             */
/*   Updated: 2024/07/09 19:13:27 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int	stack_len;

	a = NULL;
	b = NULL;
	/*check input*/
	if (ac == 1 || ac == 2 && !av[1][0])
		exit_program(av, "wrong!"); //or return(1) /*or exit(EXIT_FAILURE)? //exit program => put error*/
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	a = avs_to_stack_a(&a, av + 1); //Initiate stack `a`, which also handles errors //+1 => skip a.out
	if (!is_stack_sorted(a)) /*check if stack a in order => no need sort => free*/
	{
		//If not, and there are two numbers, swap the first two nodes
		if (stack_len == 2)
			sa(&a); TODO: //if to add boolean?
		//If not, and there are three numbers, call the sort three algorithm
		if (stack_len == 3)
			sort_small_3(&a);
		//If not, and there are more than three numbers, call the sort stacks algorithm
		else
			sort_big(&a, &b);
	}
	free_stack(&a); // Exit the program with a status of 1 (successful completion)
	return (0);
}