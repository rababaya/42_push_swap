/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:01:35 by rababaya          #+#    #+#             */
/*   Updated: 2025/01/24 14:25:22 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	void		*res;

	i = 0;
	res = malloc(count * size);
	if (res)
	{
		ft_bzero(res, count * size);
		return (res);
	}
	return (NULL);
}
