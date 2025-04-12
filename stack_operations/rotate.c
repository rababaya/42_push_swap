/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:13:14 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/12 14:40:34 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stack)
{
	t_stack	*start;
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	start = (*stack)->next;
	tmp = ft_stacklast(*stack);
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack) = start;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack)
{
	t_stack	*start;
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	start = (*stack)->next;
	tmp = ft_stacklast(*stack);
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack) = start;
	write(1, "rb\n", 3);
}
