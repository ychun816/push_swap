/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:42:38 by yilin             #+#    #+#             */
/*   Updated: 2024/07/04 17:19:38 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"
/*
/*char to long int
int	ft_atol(const char *str, int *range)
{
	int	i;
	long	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;  //Assume valid input initially
	range = 1; 
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str == '-')
			sign = sign * (-1);	
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		*range = 2;
	while (str[i] >= '0' && str[i] >= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (nb > INT_MAX || nb < INT_MIN)
		*range = 2;
	return (nb * sign);
}*/

/*ft_stacklen*/
int	ft_stacklen(t_stack **stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;	
	}
	return (len);
}

/* ft_stack_last : get_last_stack*/
/*
stack structure:
head -> [data | next] -> [data | next] -> [data | NULL]
*/
t_stack	ft_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/*ft_stack_new : create new node*/
t_stack	ft_stack_new(int content) //initiate stack
{
	t_stack	*new_node;
	
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

/*create new stack*/
/*
head -> [A] -> [B] -> [C] -> NULL
 [New] -> [A] -> [B] -> [C] -> NULL
*/
void	ft_stackadd_front(t_stack **stack, t_stack *new_head)
{
	if (!*stack || !new_head)
		return ;
	new_head->next = *stack;
	*stack = new_head;
}

/*ft_stackadd_back*/
/*
head -> [A] -> [B] -> [C] -> NULL
head -> [A] -> [B] -> [C] -> [last] NULL

*stack (before):

| data: 10   | next | --> NULL
| next: NULL | prev |
| prev: NULL |      |

node (new node):

| data: 20   |
| next: NULL |
| prev: *stack (points to previous node with data 10) |

*stack (after):

| data: 10   | next | --> node
| next: node | prev |
| prev: NULL |      |
///////////////////////////////
*stack (before):
---------------------
| data: 10   | next | --> node
| next: node | prev |
| prev: NULL |      |
---------------------

node (before):
--------------
| data: 20   |
| next: NULL |
| prev: *stack (points to node with data 10) |
--------------

new node:
--------------
| data: 30   |
| next: NULL |
| prev: node (points to node with data 20) |
--------------

*stack (after):
---------------------
| data: 10   | next | --> node
| next: node | prev |
| prev: NULL |      |
---------------------

node (after):
--------------
| data: 20   |
| next: new node |
| prev: *stack (points to node with data 10) |
--------------

new node:
--------------
| data: 30   |
| next: NULL |
| prev: node (points to node with data 20) |
--------------
 */ 
void	ft_stackadd_back(t_stack **stack, int content) TODO:
{
	t_stack *current;
	t_stack *new_last;

	if (!stack)
		return ;
	new_last = malloc(sizeof(t_stack));
	if (!new_last)
		return ;
	// Set the next pointer of the new node to NULL
	// Assign the provided data to the new node's data field
	new_last->next = NULL;
	new_last->content;
	//// Check if the stack pointer points to NULL (empty stack)
	if (!(*stack))
	{
		// If empty, make the stack pointer point to the new node
		*stack = new_last;
		//prev node point to NULL
		new_last->prev = NULL;
	}
	else
	{
		// If the stack not empty => initialize 'last'-> point to the start of the stack
		current = *stack;
		// Traverse the stack until the last node (where next is NULL) is found
		while(current->next != NULL)
		{
			current->next = new_last;
			new_last->prev = current;
			current = current->next;
		}
	}
}

//ft_stackremove_one(t_stack **stack, int num);

//ft_stackremove_last_one(t_stack **stack);

//ft_stackremove_first_one(t_stack **stack);
