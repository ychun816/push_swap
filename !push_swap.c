/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   !push_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:27:33 by yilin             #+#    #+#             */
/*   Updated: 2024/07/02 18:56:27 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

/*
** Function: parse_stack_argv => parse_n_check
** ---------------------------
** Ensures that the stack 'a' does not contain duplicate elements.
** If duplicates are found, the function frees the stack and exits the program.
**
** Parameters:
** - a: Pointer to the stack 'a' to be parsed and validated.
**
** Returns: None
*/
void	parse_n_check(t_stack *a)
{
	// Pointer to traverse the stack
	t_stack	*check_index;
	
	// Exit if stack 'a' is empty
	if (!a) //a ==NULL
		exit_program(NULL,"stack empty");
	// Iterate through each node in the stack
	while (a)
	{
		//initialize current_pos to the next node after a => compare the data in the a node with the data in all subsequent nodes
		check_index = a->next;
		// Compare 'a' with all subsequent nodes 'current'
		while (check_index)
		{
			// If duplicate elements are found, exit the program => free stack a +exit program(error message)
			if (check_index->content == a->content) //a != current
			{
				free_stack(&a);
				exit_program(NULL, "find duplicate elements");
			}
			check_index = check_index->next; //loop current_pos
		}
		a = a->next; //loop stack a
	}
}

/*
** Function: create_stack_two_args => init_stack_2args
** -------------------------------
** Creates and populates a stack 'a' from arguments in 'converted_argv'.
** Validates each argument to ensure they are valid integers.!
**
** Parameters:
** - converted_argv: Array of strings containing arguments to be converted into stack elements.
** - a: Pointer to the stack 'a' to be populated.
**
** Returns:
** Pointer to the populated stack 'a'.
*/
t_stack	*init_stack_2args(int ac, char *allocated_av[], t_stack *a)
{
	int	i; // Index to count arguments in 'av' "av[i][j]""
 	int	j; // Index for characters within each argument (av)
	int	check_range; //flag => check if argument outa range
	
	i = 0;
	check_range = 1;
	
	// Iterate through each argument in 'av'
	while (allocated_av[i][j])
	{
		j = 0;
		//CHECK IF VALID//
		// Check each character in the argument
		while (allocated_av[i][j])
		{
			// Skip sign characters '+' or '-'
			if (allocated_av[i][j] == '+' || allocated_av[i][j] == '-')
				j++;
			// Check if character is not a digit => if not => exit program
			if (!ft_isdigit(allocated_av[i][j]))
			{
				check_range = 0; // Set check_range to 0 for invalid character
				exit_program(NULL, "argument input not integer");
			}
			else
				// Validate and handle arguments that represent a range
				a = is_arg_in_range(i, check_range, a, allocated_av); ////
				// if all digit => loop all the character til the end of av
				while (ft_isdigit(allocated_av[i][j]))
					j++;
		}
		i++;
	}
	return (a);
}

/*
** Function: control_two_args => ALLOCATE when ONE ARGUMENT(2av)
** ---------------------------
** Controls the creation of stack 'a' from a single argument 'argv'.
** Splits 'argv' into multiple arguments and calls 'create_stack_two_args' to populate 'a'.
**
** Parameters:
** - argv: Single string argument containing numbers separated by spaces.
** - a: Pointer to the stack 'a' to be populated.
**
** Returns:
** Pointer to the populated stack 'a'.
*/
t_stack	*allocate_av_2args(char	*av, t_stack *a)
{
	char	**allocated_av; // Array to store split arguments

	// Split 'argv' into multiple arguments
	allocated_av = ft_split(av, ' ');
	// Populate stack 'a' with split arguments
	a = init_stack_2args(allocated_av, a);
	// Free memory allocated for 'converted_argv'
	free_array(allocated_av);
	//return populated a
	return (a);
}

/*
** Function: create_stack_argv => AV TO STACK
** ---------------------------
** Creates and initializes stack 'a' based on command-line arguments 'argc' and 'argv'.
** Validates each argument and ensures stack 'a' does not contain duplicate elements.
**
** Parameters:
** - argc: Number of command-line arguments.
** - argv: Array of strings containing command-line arguments.
** - a: Pointer to the stack 'a' to be created and initialized.
**
** Returns:
** Pointer to the initialized stack 'a'.
*/
t_stack	avs_to_stack(int ac, char *avs[], t_stack *a)
{
	int	i; // Index for iterating through command-line arguments
	int	converted_int; // Converted integer from command-line argument
	int	check_range; // Flag to indicate if integer argument is out of range

	check_range = 1;
	
	 // If only single argument
	 if (ac == 2)
	 	a = allocate_av_2args(avs[1], a);
	 // If more than one argument
	 else
	 {
		i = 1;
		// Iterate through each command-line argument 'argv[i]'
		while (avs[i])
		{
			// Exit if argument contains characters =>exit program
			if (avs[i][0] >= 'a' && avs[i][0] >= 'z')
				exit_program(NULL, "char in args");
			// Convert argument to integer and validate check_range
			converted_int = ft_atol(avs[i], &check_range);
			// Exit if integer argument is out of check_range
			if (check_range == 2)
				exit_program(NULL, "out of check_range");
			i++;
		}
		// Add converted integer to stack 'a'
		ft_stackadd_back(&a, converted_int); //addstack
		i++;
	 }
	 // Validate stack 'a' to ensure it does not contain duplicate elements
	 parse_n_check(a);
	 return (a);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int	stack_len;

	a = NULL;
	b = NULL;
	/*check input*/
	if (ac == 1 || ac == 2 && !av[1][0])
		exit_program(av, "wrong!"); /*or exit(EXIT_FAILURE)? //exit program => put error*/
	// else if (ac == 2)
	// 	av = ft_split(av[1], ' ');
	/*create stack a*/
	a = av_to_stack(ac, av, a); ///
	//check if stack a in order => no need sort => free
	if (!is_stack_sorted(a))
	{
		free_stack(a);
		exit(EXIT_FAILURE);
	} 
	stack_len = ft_stacklen(a);
	if (stack_len == 2)
		sa(&a);
	if (stack_len == 3)
		sort_three_small(stack_len, &a);
	else
		sort_big(stack_len, &a, &b);
	free_stack(&a);
	// Exit the program with a status of 1 (successful completion)
	return (0);
}