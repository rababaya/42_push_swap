/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:37:24 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/21 16:31:18 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	r_rotate(t_stack **stack)
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
}
