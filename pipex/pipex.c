/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:08:41 by seomoon           #+#    #+#             */
/*   Updated: 2021/06/08 16:40:53 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void				redirect_out(char *file_name)
{
	int				fd;

	//file_name이 존재하면 읽기쓰기 권한으로 열기, 
	//file_name이 존재하지 않으면 생성하기 (읽기쓰기 권한 부여, 644)
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file_name);
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void				redirect_in(char *file_name)
{
	int				fd;

	fd = open(file_name, O_RDONLY); //file 열기
	if (fd < 0)
	{
		perror(file_name);
		exit(1);
	}
	dup2(fd, STDIN_FILENO); //fd -> stdin
	close(fd); //file 닫기
}

void				connect_pipe(int pipe_fds[2], int fd)
{
	dup2(pipe_fds[fd], fd);
	close(pipe_fds[0]);
	close(pipe_fds[1]);
}

void				init_cmd(const char *cmd, t_cmd *cmd_struct)
{
	char			**split_cmd;

	split_cmd = ft_split(cmd, ' ');
	cmd_struct->cmd[0] = ft_strjoin("/bin/", split_cmd[0]);
	cmd_struct->cmd[1] = ft_strjoin("/usr/local/bin/", split_cmd[0]);
	cmd_struct->cmd[2] = ft_strjoin("/usr/bin/", split_cmd[0]);
	cmd_struct->cmd[3] = ft_strjoin("/usr/sbin/", split_cmd[0]);
	cmd_struct->cmd[4] = ft_strjoin("/sbin/", split_cmd[0]);
	cmd_struct->argv = (char *const *)split_cmd;
}

void				run_cmd(const char *cmd, t_cmd *cmd_struct)
{
	int				i;

	i = 0;
	init_cmd(cmd, cmd_struct);
	while (i < 5)
	{
		execve(cmd_struct->cmd[i], cmd_struct->argv, cmd_struct->envp);
		i++;
	}
	perror(cmd_struct->argv[0]);
}

int					main(int argc, char **argv)
{
	pid_t			pid;
	int				pipe_fds[2];
	t_cmd			cmd;
	int				status;

	if (argc != 5)
		return (1);
	pipe(pipe_fds);
	pid = fork();
	if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) == 0) //자식 프로세스가 비정상적으로 종료된 경우
			exit(1); //종료 (상태코드 1 반환)
		redirect_out(FILE_2);
		connect_pipe(pipe_fds, STDIN_FILENO);
		run_cmd(CMD_2, &cmd);
	}
	else if (pid == 0)
	{
		redirect_in(FILE_1);
		connect_pipe(pipe_fds, STDOUT_FILENO);
		run_cmd(CMD_1, &cmd);
	}
	return (0);
}
