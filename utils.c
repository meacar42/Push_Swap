/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:33:52 by meacar            #+#    #+#             */
/*   Updated: 2023/04/05 13:39:49 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_atoi(char *str)
{
	t_def	d;

	d.k = 0;
	d.sign = 1;
	d.i = 0;
	d.atoin = (int *)malloc(sizeof(int *) * atoi_cal_and_che(str));
	while (str[d.i] && check(&str[d.i]) == 1)
	{
		d.atoin[d.k] = 0;
		while (str[d.i] == ' ' || (str[d.i] >= 9 && str[d.i] <= 13))
			d.i++;
		if ((str[d.i] == '-' || str[d.i] == '+') && check(&str[d.i]))
		{
			if (str[d.i++] == '-')
				d.sign = -1;
		}
		while (str[d.i] >= '0' && str[d.i] <= '9' && \
			str[d.i] && check(&str[d.i]))
			d.atoin[d.k] = (d.atoin[d.k] * 10) + (str[d.i++] - 48) * d.sign;
		d.sign = 1;
		d.k++;
	}
	return (d.atoin);
}

int	check(char	*str)
{
	int		i;

	i = 0;
	if ((str[i] < '0' || str[i] > '9') && \
		str[i] != '-' && str[i] != '+' && str[i] != ' ' && str[i] != '\t')
		ft_error();
	if ((str[i] == '-' || str[i] == '+') && \
		!(str[i + 1] >= '0' && str[i + 1] <= '9'))
		ft_error();
	if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] >= '0' && str[i] <= '9' && str[i])
			i++;
		if ((str[i] != ' ' && str[i] != '\t') && str[i])
			ft_error();
	}
	return (1);
}

int	atoi_cal_and_che(char *str)
{
	t_def	d;

	d.i = 0;
	d.result = 0;
	d.k = 0;
	while (str[d.i])
	{
		d.sign = 1;
		while (str[d.i] == '-' || str[d.i] == '+' || \
			str[d.i] == ' ' || str[d.i] == '\t')
		{
			if (str[d.i++] == '-')
				d.sign *= -1;
		}
		if (!(str[d.i] >= '0' && str[d.i] <= '9') && str[d.i] != '\0')
			ft_error();
		if (str[d.i] >= '0' && str[d.i] <= '9')
			d.k++;
		while (str[d.i] >= '0' && str[d.i] <= '9')
			d.result = (d.result * 10) + (str[d.i++] - 48);
		if (d.result * d.sign > 2147483647 || d.result * d.sign < -2147483648)
			ft_error();
		d.result = 0;
	}
	return (d.k);
}
