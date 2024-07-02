/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:03:22 by yilin             #+#    #+#             */
/*   Updated: 2024/07/01 16:57:25 by yilin            ###   ########.fr       */
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
	int	content;
	int	position_index;
	int	push_cost;
	bool	above_median; /*median 中位数*/
	bool	cheapest;
	struct	s_stack *prev;
	struct	s_stack	*next;
	struct	s_stack	*target_node;
}	t_stack;

/* ===(B) double linked list for value(same in libft)===
typedef struct s_list
{
	int	content;
	struct s_list *next;
	struct s_list *prev; //double linked list
} t_list
*/

/****** FUNCTION PROTOTYPE *******/
/************ COMMANDS ***********/
//push

//swap

//rotate

//rrotate

/************ SORTING ***********/

#endif

/*********************************/
/************ PENDING ***********/
//check error

//stack initiation

//node initiation

////operation////
//operation (commands)

//algorithm

//stack tools
/************ PENDING ***********/
/*********************************/