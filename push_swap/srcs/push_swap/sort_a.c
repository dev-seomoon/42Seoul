/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:29:55 by seomoon           #+#    #+#             */
/*   Updated: 2021/05/06 10:47:44 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			skip_highers(t_stack *a, int median, int *reverse_count)
{
	int		count;
	t_node	*tmp;

	count = 0;
	tmp = a->head;
	while (tmp != a->part[a->top])
	{
		if (tmp->num <= median)
			break ;
		count++;
		tmp = tmp->next;
	}
	if (tmp == a->part[a->top])
		return (0);
	*reverse_count += count;
	while (count > 0)
	{
		rotate(&a->head, &a->tail);
		write(1, "ra\n", 3);
		count--;
	}
	return (1);
}

void		median_split_a(t_stack *a, t_stack *b, int median)
{
	int		reverse_count;

	if (b->head)
		b->part[++(b->top)] = b->head;
	reverse_count = 0;
	while (a->head != a->part[a->top])
	{
		if (a->head->num <= median)
		{
			push(&a->head, &b->head, &b->tail);
			write(1, "pb\n", 3);
		}
		else if (!(skip_highers(a, median, &reverse_count)))
			break ;
	}
	while (a->part[a->top] && reverse_count > 0)
	{
		reverse_rotate(&a->head, &a->tail);
		write(1, "rra\n", 4);
		reverse_count--;
	}
}

void		sort_three_nums_a(t_stack *a)
{
	while (!(a->head->next->num < a->head->next->next->num
				&& a->head->num < a->head->next->next->num))
	{
		if (a->head->next->num > a->head->next->next->num
				&& a->head->next->num > a->head->num)
		{
			reverse_rotate(&a->head, &a->tail);
			write(1, "rra\n", 4);
		}
		else
		{
			rotate(&a->head, &a->tail);
			write(1, "ra\n", 3);
		}
	}
	if (a->head->num > a->head->next->num)
	{
		swap(&a->head);
		write(1, "sa\n", 3);
	}
}

void		sort_a(t_stack *a, int count)
{
	if (count == 1)
		return ;
	else if (count == 2)
	{
		if (a->head->num > a->head->next->num)
		{
			swap(&a->head);
			write(1, "sa\n", 3);
		}
	}
	else
		sort_three_nums_a(a);
}
