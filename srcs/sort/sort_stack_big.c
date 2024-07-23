/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:56:23 by yilin             #+#    #+#             */
/*   Updated: 2024/07/23 16:20:32 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sort stack a*/
void	sort_stack_a(t_stack **a)
{
	int	min_content;

	min_content = get_min_content(*a);
	while (get_content(*a) != min_content)
	{
		if (is_stack_to_rotate(*a, min_content))
			ra(a, 1);
		else
			rra(a, 1);
	}
}

/*sort stack big*/
void	sort_stack_big(t_stack **a, t_stack **b, int a_len)
{
	int	b_len;

	b_len = 0;
	while (b_len < 2)
	{
		pb(a, b);
		b_len++;
	}
	while (a_len - b_len > 3)
	{
		check_cheap_a2b(a, (a_len - b_len), b, b_len);
		pb(a, b);
		b_len++;
	}
	sort_stack_3nodes(a);
	while (b_len > 0)
	{
		check_cheap_b2a(b, b_len, a, (a_len - b_len));
		pa(a, b);
		b_len--;
	}
	sort_stack_a(a);
}
