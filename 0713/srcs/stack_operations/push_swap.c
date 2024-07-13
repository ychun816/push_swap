/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:39:11 by yilin             #+#    #+#             */
/*   Updated: 2024/07/13 21:54:04 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int	stack_len;
	char	**split_avs;

	a = NULL;
	b = NULL;
	/*check input*/
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (EXIT_FAILURE);
	else if (ac == 2)
	{
			split_avs = ft_split(av[1], ' ');
			if (!split_avs)
				return (EXIT_FAILURE);
			av = split_avs; // Use the newly allocated split strings
	}
	avs_to_stack_a(&a, (av + 1)); //Initiate stack `a`, which also handles errors //+1 => skip a.out
	stack_len = ft_stacklen(a); 
	if (!is_stack_sorted(a))/*check if stack a in order => no need sort => free*/
	{
		if (stack_len == 2)/*If not, and there are two numbers, swap the first two nodes*/
			sa(&a);
		else if (stack_len == 3)/*If not, and there are three numbers, call the sort three algorithm*/
			sort_stack_3small(&a);
		else/*If not, and there are more than three numbers, call the sort stacks algorithm*/
			sort_stack_big(&a, &b);
	}
	free_stack(&a); // Exit the program with a status of 1 (successful completion)
	if (ac == 2)
   		free_strs(av, ft_wordcount(av[1], ' ') + 1);// +1 for the NULL terminator
	return (EXIT_SUCCESS);
}