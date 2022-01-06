/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:29:18 by seomoon           #+#    #+#             */
/*   Updated: 2021/05/06 10:42:52 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "srcs/utils/gnl.h"

typedef struct		s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_stack
{
	t_node			*head;
	t_node			*tail;
	t_node			**part;
	int				top;
	int				size;
}					t_stack;

int					ft_isdigit(char c);
int					ft_isnum(char *str);
void				ft_putstr_fd(char *str, int fd);
long				ft_atol(char *str);
int					ft_strcmp(char *s1, char *s2);

int					check_only_numbers(int size, char **args);
int					check_duplicate(t_stack *a, int size);
void				init_stack(t_stack *a, t_stack *b, char **args, int size);
void				free_stack(t_stack *a, t_stack *b);

void				push(t_node **src_head, t_node **dst_head, \
					t_node **dst_tail);
void				swap(t_node **head);
void				rotate(t_node **head, t_node **tail);
void				reverse_rotate(t_node **head, t_node **tail);

void				exit_error(void);

void				run_reverse_rotate(char *cmd, t_stack *a, t_stack *b);
void				run_swap(char *cmd, t_stack *a, t_stack *b);
void				run_rotate(char *cmd, t_stack *a, t_stack *b);

int					skip_highers(t_stack *a, int median, int c[2]);
void				median_split_a(t_stack *a, t_stack *b, int median);
void				sort_a(t_stack *a, int count);
int					skip_lowers(t_stack *b, int median, int *reverse_count);
void				median_split_b(t_stack *a, t_stack *b, int median);
void				sort_b(t_stack *b, int count);
void				solve(t_stack *a, t_stack *b);
int					count_nums(t_stack *s);
int					get_median(t_stack *a);

#endif
