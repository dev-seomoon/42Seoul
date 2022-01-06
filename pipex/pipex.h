/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:40:57 by seomoon           #+#    #+#             */
/*   Updated: 2021/06/08 15:52:52 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define FILE_1 argv[1]
# define FILE_2 argv[4]
# define CMD_1 argv[2]
# define CMD_2 argv[3]

typedef struct		s_cmd
{
	const char		*cmd[5];
	char *const		*argv;
	char *const		*envp;
}					t_cmd;

int					ft_strlen(const char *str);
char				*ft_strjoin(const char *s1, const char *s2);
char				**ft_split(const char *str, char sep);

#endif
