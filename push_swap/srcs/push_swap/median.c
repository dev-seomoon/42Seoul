/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 05:47:50 by seomoon           #+#    #+#             */
/*   Updated: 2021/05/06 09:20:32 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_median(t_stack *a)
{
	t_node	*tmp;
	int		arr[a->size + 1];
	int		i;
	int		j[2];

	tmp = a->head;
	i = 0;
	while (tmp != a->part[a->top])
	{
		arr[i++] = tmp->num;
		tmp = tmp->next;
	}
	j[0] = -1;
	while (j[0]++ < i)
	{
		j[1] = j[0];
		while (++j[1] < i)
			if (arr[j[0]] < arr[j[1]])
			{
				arr[a->size] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[a->size];
			}
	}
	return (arr[i / 2]);
}
