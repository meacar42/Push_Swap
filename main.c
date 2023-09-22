/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:30:30 by meacar            #+#    #+#             */
/*   Updated: 2023/04/05 14:11:39 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ordinal_number(t_list **a)
{
	t_list	*iter;
	int		k;
	int		j;

	iter = *a;
	k = iter->index_size;
	j = 1;
	while (iter->next != NULL)
	{
		if (iter->content < iter->next->content)
			j++;
		iter = iter->next;
	}
	if (k == j)
		exit(0);
}

int	repeating_number(t_list *a)
{
	t_list	*iter;
	t_list	*iter2;

	iter = a;
	while (iter->next != NULL)
	{
		iter2 = iter->next;
		while (iter2)
		{
			if (iter->content == iter2->content)
			{
				write(2, "Error\n", 6);
				exit(0);
			}
			iter2 = iter2->next;
		}
		iter = iter->next;
	}
	return (0);
}

void	add_a(int ac, char **ag, t_list **a)
{
	t_def	d;
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	*a = list;
	d.i = 0;
	d.result = 0;
	while (++d.i < ac)
	{
		d.k = atoi_cal_and_che(ag[d.i]);
		d.atoin = ft_atoi(ag[d.i]);
		while (d.k-- > 0)
		{
			list->content = d.atoin[d.result++];
			if (d.i == ac - 1 && d.k == 0)
			{
				list->next = NULL;
				break ;
			}
			list->next = (t_list *)malloc(sizeof(t_list));
			list = list->next;
		}
		d.result = 0;
		free(d.atoin);
	}
}

int	main(int ac, char **ag)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (ac <= 1)
		return (0);
	add_a(ac, ag, &a);
	repeating_number(a);
	index_adder(&a);
	ordinal_number(&a);
	if (a->index_size < 42)
		lowersizea(&a, &b);
	else
		radix_sort(&a, &b);
	return (0);
}
