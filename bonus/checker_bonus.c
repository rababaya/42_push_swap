/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:12:52 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/22 16:27:15 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

static int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static int	operation_check(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (!(ft_strncmp(op, "ra\n", 3)))
		return (rotate(stack_a), 1);
	else if (!(ft_strncmp(op, "rb\n", 3)))
		return (rotate(stack_b), 1);
	else if (!(ft_strncmp(op, "rr\n", 3)))
		return (rr(stack_a, stack_b), 1);
	else if (!(ft_strncmp(op, "sa\n", 3)))
		return (swap(stack_a), 1);
	else if (!(ft_strncmp(op, "sb\n", 3)))
		return (swap(stack_b), 1);
	else if (!(ft_strncmp(op, "ss\n", 3)))
		return (ss(stack_a, stack_b), 1);
	else if (!(ft_strncmp(op, "rra\n", 4)))
		return (r_rotate(stack_a), 1);
	else if (!(ft_strncmp(op, "rrb\n", 4)))
		return (r_rotate(stack_b), 1);
	else if (!(ft_strncmp(op, "rrr\n", 4)))
		return (rrr(stack_a, stack_b), 1);
	else if (!(ft_strncmp(op, "pa\n", 3)))
		return (push(stack_b, stack_a), 1);
	else if (!(ft_strncmp(op, "pb\n", 3)))
		return (push(stack_a, stack_b), 1);
	else
		return (0);
}

static int	reading(t_stack	**stack_a, t_stack	**stack_b)
{
	char	*str;

	*stack_b = NULL;
	while (1)
	{
		str = get_next_line(0);
		if (!str)
		{
			if (!(*stack_b))
				return (1);
			return (ft_putstr_fd("KO\n", 1), 0);
		}
		if (!(operation_check(str, stack_a, stack_b)))
			return (ft_putstr_fd("Error\n", 1), free(str), 0);
		free (str);
	}
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
		return (ft_putstr_fd("Error\n", 2), 1);
	len = arr_len(args);
	unsorted = validation(args, len);
	if (!unsorted)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (if_sorted(unsorted, len))
		return (ft_printf("OK\n"), free(unsorted), 0);
	stack_a = stack_filling(unsorted, len);
	if (!(reading(&stack_a, &stack_b)))
		return (ft_stackclear(&stack_a), ft_stackclear(&stack_b), 1);
	if (!(if_sorted_stack(&stack_a)))
		return (ft_printf("KO\n", 0));
	return (ft_printf("OK\n"), 0);
}
