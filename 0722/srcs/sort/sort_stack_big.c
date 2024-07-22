/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:56:23 by yilin             #+#    #+#             */
/*   Updated: 2024/07/22 19:42:08 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		set_cheapest_a2b(a, (a_len - b_len), b, b_len);
		pb(a, b);
		b_len++;
	}
	sort_stack_3nodes(a);
	while (b_len > 0)
	{
		set_cheapest_b2a(b, b_len, a, (a_len - b_len));
		pa(a, b);
		b_len--;
	}
	sort_stack_a(a);
}
