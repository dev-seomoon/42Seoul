/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 05:47:31 by seomoon           #+#    #+#             */
/*   Updated: 2021/05/06 10:42:12 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			skip_lowers(t_stack *b, int median, int *reverse_count)
{
	int		count;
	t_node	*tmp;

	count = 0;
	tmp = b->head;
	while (tmp != b->part[b->top])
	{
		if (tmp->num > median)
			break ;
		count++;
		tmp = tmp->next;
	}
	if (tmp == b->part[b->top])
		return (0);
	*reverse_count += count;
	while (count > 0)
	{
		rotate(&b->head, &b->tail);
		write(1, "rb\n", 3);
		count--;
	}
	return (1);
}

void		median_split_b(t_stack *a, t_stack *b, int median)
{
	int		count;
	int		reverse_count;

	count = 0;
	reverse_count = 0;
	while (b->head != b->part[b->top])
	{
		if (b->head->num > median)
		{
			push(&b->head, &a->head, &a->tail);
			write(1, "pa\n", 3);
		}
		else if (!(skip_lowers(b, median, &reverse_count)))
			break ;
	}
	while (b->part[b->top] && reverse_count > 0)
	{
		reverse_rotate(&b->head, &b->tail);
		write(1, "rrb\n", 4);
		reverse_count--;
	}
}

void		sort_three_nums_b(t_stack *b)
{
	while (!(b->head->next->num > b->head->next->next->num
	&& b->head->num > b->head->next->next->num))
	{
		if (b->head->next->num < b->head->next->next->num
		&& b->head->next->num < b->head->num)
		{
			reverse_rotate(&b->head, &b->tail);
			write(1, "rrb\n", 4);
		}
		else
		{
			rotate(&b->head, &b->tail);
			write(1, "rb\n", 3);
		}
	}
	if (b->head->num < b->head->next->num)
	{
		swap(&b->head);
		write(1, "sb\n", 3);
	}
}

void		sort_b(t_stack *b, int count)
{
	if (b->top)
		b->top--;
	if (count == 0 || count == 1)
		return ;
	else if (count == 2)
	{
		if (b->head->next && b->head->next->num > b->head->num)
		{
			swap(&b->head);
			write(1, "sb\n", 3);
		}
	}
	else
		sort_three_nums_b(b);
}
