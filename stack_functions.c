/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:42:38 by yilin             #+#    #+#             */
/*   Updated: 2024/07/02 19:37:16 by yilin            ###   ########.fr       */
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
	/*Assume valid input initially*/
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
}

//stackadd back (node)
void	ft_stackadd_back(t_stack *node, int nb)
{

}


//ft_stacklen
int	ft_stacklen(t_stack **stack)
{
	
}
