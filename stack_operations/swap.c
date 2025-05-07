/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:27:22 by rababaya          #+#    #+#             */
/*   Updated: 2025/05/07 13:53:34 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char c)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next->next;
	(*stack)->next->next = *stack;
	(*stack) = (*stack)->next;
	(*stack)->next->next = tmp;
	ft_printf("s%c\n", c);
}
