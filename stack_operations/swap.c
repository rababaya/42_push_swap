/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:27:22 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/18 18:25:40 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next->next;
	(*stack)->next->next = *stack;
	(*stack) = (*stack)->next;
	(*stack)->next->next = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next->next;
	(*stack)->next->next = *stack;
	(*stack) = (*stack)->next;
	(*stack)->next->next = tmp;
	write(1, "sb\n", 3);
}
