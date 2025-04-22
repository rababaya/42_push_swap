/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:20:50 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/22 16:22:26 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

int		if_sorted_stack(t_stack **stack_a);
t_stack	*stack_filling(int *unsorted, int len);

int		*validation(char **argv, int argc);
char	**join_split(char **argv, int argc);

void	rr(t_stack **s_a, t_stack	**s_b);
void	rrr(t_stack **s_a, t_stack	**s_b);
void	ss(t_stack **s_a, t_stack	**s_b);
void	swap(t_stack **stack);
void	push(t_stack **stack, t_stack **dst);
void	rotate(t_stack **stack);
void	r_rotate(t_stack **stack);

void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackclear(t_stack **lst);
int		ft_stacksize(t_stack *lst);
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stacknew(int content);

#endif
