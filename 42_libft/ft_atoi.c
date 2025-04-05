/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:42:18 by rababaya          #+#    #+#             */
/*   Updated: 2025/02/03 11:20:02 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	pm;

	res = 0;
	i = 0;
	pm = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			pm = -pm;
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (res * pm);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * pm);
}
