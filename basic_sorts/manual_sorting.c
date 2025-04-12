/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:53:35 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/12 17:52:03 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ****************************************************************************/

#include "push_swap.h"

void	sort_for_3(t_stack **stack_a)
{
	if ((*stack)->next->next->content == 2)
	{
		if ((*stack)->next->content == 1)
			return ;
		else
		{
			swap_a(*stack_a);
			return ;
		}
	}
	else if ((*stack)->next->content == 2)
	{
		if ((*stack)->next->next->content == 0)
		{
			r_rotate_a(stack_a);
			return ;
		}
		else
		{
			swap_a(*stack_a);
			rotate_a(stack_a);
			return ;
		}
	}
	else
	{
		if ((*stack)->next->content == 0)
		{
			rotate_a(stack_a);
			return ;
		}
		else
		{
			swap_a(*stack_a);
			r_rotate_a(stack_a);
			return ;
		}
	}
}

