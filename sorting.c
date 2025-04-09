/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:26:32 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/09 16:51:52 by rababaya         ###   ########.fr       */
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

	if (!(*stack_a))
		return ;
	counter = 0;
	len = ft_stacksize(*stack_a);
	dev = deviation(len);
	while (*stack_a)
	{
		if ((*stack_a)->content <= counter)
		{
			push((stack_a), (stack_b));
			rotate((stack_b));
			counter++;
		}
		else if ((*stack_a)->content <= counter + dev)
		{
			push((stack_a), (stack_b));
			counter++;
		}
		else
			rotate((stack_a));
	}
}
