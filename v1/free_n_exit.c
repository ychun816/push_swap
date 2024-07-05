/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_n_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:36:55 by yilin             #+#    #+#             */
/*   Updated: 2024/07/05 10:36:56 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

/* put error
int put_error(int fd)
{
	write(fd, "Error\n" 6);
	return (1);
}*/

/*free array*/
void	free_array(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
}

/*free_stack*/
/*
(1) ORIGINAL
Head
 ↓
[ 10 | ] -> [ 20 | ] -> [ 30 | NULL ]
=====================================
(2) LOOP
Head
↓
[ 10 | ] -> [ 20 | ] -> [ 30 | NULL ]
current   tmp

Head
↓
[ 10 | ] -> [ 20 | ] -> [ 30 | NULL ]
                        current   tmp
=====================================
(3) RESULT
Head (NULL)
 ↓
[ 10 | ] -> [ 20 | ] -> [ 30 | NULL ]
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

/*exit program*/
void	exit_program(char	**array, char *error_msg)
{
	(void)error_msg; // Suppress unused parameter warning for error_msg
	/*If `array` is not NULL, free the memory it points to*/
	if (array)
		free(array);
	/*Output "Error" to the file descriptor 2 (stderr) => putstr_fd*/
	/*Output a newline character to the file descriptor 2 (stderr) => putchar_fd*/
	ft_putstr_fd("Error", 2);
	ft_putchar_fd("\n", 2);
	exit(EXIT_FAILURE);
}