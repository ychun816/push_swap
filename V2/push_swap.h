/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:03:22 by yilin             #+#    #+#             */
/*   Updated: 2024/07/04 17:31:24 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

/************ STRUCTURE ***********/
typedef struct s_stack
{
	int	content;  //The number to sort
	int	position_index; //The number's position in the stack
	int	push_cost; //How many commands in total
	bool	above_median; /*median 中位数*/ //Used to calculate `push_cost`
	bool	cheapest; //The node that is the cheapest to do commands
	struct	s_stack *prev;
	struct	s_stack	*next;
	struct	s_stack	*target_node;
}	t_stack;

/************ FUNCTIONS ***********/

/*basic commands*/




/*handle error*/

/*stack init*/
/*stack functions*/

/*algo*/
sort_three
sort_big



#endif
