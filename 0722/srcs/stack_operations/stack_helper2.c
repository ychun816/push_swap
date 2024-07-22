/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:44:49 by yilin             #+#    #+#             */
/*   Updated: 2024/07/22 17:34:08 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*for get_cheapest_A2B*/
void	a2b_rb_or_rrb(t_stack **b, int target_pos, int b_len)
{
	if (b_len - target_pos > target_pos)
		rb(b, target_pos);
	else
		rrb(b, b_len - target_pos);
}

/*for get_cheapest_A2B*/
void	a2b_ra_or_rra(t_stack **a, int cheapest_pos, int a_len)
{
	if (a_len - cheapest_pos > cheapest_pos)
		ra(a, cheapest_pos);
	else
		rra(a, a_len - cheapest_pos);
}

/*for get_cheapest_B2A*/
void	b2a_ra_or_rra(t_stack **a, int target_pos, int a_len)
{
	if (a_len - target_pos > target_pos)
		ra(a, target_pos);
	else
		rra(a, a_len - target_pos);
}

/*for get_cheapest_B2A*/
void	b2a_rb_or_rrb(t_stack **b, int cheapest_pos, int b_len)
{
	if (b_len - cheapest_pos > cheapest_pos)
		rb(b, cheapest_pos);
	else
		rrb(b, b_len - cheapest_pos);
}
