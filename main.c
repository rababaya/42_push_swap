/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:51:37 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/22 15:08:44 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_all(int len, t_stack **stack_a, t_stack **stack_b)
{
	if (len == 2)
		swap(stack_a, 'a');
	else if (len == 3)
		sort_for_3(stack_a);
	else if (len == 4)
		sort_for_4(stack_a, stack_b);
	else if (len == 5)
		sort_for_5(stack_a, stack_b);
	else
		sorting(stack_a, stack_b);
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
	int		len;
	int		*unsorted;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	len = 0;
	args = join_split(&argv[1], argc);
	if (!args)
		return (1);
	len = arr_len(args);
	unsorted = validation(args, len);
	if (!unsorted)
		return (1);
	if (if_sorted(unsorted, len))
		return (free(unsorted), 0);
	stack_a = stack_filling(unsorted, len);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	sort_all(len, &stack_a, &stack_b);
	ft_stackclear(&stack_a);
	return (0);
}
