/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 05:48:02 by seomoon           #+#    #+#             */
/*   Updated: 2021/05/06 09:23:28 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			a_sorted(t_stack *a)
{
	t_node	*tmp;

	tmp = a->head;
	while (tmp)
	{
		if (tmp->next && tmp->next->num < tmp->num)
			return (0);
		tmp = tmp->next;
		if (tmp == a->part[a->top])
			break ;
	}
	return (1);
}

int			count_nums(t_stack *s)
{
	int		count;
	t_node	*tmp;

	tmp = s->head;
	count = 0;
	while (tmp != s->part[s->top])
	{
		count++;
		tmp = tmp->next;
	}
	if (!s->part[s->top] && count == 3)
		return (-1);
	return (count);
}

int			split_a(t_stack *a, t_stack *b)
{
	int		count;
	long	median;

	count = count_nums(a);
	if (count < 3)
	{
		sort_a(a, count);
		a->part[++(a->top)] = a->head;
		return (1);
	}
	else
	{
		median = get_median(a);
		median_split_a(a, b, (int)median);
	}
	return (0);
}

void		split_b(t_stack *a, t_stack *b)
{
	int		count;
	long	median;

	count = count_nums(b);
	if (count < 3)
	{
		sort_b(b, count);
		count = (count == -1) ? 3 : count;
		while (count > 0)
		{
			push(&b->head, &a->head, &a->tail);
			write(1, "pa\n", 3);
			count--;
		}
	}
	else
	{
		median = get_median(b);
		median_split_b(a, b, (int)median);
	}
}

void		solve(t_stack *a, t_stack *b)
{
	int		sorted;

	while (!(sorted = a_sorted(a)) || !(b->head == NULL))
	{
		if (!sorted)
		{
			while ((sorted = split_a(a, b)) == 0)
				;
		}
		else
			a->part[++(a->top)] = a->head;
		split_b(a, b);
	}
}
