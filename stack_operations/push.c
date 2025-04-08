/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:16:00 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/08 17:08:40 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack, t_stack **dst)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	tmp = (*stack)->next;
	ft_stackadd_front(dst, *stack);
	*stack = tmp;
}
