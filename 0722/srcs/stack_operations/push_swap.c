/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:39:11 by yilin             #+#    #+#             */
/*   Updated: 2024/07/22 21:29:14 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_result(t_stack *a)
{
	t_stack *stack;

	stack = a;
	while (stack)
	{
		ft_printf("%d\n", stack->content);
		stack = stack->next;
	}
}

static void	start_sort(t_stack **a, t_stack **b)
{
	if (ft_stacklen(*a) <= 5)
		sort_stack_small(a, b, ft_stacklen(*a));
	else
		sort_stack_big(a, b, ft_stacklen(*a));
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_avs;

	a = NULL;
	b = NULL;
	if (ac <= 1 || (ac == 2 && !av[1][0]) || (ac == 2
	&& (av[1][0] == ' ' && av[1][1] == '\0')))
		return (EXIT_FAILURE);
	else if (ac == 2)
	{
		split_avs = ft_split(av[1], ' ');
		if (!split_avs)
			return (EXIT_FAILURE);
		av = split_avs;
	}
	if (check_av_input(ac, av) == NULL)
		return (EXIT_FAILURE);
	avs_to_stack_a(&a, ac, av, &clear);
	if (!is_stack_to_sort(a))
		start_sort(&a, &b);
	print_result(a);
	clear_both_stacks(&a, &b);
	if (ac == 2)
		free_strs(av);
	return (EXIT_SUCCESS);
}
/*
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_avs;

	a = NULL;
	b = NULL;
	if (ac <= 1 || (ac == 2 && !av[1][0]) || (ac == 2 && \
(av[1][0] == ' ' && av[1][1] == '\0')))
	 	return (EXIT_FAILURE);
	// if (ac <= 1 || (ac == 2 && !av[1][0]))
	// else if (ac == 2 && (av[1][0] == ' ' && av[1][1] == '\0'))
	// 	return (EXIT_FAILURE);
	else if (ac == 2)
	{
		split_avs = ft_split(av[1], ' ');
		if (!split_avs)
			return (EXIT_FAILURE);
		av = split_avs;
	}
	if (check_av_input(ac, av) == NULL)
		return (EXIT_FAILURE);
	avs_to_stack_a(&a, ac, av, &clear);
	if (!is_stack_to_sort(a))
		start_sort(&a, &b);
	// {
	// 	if (ft_stacklen(a) <= 5)
	// 		sort_stack_small(&a, &b, ft_stacklen(a));
	// 	else
	// 		sort_stack_big(&a, &b, ft_stacklen(a));
	// }
	clear_both_stacks(&a, &b);
	if (ac == 2)
		free_strs(av);
	return (EXIT_SUCCESS);
}
*/
