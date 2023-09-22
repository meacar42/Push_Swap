/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:33:44 by meacar            #+#    #+#             */
/*   Updated: 2023/04/05 13:33:47 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swaping(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!(*stack) && !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	swap_a(t_list **stack)
{
	swaping(stack);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **stack)
{
	swaping(stack);
	write(1, "sb\n", 3);
}

void	swap_ss(t_list **stack_a, t_list **stack_b)
{
	swaping(stack_a);
	swaping(stack_b);
	write(1, "ss\n", 3);
}
