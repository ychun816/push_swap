/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:06:53 by yilin             #+#    #+#             */
/*   Updated: 2024/07/19 17:43:54 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*lst_push: */
static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp_node;

	if (!(*src))
		return ;
	tmp_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp_node->prev = NULL;
	if (!(*dest))
	{
		*dest = tmp_node;
		tmp_node->next = NULL;
	}
	else
	{
		tmp_node->next = *dest;
		(tmp_node->next)->prev = tmp_node;
		*dest = tmp_node;
	}
}

/*pa: push */
void	pa(t_stack **a, t_stack **b)
{
	if (!(*b))
		return ;
	push(b, a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

/*pb: */
void	pb(t_stack **a, t_stack **b)
{
	if (!(*a))
		return ;
	push(a, b);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}
