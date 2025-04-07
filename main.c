/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:36:49 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/07 17:50:21 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *bubble_sort(int *sorting, int length)
{
	int i;
	int temp;

	i = 0;
	while(i < length - 1)
	{
		if(sorting[i] > sorting[i + 1])
		{
			temp = sorting[i];
			sorting[i] = sorting[i + 1];
			sorting[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (sorting);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int 	len;
		int 	i;
		int		j;
		int		*unsorted;
		int		*sorted;
		t_stack	*stack_a;
		t_stack	*tmp;


		len = argc - 1;
		unsorted = (int *)malloc(sizeof(int) * len);
		sorted = (int *)malloc(sizeof(int) * len);
		i = 0;
		while (i < len)
		{
			unsorted[i] = ft_atoi(argv[i + 1]);
			sorted[i] = ft_atoi(argv[i + 1]);
			i++;
		}
		sorted = bubble_sort(sorted, len);
		i = 0;
		j = 0;
		stack_a = NULL;
		while (i < len)
		{
			if (unsorted[i] == sorted[j])
			{
				tmp = ft_stacknew(j);
				ft_stackadd_back(&stack_a, tmp);
				j = 0;
				i++;
			}
			else
				j++;
		}

		tmp = stack_a;
		while (stack_a)
		{
			ft_printf("%d", stack_a->content);
			stack_a = stack_a->next;
		}
		stack_a = tmp;
	}
}
