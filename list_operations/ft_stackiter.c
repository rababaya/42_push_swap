/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:56:40 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/07 17:23:04 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackiter(t_stack *lst, void (*f)(int))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
	return ;
}
