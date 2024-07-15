/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:39:11 by yilin             #+#    #+#             */
/*   Updated: 2024/07/15 19:53:43 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_both_stacks(t_stack **a, t_stack **b)
{
	clear_stack(a, &clear_content);
	clear_stack(b, &clear_content);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int	a_len;

	a = NULL;
	b = NULL;
	/*check input*/
	if (ac <= 1 || (ac == 2 && !av[1][0]))
	{
		if(ac == 2)
			ft_printf("Error\n");//write(STDERR_FILENO, "Error\n", 6);
		return (0);//return (EXIT_SUCCESS)
	}
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	check_av_input(ac, av);
	avs_to_stack_a(&a, (av + 1));//Initiate stack `a`, which also handles errors //+1 => skip a.out
	// ft_init_stk(&stk_a, ac, av, &ft_del);
	a_len = ft_stacklen(a); 
	if (!is_stack_sorted(a))/*check if stack a in order => no need sort => free*/
	{
		if (a_len <= 5)
			sort_stack_small(&a, &b, a_len);
		else
			sort_stack_big(&a, &b, a_len);
	}
	clear_both_stacks(&a, &b);
	if (ac == 2)
   		free_strs(av);
	return (0);//return (EXIT_SUCCESS);
}