/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:37:24 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/12 14:40:19 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*start;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = ft_stacklast(*stack);
	start = (*stack);
	while (start->next->next)
		start = start->next;
	start->next = NULL;
	tmp->next = *stack;
	(*stack) = tmp;
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*start;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = ft_stacklast(*stack);
	start = (*stack);
	while (start->next->next)
		start = start->next;
	start->next = NULL;
	tmp->next = *stack;
	(*stack) = tmp;
	write(1, "rrb\n", 4);
}
