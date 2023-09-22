/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:33:21 by meacar            #+#    #+#             */
/*   Updated: 2023/04/05 13:33:24 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
		tmp = tmp->next;
	head = (*stack);
	*stack = (*stack)->next;
	head->next = NULL;
	tmp->next = head;
}

void	rotate_a(t_list **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rotate_r(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
