/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:19:22 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/06 15:23:17 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // navsyaki

typedef struct s_stack
{
	int		content;
//	size_t	index;  /*navsyaki 2*/
	struct	s_stack	*next;
}	t_stack;

#endif
