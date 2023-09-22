/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:33:59 by meacar            #+#    #+#             */
/*   Updated: 2023/04/05 13:41:21 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_adder(t_list **a)
{
	int		*str;
	int		j;
	int		i;
	t_list	*iter;

	i = 0;
	str = NULL;
	j = find_last_list(a);
	str = sort_str(a, str);
	iter = *a;
	while (j > i)
	{
		if (iter->content == str[i])
		{
			iter->index = i;
			i++;
		}
		iter = iter->next;
		if (iter == NULL)
			iter = *a;
	}
	free(str);
}

int	*str_fill(t_list **a, int *str)
{
	t_list	*iter;
	int		i;
	int		j;

	j = find_last_list(a);
	str = malloc(sizeof(int) * j);
	i = 0;
	iter = *a;
	while (iter != NULL)
	{
		str[i] = iter->content;
		iter->index_size = j;
		i++;
		iter = iter->next;
	}
	return (str);
}

int	find_last_list(t_list **list)
{
	int		i;
	t_list	*iter;

	iter = *list;
	i = 0;
	while (iter != NULL)
	{
		iter = iter->next;
		i++;
	}
	return (i);
}

int	*sort_str(t_list **a, int *str)
{
	int	i;
	int	k;
	int	tmp;
	int	j;

	j = find_last_list(a);
	str = str_fill(a, str);
	k = 0;
	i = 0;
	while (i < j)
	{
		k = 0;
		while (k < j)
		{
			if (str[i] < str[k])
			{
				tmp = str[i];
				str[i] = str[k];
				str[k] = tmp;
			}
			k++;
		}
		i++;
	}
	return (str);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
