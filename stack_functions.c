/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:42:38 by yilin             #+#    #+#             */
/*   Updated: 2024/07/03 18:19:04 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"
#include <limits.h> //for INT MAX+INT MIN

// char to long int
int	ft_atol(const char *str, int *range)
{
	int	i;
	long	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	range = 1; /*Assume valid input initially*/

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
}

//ft_stacklen
int	ft_stacklen(t_stack **stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;	
	}
	return (i);
}

void	ft_stackadd_back(t_stack **stack, int nb)
{
	t_stack *tmp;

	if (!node)
		return ;
	if (!)
	

}
/*ref
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
*/
void	free_stack(t_stack **stack)
{
	t_stack	*index;
	t_stack	*tmp;

	if (!stack)
		return ;
	index = *stack; /*initialize index*/
	while (index)
	{
		tmp = index->content;
		index->content = 0; /*Clear data to protect sensitive information*/
		free(tmp);
		index = index->next; /*loop*/
	}
	*stack = NULL;
}