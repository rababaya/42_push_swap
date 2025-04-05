/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:53:13 by rababaya          #+#    #+#             */
/*   Updated: 2025/02/04 15:31:44 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (*lst && del)
	{
		ft_lstclear(&(*lst)->next, (*del));
		del((*lst)->content);
		free(*lst);
		*lst = NULL;
	}
	return ;
}
