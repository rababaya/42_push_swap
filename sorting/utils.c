/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:37:17 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/18 18:28:53 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_all(int len, t_stack **stack_a, t_stack **stack_b)
{
	if (len == 2)
		swap_a(stack_a);
	else if (len == 3)
		sort_for_3(stack_a);
	else if (len == 4)
		sort_for_4(stack_a, stack_b);
	else if (len == 5)
		sort_for_5(stack_a, stack_b);
	else
		sorting(stack_a, stack_b);
}

void	free_all(int *unsorted, int *sorted, t_stack **stack_a, t_stack **stack_b)
{
	ft_stackclear(stack_a);
	ft_stackclear(stack_b);
	free(unsorted);
	free(sorted);
}

t_stack	*stack_filling(int *unsorted, int *sorted, int len)
{
	int		i;
	int		j;
	t_stack	*tmp;
	t_stack	*stack;

	i = 0;
	j = 0;
	stack = NULL;
	while (i < len)
	{
		if (unsorted[i] == sorted[j])
		{
			tmp = ft_stacknew(j);
			if (!tmp)
				return (ft_stackclear(&stack) ,NULL);
			ft_stackadd_back(&stack, tmp);
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (stack);
}
