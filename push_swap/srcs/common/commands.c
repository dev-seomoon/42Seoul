/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 05:48:48 by seomoon           #+#    #+#             */
/*   Updated: 2021/05/06 00:39:11 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push(t_node **src_head, t_node **dst_head, t_node **dst_tail)
{
	t_node	*tmp;

	if (*src_head == NULL)
		return ;
	tmp = *src_head;
	*src_head = (*src_head)->next;
	if (*src_head)
		(*src_head)->prev = NULL;
	if (*dst_head)
		(*dst_head)->prev = tmp;
	else
		*dst_tail = tmp;
	tmp->next = *dst_head;
	*dst_head = tmp;
	(*dst_head)->prev = NULL;
}

void		swap(t_node **head)
{
	t_node	*tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	tmp->prev = *head;
	(*head)->next = tmp;
	(*head)->prev = NULL;
}

void		rotate(t_node **head, t_node **tail)
{
	if (*head == NULL || *tail == NULL || (*head)->next == NULL)
		return ;
	(*tail)->next = *head;
	(*head)->prev = *tail;
	*head = (*head)->next;
	(*head)->prev = NULL;
	*tail = (*tail)->next;
	(*tail)->next = NULL;
}

void		reverse_rotate(t_node **head, t_node **tail)
{
	if (*head == NULL || *tail == NULL || (*tail)->prev == NULL)
		return ;
	(*head)->prev = *tail;
	(*tail)->next = *head;
	*head = *tail;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
	(*head)->prev = NULL;
}
