/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:13:14 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/22 15:41:42 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rr(t_stack **s_a, t_stack	**s_b)
{
	rotate(s_a);
	rotate(s_b);
}

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
