/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:07:01 by yilin             #+#    #+#             */
/*   Updated: 2024/07/05 10:56:27 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

/*
(1)Get last_node

Head                  last_node => get_last_node(**stack)
 ↓                       ↓
[A] <-> [B] <-> [C] <-> [D]

----------------------------
(2)Detach last_node:

Head
 ↓
[A] <-> [B] <-> [C]    [D] => deatch last_node => (last_node->prev)->next = NULL;

----------------------------
(3)Link last_node to front:

               (*stack)
NULL <-> [D] <-> [A] <-> [B] <-> [C] <-> NULL

----------------------------
(4)Update:

Head
 ↓
[D] <-> [A] <-> [B] <-> [C]

*/

void	rrotate(t_stack **stack)
{
	t_stack *last_node;

	if (!(*stack) ||!(*stack)->next)
		return ;
	last_node = get_last_node(*stack);
	//Detaching the Last Node
	(last_node->prev)->next = NULL;
	//Link last_node to front
	last_node->next = *stack;
	last_node->prev = NULL;
	//update *stack to point to the new node; otherwise it points to old node
	*stack = last_node;
	//update prev pointer; otherwise it still points to NULL => break the link
	(last_node->next)->prev = last_node;
}

//rra: last node become first
void	rra(t_stack **a) TODO: //if to add boolean?
{
	rrotate(a);
	ft_printf("rra\n");
}

//rrb: last node become first
void	rrb(t_stack **b) TODO: //if to add boolean?
{
	rrotate(b);
	ft_printf("rrb\n");
}

//rrr: rra and rrb at the same time
void	rrr(t_stack **stack) TODO: //if to add boolean?
{
	rrotate(a);
	rrotate(b);
	ft_printf("rrr\n");
}