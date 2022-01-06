/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 05:48:27 by seomoon           #+#    #+#             */
/*   Updated: 2021/05/05 23:17:30 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_swap(char *cmd, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(cmd, "sa"))
		swap(&a->head);
	else if (!ft_strcmp(cmd, "sb"))
		swap(&b->head);
	else
	{
		swap(&a->head);
		swap(&b->head);
	}
}

void	run_rotate(char *cmd, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(cmd, "ra"))
		rotate(&a->head, &a->tail);
	else if (!ft_strcmp(cmd, "rb"))
		rotate(&b->head, &b->tail);
	else
	{
		rotate(&a->head, &a->tail);
		rotate(&b->head, &b->tail);
	}
}

void	run_reverse_rotate(char *cmd, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(cmd, "rra"))
		reverse_rotate(&a->head, &a->tail);
	else if (!ft_strcmp(cmd, "rrb"))
		reverse_rotate(&b->head, &b->tail);
	else
	{
		reverse_rotate(&a->head, &a->tail);
		reverse_rotate(&b->head, &b->tail);
	}
}
