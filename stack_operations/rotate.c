/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:13:14 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/19 17:10:38 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, char c)
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
	ft_printf("r%c\n", c);
}
