/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:51:37 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/14 17:02:44 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bubble_sort(int *sorting, int length)
{
	int	i;
	int	temp;

	i = 0;
	while (i < length - 1)
	{
		if (sorting[i] > sorting[i + 1])
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

static int	if_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i + 1] < arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		len;
	int		i;
	int		j;
	int		*unsorted;
	int		*sorted;
	t_stack	*stack_a;
	t_stack	*tmp;

	if (argc <= 1)
		exit(1);
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

	i = 0;

	if (if_sorted(unsorted, len))
			return (0);
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
	/*testi skizb */
	tmp = NULL;
	if (len == 3)
		sort_for_3(&stack_a);
	else
		sorting(&stack_a, &tmp);
	/* testi verj*/
	ft_stackclear(&stack_a);
	free(sorted);
	free(unsorted);
}
