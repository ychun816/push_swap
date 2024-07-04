/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:54:55 by yilin             #+#    #+#             */
/*   Updated: 2024/07/04 19:55:28 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

/*is stack sorted*/
bool	is_stack_sorted(t_stack *stack)
{
	t_stack	*current;
	int	current_content;
	int	next_content;

	current = 0;
	if (!stack)
		return (true);
	if (current->next != NULL)
	{
		current_content =current->content;
		next_content = (current->next)->content;
		if (current_content >= next_content)
			return (false);
		current = current->next;	
	}
	return (true);
}