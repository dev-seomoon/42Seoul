/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 05:48:17 by seomoon           #+#    #+#             */
/*   Updated: 2021/05/06 11:57:33 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		exit_checker(t_stack *a, t_stack *b, int ok)
{
	free_stack(a, b);
	if (ok)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	exit(1);
}

int			check_a_sorted(t_stack *a)
{
	t_node	*tmp;

	tmp = a->head;
	while (tmp->next != NULL)
	{
		if (tmp->next->num < tmp->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			check_b_empty(t_stack *b)
{
	if (b->head)
		return (0);
	return (1);
}

void		treat_instruction(char *s, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(s, "sa") || !ft_strcmp(s, "sb") || !ft_strcmp(s, "ss"))
		run_swap(s, a, b);
	else if (!ft_strcmp(s, "pa"))
		push(&b->head, &a->head, &a->tail);
	else if (!ft_strcmp(s, "pb"))
		push(&a->head, &b->head, &b->tail);
	else if (!ft_strcmp(s, "ra") || !ft_strcmp(s, "rb") || !ft_strcmp(s, "rr"))
		run_rotate(s, a, b);
	else if (!ft_strcmp(s, "rra") || !ft_strcmp(s, "rrb") ||
			!ft_strcmp(s, "rrr"))
		run_reverse_rotate(s, a, b);
	else
	{
		free_stack(a, b);
		exit_error();
	}
}

int			main(int argc, char **args)
{
	t_stack	a;
	t_stack	b;
	char	*line;

	if (argc < 2)
		return (-1);
	init_stack(&a, &b, args, argc);
	while (get_next_line(0, &line) > 0)
	{
		treat_instruction(line, &a, &b);
		free(line);
	}
	if (check_a_sorted(&a) && check_b_empty(&b))
		exit_checker(&a, &b, 1);
	else
		exit_checker(&a, &b, 0);
}
