/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:03:22 by yilin             #+#    #+#             */
/*   Updated: 2024/06/27 13:52:00 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h" 
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
######### include <stdarg.h>

/************ COMMANDS ********** => single or doubly linked list?*/ //PENDING
/* ===(A) doubly linked list===
typedef struct s_stack
{
	int	data;
	int	current_position;
	int	push_cost;
	bool	above_median;
	bool	cheapest;
	struct	s_stack *prev;
	struct	s_stack	*next;
	struct	s_stack	*target_node;

}	t_stack;
/* ===(B) double linked list for value(same in libft)===*/
typedef struct s_list
{
	void	*content;
	struct s_list *next;
	struct s_list *prev; //double linked list
} t_list

/* ===(B) stack for labeling order===*/


////function prototype////
/************ COMMANDS ***********/
//push

//swap

//rotate

//rrotate

/************ SORTING ***********/



#endif


/************ PENDING ***********/
//check error

//stack initiation

//node initiation

////operation////
//operation (commands)

//algorithm

//stack tools
