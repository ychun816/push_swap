/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:45:48 by yilin             #+#    #+#             */
/*   Updated: 2024/07/23 16:50:26 by yilin            ###   ########.fr       */
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
		if ((!nb && ft_strcmp(av[i], "0")) || (ft_strcmp(converted_str, av[i])))
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
char	**check_av_input(int ac, char **av)
{
	if (is_value_error(ac, av) < 0 || is_duplicate_error(ac, av) < 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		if (ac == 2)
			free_strs(av);
		return (NULL);
	}
	return (av);
}

/*is stack to sort*/
/*
- traverse the stack,compare the content of the next node with ref_content
- return (TRUE / 0) List is not sorted
- return (FALSE / 1) List is sorted
*/
bool	is_stack_to_sort(t_stack *node)
{
	int	ref_content;

	ref_content = get_content(node);
	while (node->next)
	{
		if (get_content(node->next) < ref_content)
			return (TRUE);
		ref_content = get_content(node->next);
		node = node->next;
	}
	return (FALSE);
}
