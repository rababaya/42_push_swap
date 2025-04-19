/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:16:00 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/19 17:02:37 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack, t_stack **dst, char c)
{
	t_stack	*tmp;

	if (!(*stack))
		return ;
	tmp = (*stack)->next;
	ft_stackadd_front(dst, *stack);
	*stack = tmp;
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
