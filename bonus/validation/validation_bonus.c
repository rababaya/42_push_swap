/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:53:26 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/22 13:51:10 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	free_tab(char ***s)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while ((*s)[count])
		count++;
	while (i < count)
	{
		free((*s)[i]);
		++i;
	}
	free(*s);
	*s = NULL;
}

static void	free_with_message(char ***argv, int **arr, char *message)
{
	ft_putstr_fd(message, 2);
	write(2, "\n", 1);
	free(*arr);
	free_tab(argv);
}

static int	num_check(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (!(ft_isdigit(argv[i])))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static void	validation_helper(char **argv, int **arr, int i)
{
	int	j;

	j = 0;
	(*arr)[i] = ft_atoi(argv[i]);
	if ((*arr)[i] == 0 && !(argv[i][0] == '0' && !argv[i][1]))
	{
		free_with_message(&argv, arr, "Error");
		exit(1);
	}
	while (j < i)
	{
		if ((*arr)[j] == (*arr)[i])
		{
			free_with_message(&argv, arr, "Error");
			exit(1);
		}
		j++;
	}
}

int	*validation(char **argv, int argc)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(argc * sizeof(int));
	if (!arr)
		return (NULL);
	while (argv[i])
	{
		if (!num_check(argv[i]))
		{
			free_with_message(&argv, &arr, "Error");
			exit(1);
		}
		validation_helper(argv, &arr, i);
		i++;
	}
	free_tab(&argv);
	return (arr);
}
