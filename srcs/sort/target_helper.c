/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:55:45 by yilin             #+#    #+#             */
/*   Updated: 2024/07/23 16:48:59 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*get target_pos*/
int	get_pos(t_stack *node, int target)
{
	int	target_pos;

	target_pos = 0;
	while (node && node->content != target)
	{
		target_pos++;
		node = node->next;
	}
	return (target_pos);
}

/*bigger*/
int	ft_bigger(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

/*smaller*/
int	ft_smaller(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

/*is_stack_to_rotate*/
/*
- Check if the current element's value is the target
- Compare the number of elements before the target (i)
- elements after the target in the list (ft_lstsize(lst) - i)
- If it's more efficient to reverse rotate, return 0
- Otherwise, return 1 indicating rotation is better
*/
bool	is_stack_to_rotate(t_stack *node, int target_content)
{
	int		i;
	t_stack	*tmp_node;

	i = 0;
	tmp_node = node;
	while (tmp_node)
	{
		if (get_content(tmp_node) == target_content)
			break ;
		i++;
		tmp_node = tmp_node->next;
	}
	if (i > (ft_stacklen(node) - i))
		return (TRUE);
	return (FALSE);
}
