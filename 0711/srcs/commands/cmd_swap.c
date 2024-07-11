/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:07:04 by yilin             #+#    #+#             */
/*   Updated: 2024/07/10 20:31:20 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "libft/includes/libft.h"
/*
static void	swap(t_stack **stack)
void	sa(t_stack **a)
void	sb(t_stack **b)
void	ss(t_stack **a, t_stack **b)
*/
/*swap*/
static void	swap(t_stack **stack)
{
	t_stack	*new_head;

	if (!stack || !(*stack)->next)
		return ;	
	new_head = (*stack)->next;
	
	//// Update the pointers to swap the nodes////
	// Old head's next points to the new head's next
	(*stack)->next = new_head->next;
	// New head's prev points to the old head's prev
	new_head->prev = (*stack)->prev;
	// New head's next points to the old head
	new_head->next = *stack;
	// Old head's prev points to the new head
	(*stack)->prev = new_head;
	// If there's a node after the new head, update its prev pointer
	if (new_head->next)
		(new_head->next)->prev = *stack;
	 // Update the head to point to the new head
	*stack = new_head;
}

/*sa*/
void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

/*sb*/
void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

//ss
void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

/*
///sa///
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

///sb///
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

///ss///
void	ss(t_stack **a, t_stack **b)
{
	t_stack	tmp_content1;
	t_stack	tmp_content2;

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
*/