/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:07:04 by yilin             #+#    #+#             */
/*   Updated: 2024/07/19 17:55:14 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*swap*/
static void	swap(t_stack **stack)
{
	t_stack	*new_head;

	if (!(*stack) || !(*stack)->next)
		return ;
	new_head = (*stack)->next;
	(*stack)->next = new_head->next;
	new_head->prev = (*stack)->prev;
	new_head->next = *stack;
	(*stack)->prev = new_head;
	if (new_head->next)
		(new_head->next)->prev = *stack;
	*stack = new_head;
}

/*sa*/
void	sa(t_stack **a)
{
	if (!(*a) ||!(*a)->next)
		return ;
	swap(a);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

/*sb*/
void	sb(t_stack **b)
{
	if (!(*b) ||!(*b)->next)
		return ;
	swap(b);
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

/*ss*/
void	ss(t_stack **a, t_stack **b)
{
	if (!(*a) || !(*a)->next)
		return ;
	if (!(*b) || !(*b)->next)
		return ;
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}
