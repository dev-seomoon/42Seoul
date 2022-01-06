/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 04:13:08 by seomoon           #+#    #+#             */
/*   Updated: 2021/05/06 11:57:23 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_partition(t_stack *a, t_stack *b)
{
	free(a->part);
	free(b->part);
}

void	init_partition(t_stack *a, t_stack *b, int size)
{
	a->part = malloc(sizeof(t_node *) * size);
	b->part = malloc(sizeof(t_node *) * size);
	if (!a->part || !b->part)
		exit(1);
	a->top = 0;
	b->top = 0;
	a->part[a->top] = NULL;
	b->part[b->top] = NULL;
}

int		main(int argc, char **args)
{
	t_stack	a;
	t_stack	b;

	init_stack(&a, &b, args, argc);
	init_partition(&a, &b, argc);
	solve(&a, &b);
	free_stack(&a, &b);
	free_partition(&a, &b);
}
