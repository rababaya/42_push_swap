/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:37:17 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/22 15:07:49 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*bubble_sort(int *sorting, int length)
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

static int	*arr_dup(int *arr, int len)
{
	int	i;
	int	*dest;

	i = 0;
	dest = malloc(len * sizeof(int));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = arr[i];
		i++;
	}
	dest = bubble_sort(dest, len);
	return (dest);
}

static void	fill_help(int len, int **uns, int **s, t_stack **stack)
{
	int		i;
	int		j;
	t_stack	*tmp;

	j = 0;
	i = 0;
	while (i < len)
	{
		if ((*uns)[i] == (*s)[j])
		{
			tmp = ft_stacknew(j);
			if (!tmp)
				return (ft_stackclear(stack), free(*s), free(*uns));
			ft_stackadd_back(stack, tmp);
			j = 0;
			i++;
		}
		else
			j++;
	}
}

t_stack	*stack_filling(int *unsorted, int len)
{
	t_stack	*stack;
	int		*sorted;

	sorted = arr_dup(unsorted, len);
	if (!sorted)
		return (NULL);
	stack = NULL;
	fill_help(len, &unsorted, &sorted, &stack);
	if (!stack)
		return (NULL);
	return (free(unsorted), free(sorted), stack);
}
