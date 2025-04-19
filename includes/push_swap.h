/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:19:22 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/19 17:19:15 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_filling(int *unsorted, int len);

int		*validation(char **argv, int argc);
char	**join_split(char **argv, int argc);

void	filling_stack_a(t_stack **stack_a, t_stack **stack_b);
void	sorting(t_stack **stack_a, t_stack **stack_b);

void	sort_for_5(t_stack **stack_a, t_stack **stack_b);
void	sort_for_4(t_stack **stack_a, t_stack **stack_b);
void	sort_for_3(t_stack **stack_a);

void	swap(t_stack **stack, char c);
void	push(t_stack **stack, t_stack **dst, char c);
void	rotate(t_stack **stack, char c);
void	r_rotate(t_stack **stack, char c);

void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackdelone(t_stack *lst);
void	ft_stackclear(t_stack **lst);
void	ft_stackiter(t_stack *lst, void (*f)(int));
int		ft_stacksize(t_stack *lst);
t_stack	*ft_stackmap(t_stack *lst, int (*f)(int));
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stacknew(int content);

#endif
