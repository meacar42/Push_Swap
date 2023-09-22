/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:30:21 by meacar            #+#    #+#             */
/*   Updated: 2023/04/05 14:11:02 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while (max)
	{
		max = max / 2;
		max_bits++;
	}
	return (max_bits);
}

void	radix_sort(t_list **a, t_list **b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *a;
	size = head_a->index_size;
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *a;
			if (((head_a->index >> i) & 1) == 1)
				rotate_a(a);
			else
				push_b(a, b);
		}
		while (*b != 0)
			push_a(a, b);
		i++;
	}
}

void	lowersizea(t_list **a, t_list **b)
{
	t_list	*iter;
	int		i;

	iter = *a;
	i = iter->index_size - 3;
	if (iter->next->next == NULL)
	{
		if (iter->index > iter->next->index)
			swap_a(a);
	}
	else
	{
		while (iter->next->next->next != NULL)
		{
			if (iter->index < i)
				push_b(a, b);
			else
				r_rotate_a(a);
			iter = *a;
		}
		a_checker(a);
		if (*b != NULL)
			lowersizeb(a, b);
	}
}

void	lowersizeb(t_list **a, t_list **b)
{
	t_list	*iter;
	int		i;

	iter = *b;
	i = iter->index_size - 4;
	while (iter != NULL)
	{
		if (iter->index == i)
		{
			push_a(a, b);
			i--;
		}
		else
			r_rotate_b(b);
		iter = *b;
	}
}

void	a_checker(t_list **a)
{
	t_list	*itera;
	int		k;

	k = 0;
	itera = *a;
	while (k != 1)
	{
		itera = *a;
		if (itera->index > itera->next->index)
			swap_a(a);
		itera = *a;
		if (itera->index < itera->next->index && \
			itera->next->index < itera->next->next->index)
			k = 1;
		else
			r_rotate_a(a);
	}
}
