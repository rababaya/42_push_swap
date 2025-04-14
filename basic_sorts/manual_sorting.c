/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:32:56 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/14 16:46:21 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_second(t_stack **stack_a)
{
	if ((*stack_a)->next->next->content == 0)
		r_rotate_a(stack_a);
	else
	{
		swap_a(*stack_a);
		rotate_a(stack_a);
	}
	return ;
}

static void	handle_first(t_stack **stack_a)
{
	if ((*stack_a)->next->content == 0)
		rotate_a(stack_a);
	else
	{
		swap_a(*stack_a);
		r_rotate_a(stack_a);
	}
	return ;
}

void	sort_for_3(t_stack **stack_a)
{
	if ((*stack_a)->next->next->content == 2)
	{
		swap_a(*stack_a);
		return ;
	}
	else if ((*stack_a)->next->content == 2)
	{
		handle_second(stack_a);
		return ;
	}
	else
	{
		handle_first(stack_a);
		return ;
	}
}

void	sort_for_4(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*start;

	i = 0;
	start = *stack_a;
	while ((*stack_a)->content != 3)
	{
		i++;
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = start;
	if (i > 1)
		while (i++ <= 3)
			r_rotate_a(stack_a);
	else
		while (i-- > 0)
			rotate_a(stack_a);
	push_b(stack_a, stack_b);
	sort_for_3(stack_a);
	push_a(stack_b, stack_b);
	rotate_a(stack_a);
	return ;
}

void	sort_for_5(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*start;

	i = 0;
	start = *stack_a;
	while ((*stack_a)->content != 4)
	{
		i++;
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = start;
	if (i > 1)
		while (i++ <= 4)
			r_rotate_a(stack_a);
	else
		while (i-- > 0)
			rotate_a(stack_a);
	push_b(stack_a, stack_b);
	sort_for_4(stack_a, stack_b);
	push_a(stack_b, stack_b);
	rotate_a(stack_a);
	return ;
}
