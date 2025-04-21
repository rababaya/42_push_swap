/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:16:00 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/21 16:31:15 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_stack **stack, t_stack **dst)
{
	t_stack	*tmp;

	if (!(*stack))
		return ;
	tmp = (*stack)->next;
	ft_stackadd_front(dst, *stack);
	*stack = tmp;
}
