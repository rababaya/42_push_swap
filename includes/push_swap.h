/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:19:22 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/18 18:27:59 by rababaya         ###   ########.fr       */
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
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_arr
{
	int	*unsorted;
	int	*sorted;
}	t_arr;

void	sort_all(int len, t_stack **stack_a, t_stack **stack_b);
void	free_all(int *unsorted, int *sorted, t_stack **stack_a, t_stack **stack_b);
t_stack	*stack_filling(int *unsorted, int *sorted, int len);

int		*validation(char **argv, int argc);
char	**join_split(char **argv, int argc);

void	filling_stack_a(t_stack **stack_a, t_stack **stack_b);
void	sorting(t_stack **stack_a, t_stack **stack_b);

void	sort_for_5(t_stack **stack_a, t_stack **stack_b);
void	sort_for_4(t_stack **stack_a, t_stack **stack_b);
void	sort_for_3(t_stack **stack_a);

void	swap_a(t_stack **stack);
void	swap_b(t_stack **stack);
void	push_a(t_stack **stack, t_stack **dst);
void	push_b(t_stack **stack, t_stack **dst);
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	r_rotate_a(t_stack **stack);
void	r_rotate_b(t_stack **stack);

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
