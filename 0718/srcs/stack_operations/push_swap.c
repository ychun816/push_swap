/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:39:11 by yilin             #+#    #+#             */
/*   Updated: 2024/07/18 18:07:20 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int	a_len;
	char	**split_avs;

	a = NULL;
	b = NULL;
	/*check input*/
	if (ac <= 1 || (ac == 2 && !av[1][0]))
	{
		// if(ac == 2)
		// 	ft_putstr_fd("Error\n", STDERR_FILENO);
		return (EXIT_SUCCESS);
	}
	else if (ac == 2 && (av[1][0] == ' ' && av[1][1] == '\0'))
		return (EXIT_SUCCESS);
	else if (ac == 2)
	{
		split_avs = ft_split(av[1], ' ');
		if (!split_avs)
			return (EXIT_SUCCESS);
		av = split_avs;
	}
	check_av_input(ac, av);
	avs_to_stack_a(&a, ac, av, &clear_content);
	a_len = ft_stacklen(a); 
	if (!is_stack_to_sort(a))/*check if stack a in order => no need sort => free*/
	{
		if (a_len <= 5)
			sort_stack_small(&a, &b, a_len);
		else
			sort_stack_big(&a, &b, a_len);
	}
	clear_both_stacks(&a, &b);
	if (ac == 2)
   		free_strs(av);
	return (EXIT_SUCCESS);
}

// OG===============
// int	main(int ac, char **av)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	int	a_len;

// 	a = NULL;
// 	b = NULL;
// 	/*check input*/
// 	if (ac <= 1 || (ac == 2 && !av[1][0]))
// 	{
// 		if(ac == 2)
// 			ft_putstr_fd("Error\n", STDERR_FILENO);
// 		return (EXIT_SUCCESS);
// 	}
// 	else if (ac == 2)
// 	{
// 		av = ft_split(av[1], ' ');
// 	}
// 	check_av_input(ac, av);
// 	avs_to_stack_a(&a, ac, av, &clear_content);
// 	a_len = ft_stacklen(a); 
// 	if (!is_stack_sorted(a))/*check if stack a in order => no need sort => free*/
// 	{
// 		if (a_len <= 5)
// 			sort_stack_small(&a, &b, a_len);
// 		else
// 			sort_stack_big(&a, &b, a_len);
// 	}
// 	clear_both_stacks(&a, &b);
// 	if (ac == 2)
//    		free_strs(av);
// 	return (EXIT_SUCCESS);
// }