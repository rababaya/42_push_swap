/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:44:32 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/19 17:14:20 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_second(t_stack **stack_a)
{
	if ((*stack_a)->next->next->content == 0)
		r_rotate(stack_a, 'a');
	else
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	return ;
}

static void	handle_first(t_stack **stack_a)
{
	if ((*stack_a)->next->content == 0)
		rotate(stack_a, 'a');
	else
	{
		swap(stack_a, 'a');
		r_rotate(stack_a, 'a');
	}
	return ;
}

void	sort_for_3(t_stack **stack_a)
{
	if ((*stack_a)->next->next->content == 2)
	{
		if ((*stack_a)->content == 1)
			swap(stack_a, 'a');
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
			r_rotate(stack_a, 'a');
	else
		while (i-- > 0)
			rotate(stack_a, 'a');
	push(stack_a, stack_b, 'b');
	sort_for_3(stack_a);
	push(stack_b, stack_a, 'a');
	rotate(stack_a, 'a');
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
	if (i > 2)
		while (i++ <= 4)
			r_rotate(stack_a, 'a');
	else
		while (i-- > 0)
			rotate(stack_a, 'a');
	push(stack_a, stack_b, 'b');
	sort_for_4(stack_a, stack_b);
	push(stack_b, stack_a, 'a');
	rotate(stack_a, 'a');
	return ;
}
