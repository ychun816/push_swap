/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:48:00 by yilin             #+#    #+#             */
/*   Updated: 2024/07/13 20:45:21 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include <stdlib.h>*/

static void	ft_free_strs(char **strs, int count)
{
	int	i;

	i = 0;
	if (!strs)
		return;
	while (i < count)
	{
		free((char *)strs[i]);
		i++;
	}
	free((char **)strs);
}

static int	ft_wordcount(char const *str, char c)
{
	int	wordlen;
	int	in_word;

	wordlen = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			wordlen++;
		}
		else if (*str == c)
		{
			in_word = 0;
		}
		str++;
	}
	return (wordlen);
}

static char	*ft_stralloc(char const *str, char c, int *end_pos)
{
	char	*total_word;
	int		start_pos;
	int		i;

	i = 0;
	start_pos = *end_pos;
	while (str[start_pos] && str[start_pos] == c)
		start_pos++;
	while (str[start_pos + i] && str[start_pos + i] != c)
		i++;
	total_word = (char *)malloc((i + 1) * sizeof(char));
	if (!total_word)
		return (NULL);
	i = 0;
	while (str[start_pos] && str[start_pos] != c)
	{
		total_word[i++] = str[start_pos++];
	}
	total_word[i] = '\0';
	*end_pos = start_pos;
	return (total_word);
}

char	**ft_split(char const *s, char c)
{
	char	**sub_strs;
	int		i;
	int		pos;
	int		wordlen;

	i = 0;
	pos = 0;
	wordlen = ft_wordcount(s, c);
	sub_strs = (char **)malloc((wordlen + 1) * sizeof(char *));
	if (!sub_strs)
		return (NULL);
	while (i < wordlen)
	{
		sub_strs[i] = ft_stralloc(s, c, &pos);
		if (!sub_strs[i])
		{
			ft_free_strs(sub_strs, i);
			return (NULL);
		}
		i++;
	}
	sub_strs[i] = NULL;
	return (sub_strs);
}
/*
#include <stdio.h>
int	main(int ac, char *av[])
{
	char **result;
	int	i;

	(void)ac;
	result = ft_split(av[1], av[2][0]);
	i = 0;
	while (i < ac)
	{
		printf("|| %s ||\n", result[i]);
		i++;
	}
	free(result);
	return (0);
}

#include <stdio.h>
int	main(void)
{
    char **result;
    char *test_string = "This~is~a~test~string";
    char delimiter = '~';
    int i;

    // Call your ft_split function
    result = ft_split(test_string, delimiter);

    // Check if the result is NULL (allocation failed or other error)
    if (!result)
    {
        printf("Error: ft_split returned NULL\n");
        return (1);
    }

    // Print each string in the result array
    for (i = 0; result[i] != NULL; i++)
    {
        printf("Substring %d: %s\n", i, result[i]);
    }

    // Free the allocated memory
    ft_free_strs(result, i); // Assuming ft_free_strs is corrected as suggested

    return (0);
}
*/
