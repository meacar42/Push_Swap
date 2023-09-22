/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:32:46 by meacar            #+#    #+#             */
/*   Updated: 2023/04/05 14:11:48 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    PUSH_SWAP_H
# define    PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int					content;
	struct s_list		*next;
	int					index;
	int					index_size;
}	t_list;

typedef struct s_def
{
	int		k;
	int		*atoin;
	int		i;
	int		sign;
	long	result;
}	t_def;

void	lowersizea(t_list **a, t_list **b);
void	lowersizeb(t_list **a, t_list **b);
int		*ft_atoi(char *str);
int		check(char *str);
int		atoi_cal_and_che(char *str);
void	ft_error(void);
void	ordinal_number(t_list **a);
void	swap_a(t_list **a);
void	swap_b(t_list **b);
void	swap_ss(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **b, t_list **a);
void	r_rotate_a(t_list **a);
void	r_rotate_b(t_list **b);
void	r_rotate_r(t_list **a, t_list **b);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rotate_rr(t_list **a, t_list **b);
void	index_adder(t_list **a);
int		*str_fill(t_list **a, int *str);
int		find_last_list(t_list **list);
int		*sort_str(t_list **a, int *str);
void	radix_sort(t_list **a, t_list **b);
void	a_checker(t_list **a);
void	push(t_list **stack_a, t_list **stack_b);
void	swaping(t_list **stack);
void	reverse_rotate(t_list **stack);
#endif
