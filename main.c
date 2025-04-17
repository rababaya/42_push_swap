/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:51:37 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/17 19:30:29 by rababaya         ###   ########.fr       */
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

t_stack	*stack_filling(int *unsorted, int *sorted, int len)
{
	int		i;
	int		j;
	t_stack	*tmp;
	t_stack	*stack;

	i = 0;
	j = 0;
	stack = NULL;
	while (i < len)
	{
		if (unsorted[i] == sorted[j])
		{
			tmp = ft_stacknew(j);
			if (!tmp)
				return (NULL);
			ft_stackadd_back(&stack, tmp);
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (stack);
}

int	*arr_dup(int *arr, int len)
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

void	sort_all(int len, t_stack *stack_a, t_stack *stack_b)
{
	if (len == 2)
		swap_a(stack_a);
	else if (len == 3)
		sort_for_3(&stack_a);
	else if (len == 4)
		sort_for_4(&stack_a, &stack_b);
	else if (len == 5)
		sort_for_5(&stack_a, &stack_b);
	else
		sorting(&stack_a, &stack_b);
}

int	main(int argc, char **argv)
{
	char	**args;
	int		len;
	int		*sorted;
	int		*unsorted;
	t_stack	*stack_a;
	t_stack	*stack_b;

	len = 0;
	args = join_split(&argv[1], argc);
	if (!args)
		return (1);
	while (args[len])
		len++;
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
	sort_all(len, stack_a, stack_b);
	free(unsorted);
	free(sorted);
}
