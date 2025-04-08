/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:13:14 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/08 18:44:15 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
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
}
