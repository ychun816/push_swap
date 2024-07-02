/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:07:04 by yilin             #+#    #+#             */
/*   Updated: 2024/06/29 20:58:48 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa
void	sa(t_stack **a)
{
	t_stack tmp_content;
	
	if (!a || !(*a) || !(*a)->next)
		return ;
	// Store the content of the first node
	tmp_content = (*a)->content;
	// Swap the data of the first node with the second node
	(*a)->content = ((*a)->next)->content;
	// Complete the swap
	((*a)->next)->content = tmp_content;
	write(1, "sa\n", 3);
}

//sb
void	sb(t_stack **b)
{
	t_stack	tmp_content;

	if (!b || !(*b) || !(*b)->next)
		return ;
	tmp_content = (*b)->content;
	(*b)->content = ((*b)->next)->content;
	((*b)->next)->content = tmp_content;
	write(1, "sb\n", 3);
}

//ss
void	ss(t_stack **a, t_stack **b)
{
	t_stack	tmp_content1;
	t_stack	tmp_content_2;

	if (!a || !(*a) || !(*a)->next)
		return ;
	tmp_content1 = (*a)->content;
	(*a)->content = ((*a)->next)->content;
	((*a)->next)->content = tmp_content1;
	if (!b || !(*b) || !(*b)->next)
		return ;
	tmp_content2 = (*b)->content;
	(*b)->content = ((*b)->next)->content;
	((*b)->next)->content = tmp_content2;
	write(1, "ss\n", 3);
}