/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:23:07 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/19 16:49:09 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	new->next = NULL;
	if (!(*lst))
		*lst = new;
	else
		ft_stacklast(*lst)->next = new;
}
