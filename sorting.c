/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:26:32 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/12 15:05:17 by rababaya         ###   ########.fr       */
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

	if (!(*stack_a)) ///jnjel validaciaic heto
		return ;
	counter = 0;
	len = ft_stacksize(*stack_a);
	dev = deviation(len);
	while (*stack_a)
	{
		if ((*stack_a)->content <= counter)
		{
			push_b((stack_a), (stack_b));
			rotate_b((stack_b));
			counter++;
		}
		else if ((*stack_a)->content <= counter + dev)
		{
			push_b((stack_a), (stack_b));
			counter++;
		}
		else
			rotate_a((stack_a));
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
			rotate_b(stack_b);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			r_rotate_b(stack_b);
	}
	push_a(stack_b, stack_a);
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
