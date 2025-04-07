/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:40:00 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/07 17:22:51 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackdelone(t_stack *lst, void (*del)(int))
{
	if (del && lst)
	{
		del(lst->content);
		free(lst);
		return ;
	}
}
