/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 00:37:35 by seomoon           #+#    #+#             */
/*   Updated: 2021/05/06 10:46:44 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_only_numbers(int size, char **args)
{
	int		i;

	i = 1;
	while (i < size)
	{
		if (!ft_isnum(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int			check_duplicate(t_stack *a, int size)
{
	t_node	*tmp;
	int		i;
	int		j;
	int		k;
	int		arr[size - 1];

	i = 0;
	tmp = a->head;
	while (tmp)
	{
		arr[i++] = tmp->num;
		tmp = tmp->next;
	}
	j = 0;
	while (j < i)
	{
		k = j;
		while (++k < i)
		{
			if (arr[j] == arr[k])
				return (0);
		}
		j++;
	}
	return (1);
}
