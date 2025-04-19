/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:27:22 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/19 17:07:10 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char c)
{
	t_stack	*tmp;

	tmp = (*stack)->next->next;
	(*stack)->next->next = *stack;
	(*stack) = (*stack)->next;
	(*stack)->next->next = tmp;
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
