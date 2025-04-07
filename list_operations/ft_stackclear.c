/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:53:13 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/07 17:22:45 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackclear(t_stack **lst, void (*del)(int))
{
	if (*lst && del)
	{
		ft_stackclear(&(*lst)->next, (*del));
		del((*lst)->content);
		free(*lst);
		*lst = NULL;
	}
	return ;
}
