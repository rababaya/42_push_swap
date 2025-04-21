/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:27:22 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/21 16:31:23 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next->next;
	(*stack)->next->next = *stack;
	(*stack) = (*stack)->next;
	(*stack)->next->next = tmp;
}
