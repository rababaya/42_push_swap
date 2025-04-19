/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:26:32 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/19 17:15:51 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int num)
{
	int	i;

	i = 0;
	while (i <= (num / 2) - 1)
	{
		if (i * i >= num)
		{
			if (i * i - num < num - (i - 1) * (i - 1))
				return (i);
			else
				return (i - 1);
		}
		i++;
	}
	return (0);
}

static int	deviation(int len)
{
	double	dev;

	dev = (1.38 * ft_sqrt(len)) - 0.38;
	return ((int)(dev + 0.5));
}

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	int		counter;
	int		len;
	int		dev;

	counter = 0;
	len = ft_stacksize(*stack_a);
	dev = deviation(len);
	while (*stack_a)
	{
		if ((*stack_a)->content <= counter)
		{
			push((stack_a), (stack_b), 'b');
			rotate((stack_b), 'b');
			counter++;
		}
		else if ((*stack_a)->content <= counter + dev)
		{
			push((stack_a), (stack_b), 'b');
			counter++;
		}
		else
			rotate((stack_a), 'a');
	}
	filling_stack_a(stack_a, stack_b);
}

static void	filling_helper(t_stack **stack_a, t_stack **stack_b, int current)
{
	t_stack	*tmp;
	int		pos;
	int		size;

	pos = 0;
	tmp = *stack_b;
	size = ft_stacksize(tmp);
	while (tmp && tmp->content != current)
	{
		tmp = tmp->next;
		pos++;
	}
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rotate(stack_b, 'b');
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			r_rotate(stack_b, 'b');
	}
	push(stack_b, stack_a, 'a');
}

void	filling_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int		current;
	int		size;

	size = ft_stacksize(*stack_b);
	current = size - 1;
	while (current >= 0)
	{
		filling_helper(stack_a, stack_b, current);
		current--;
	}
}
