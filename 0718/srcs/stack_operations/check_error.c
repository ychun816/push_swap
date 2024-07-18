/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:45:48 by yilin             #+#    #+#             */
/*   Updated: 2024/07/18 17:49:32 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*check_av_input: (1)check value, (2)check dup*/
static int	is_value_error(int ac, char **av)
{
	int		i;
	int		nb;
	char	*converted_str;

	i = 0;
	if (ac != 2)
		i++;
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		converted_str = ft_itoa(nb);
		if (((nb == 0) && (ft_strcmp(av[i], "0") != 0)) || (ft_strcmp(converted_str, av[i]) != 0))
		{
			free(converted_str);
			return (-1);
		}
		free(converted_str);
		i++;
	}
	return (i);
}

/***check_av_input: (2)is duplicate error***/
static int	is_duplicate_error(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac != 2)
		i++;
	while (av[i])
	{
		j = i + 1;
		while (av[j]) 
		{
			if (!ft_strcmp(av[i], av[j++]))
				return (-1);
		}
		i++;
	}
	return (i);
}
/***check_av_input***/
void	check_av_input(int ac, char **av)
{
	if (is_value_error(ac, av) < 0 || is_duplicate_error(ac, av) < 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		if (ac == 2)
			free_strs(av);
		exit(EXIT_SUCCESS);
	}
}

/***is stack sorted***/
// int	is_stack_to_sort(t_stack *node)
// {
// 	int	ref;

// 	ref = get_content(node);
// 	while (node->next)
// 	{
// 		if (get_content(node->next) < ref)
// 			return (0);
// 		ref = get_content(node->next);
// 		node = node->next;
// 	}
// 	return (1);
// }
bool	is_stack_to_sort(t_stack *node)
{
	int	ref_content;

	// if (!node)
	// 	return (TRUE);
	ref_content = get_content(node);
	while (node->next)
	{
		if (get_content(node->next) < ref_content)//traverse the stack,compare the content of the next node with ref_content
			return (TRUE);// return (0) List is not sorted
		ref_content = get_content(node->next);
		node = node->next;
	}
	return (FALSE);// return (1) List is sorted
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
		return (TRUE);// If it's more efficient to reverse rotate, return 0
	return (FALSE);//Otherwise, return 1 indicating rotation is better
}