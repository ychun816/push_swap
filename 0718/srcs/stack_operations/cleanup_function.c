/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:37:27 by yilin             #+#    #+#             */
/*   Updated: 2024/07/18 17:11:18 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*clear content*/
void	clear_content(void *content)
{
	free(content);
}

/*clear stack*/
void	clear_stack(t_stack **stack, void (*clear_content)(void *))
{
	t_stack *tmp_node; // Temporary pointer to hold the current node.
	
	while (*stack)    // Loop through the entire stack
    {
        tmp_node = *stack;// Save the current node in `tmp`.
		*stack = (*stack)->next;
		if (*stack)//if the next node exits
		{
			(*stack)->prev = NULL; // set the next node's previous pointer to NULL
		}
		clear_content(tmp_node);// delete the current node
	}
}

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	if (!lst || !del || !(*lst))
// 		return ;
// 	ft_lstclear(&(*lst)->next, del);
// 	(del)((*lst)->content);
// 	free(*lst);
// 	*lst = NULL;
// }

/*clear both stacks*/
void	clear_both_stacks(t_stack **a, t_stack **b)
{
	clear_stack(a, &clear_content);
	clear_stack(b, &clear_content);
}

/*free strs(frm split)*/
void	free_strs(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}
