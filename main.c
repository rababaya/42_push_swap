/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:51:37 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/19 17:20:41 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*bubble_sort(int *sorting, int length)
{
	int	i;
	int	temp;

	i = 0;
	while (i < length - 1)
	{
		if (sorting[i] > sorting[i + 1])
		{
			temp = sorting[i];
			sorting[i] = sorting[i + 1];
			sorting[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (sorting);
}

static int	if_sorted(int *arr, int size)
{
	int	i;

	if (size == 1)
		return (1);
	i = 0;
	while (i < size - 1)
	{
		if (arr[i + 1] < arr[i])
			return (0);
		i++;
	}
	return (1);
}

static int	*arr_dup(int *arr, int len)
{
	int	i;
	int	*dest;

	i = 0;
	dest = malloc(len * sizeof(int));
	while (i < len)
	{
		dest[i] = arr[i];
		i++;
	}
	return (dest);
}

static int	arr_len(char	**arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	char	**args;
	int		*sorted;
	int		len;
	int		*unsorted;
	t_stack	*stack_a;
	t_stack	*stack_b;

	len = 0;
	args = join_split(&argv[1], argc);
	if (!args)
		return (1);
	len = arr_len(args);
	unsorted = validation(args, len);
	sorted = arr_dup(unsorted, len);
	if (!unsorted || !sorted)
		return (1);
	if (if_sorted(unsorted, len))
		return (free(unsorted), free(sorted), 0);
	sorted = bubble_sort(sorted, len);
	stack_a = stack_filling(unsorted, sorted, len);
	if (!stack_a)
		return (free(unsorted), free(sorted), 1);
	stack_b = NULL;
	sort_all(len, &stack_a, &stack_b);
	free_all(unsorted, sorted, &stack_a, &stack_b);
}
