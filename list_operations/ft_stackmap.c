/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:02:20 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/08 15:41:52 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stackmap(t_stack *lst, int (*f)(int))
{
	t_stack	*tmp;
	t_stack	*ret;

	ret = NULL;
	while (lst && f)
	{
		tmp = ft_stacknew(f(lst->content));
		if (tmp)
			ft_stackadd_back(&ret, tmp);
		else
		{
			ft_stackclear(&ret);
			return (NULL);
		}
		lst = lst->next;
	}
	return (ret);
}
