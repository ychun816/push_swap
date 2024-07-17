/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:45:48 by yilin             #+#    #+#             */
/*   Updated: 2024/07/17 19:56:32 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*check_av_input: (1)check value, (2)check dup*/
/***(1) is value error***/
static bool	is_value_error(int ac, char **av)
{
	int	i;
	int	nb;
	char *converted_str;
	
	i = 0;
	if (ac != 2)
		i++;// Skip the first argument if not exactly 2 arguments
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		converted_str = ft_itoa(nb);
		// Check if the original string is valid
		// `(!nbr && ft_strcmp(av[i], "0"))` handles the special case of "0"
		// `ft_strcmp(tmp, av[i])` ensures the conversion was exact
		if ((nb == 0 && ft_strcmp(av[i], "0") != 0) || ft_strcmp(converted_str, av[i]) != 0)
		{
			free(converted_str);
			return (TRUE);
		}
		free(converted_str);
		i++;
	}
	return (FALSE);
}
/***(2)is duplicate error***/
static bool	is_duplicate_error(int ac, char **av)
{
	int	i;
	int	j;
	
	i = 0;
	if (ac != 2)
		i++;// Skip the first argument if not exactly 2 arguments
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (!ft_strcmp(av[i], av[j]))
				return (TRUE);// Duplicate found
			j++;
		}
		i++;
	}
	return (FALSE);//returns "true" if duplicates are found/ no duplicate =>false
}
/*check_av_input*/
void	check_av_input(int ac, char** av)
{
	if (is_value_error(ac, av) || is_duplicate_error(ac, av))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		if (ac == 2)
			free_strs(av);
	}
	exit(EXIT_SUCCESS);
}

/***is stack sorted***/
bool	is_stack_sorted(t_stack *node)
{
	int	ref_content;

	if (!node)
		return (TRUE);
	ref_content = get_content(node);
	while (node->next)
	{
		if (get_content(node->next) < ref_content)//traverse the stack,compare the content of the next node with ref_content
			return (FALSE);// List is not sorted
		ref_content = get_content(node->next);
		node = node->next;
	}
	return (TRUE);// List is sorted
}
/*is stack rotated*/
bool	is_stack_to_rotate(t_stack *node, int target_content)
{
	t_stack	*tmp_node;
	int	i;
	
	i = 0;
	tmp_node = node;
	while (tmp_node)
	{
		// Check if the current element's value is the target
		if (get_content(tmp_node) == target_content)
			break ;
		i++;
		tmp_node = tmp_node->next;
	}
	// Compare the number of elements before the target (i)
    // elements after the target in the list (ft_lstsize(lst) - i)
	if (i > (ft_stacklen(node) - i))
		return (FALSE);// If it's more efficient to reverse rotate, return 0
	return (TRUE);//Otherwise, return 1 indicating rotation is better
}