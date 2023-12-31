/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:32:55 by meacar            #+#    #+#             */
/*   Updated: 2023/04/05 13:32:57 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_a;
	t_list	*top_b;
	t_list	*tmp;

	if (!(*stack_a))
		return ;
	top_a = (*stack_a);
	top_b = (*stack_b);
	tmp = top_a->next;
	top_a->next = top_b;
	(*stack_a) = tmp;
	(*stack_b) = top_a;
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
