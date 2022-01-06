/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 05:48:40 by seomoon           #+#    #+#             */
/*   Updated: 2021/05/06 05:12:05 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void		ft_lstadd_end(char *str, t_node **tail)
{
	long	num;
	t_node	*tmp;

	if (*tail == NULL)
		return ;
	num = ft_atol(str);
	if (num > 2147483647 || num < -2147483648)
		exit_error();
	if (!(tmp = malloc(sizeof(t_node))))
		exit_error();
	tmp->num = (int)num;
	tmp->next = NULL;
	(*tail)->next = tmp;
	tmp->prev = *tail;
	*tail = tmp;
}

void		free_stack(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	while (a->head)
	{
		tmp = a->head;
		a->head = a->head->next;
		free(tmp);
	}
	while (b->head)
	{
		tmp = b->head;
		b->head = b->head->next;
		free(tmp);
	}
}

void		init_stack(t_stack *a, t_stack *b, char **args, int size)
{
	int		i;
	long	num;

	i = 1;
	num = ft_atol(args[i++]);
	if (num > 2147483647 || num < -2147483648)
		exit_error();
	if (!check_only_numbers(size, args) || !(a->head = malloc(sizeof(t_node))))
		exit_error();
	a->head->num = (int)num;
	a->head->prev = NULL;
	a->tail = a->head;
	b->head = NULL;
	b->tail = NULL;
	a->size = size;
	b->size = size;
	while (i < size)
		ft_lstadd_end(args[i++], &a->tail);
	if (!check_duplicate(a, size))
	{
		free_stack(a, b);
		exit_error();
	}
}
