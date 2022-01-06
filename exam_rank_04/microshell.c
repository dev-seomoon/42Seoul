#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct  s_cmd
{
    char            **args;
    int             fd[2];
    int             pipe;
    struct s_cmd    *prev;
    struct s_cmd    *next;
}               t_cmd;

// utils

int     ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

void    ft_putstr_err(char *s)
{
    write(2, s, ft_strlen(s));
}

void    exit_error()
{
    ft_putstr_err("error fatal\n");
    exit(1);
}

char    *ft_strdup(char *s1)
{
    char *s2;
    s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
    if (!s2)
        exit_error();

    int i = 0;
    while (s1[i])
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}

int is_cmd_end(int ac, char **av, int end)
{
    if (!strcmp(av[end], "|") || !strcmp(av[end], ";"))
        return (1);
    else if (end + 1 == ac)
        return (1);
    return (0);
}

// shell
int ft_cd(t_cmd* cmd)
{
    int result = 0;
    int i = 0;
    while (cmd->args[i])
        i++;
    if (i != 2) {
        ft_putstr_err("error: cd: bad arguments\n");
        return (1);
    }
    result = chdir(cmd->args[1]); //exec cd
    if (result < 0) {
        ft_putstr_err("error: cd: cannot change directory to ");
        ft_putstr_err(cmd->args[1]);
        ft_putstr_err("\n");
    }
    return (result);
}

int ft_program(t_cmd *cmd, char **env)
{
    pid_t   pid;
    int     status;
    int     result = 0;

    if (cmd->pipe && pipe(cmd->fd) < 0)
        exit_error();
    
    pid = fork();
    if (pid < 0) exit_error();
    else if (pid == 0)
    {
        if (cmd->pipe && dup2(cmd->fd[1], 1) < 0)
            exit_error();
        if (cmd->prev && cmd->prev->pipe && dup2(cmd->prev->fd[0], 0) < 0)
            exit_error();
        result = execve(cmd->args[0], cmd->args, env);
        if (result < 0) {
            ft_putstr_err("error: cannot execute ");
            ft_putstr_err(cmd->args[0]);
            ft_putstr_err("\n");
        }
        exit(result);
    }
    else if (pid > 0)
    {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
            result = WEXITSTATUS(status);
        if (cmd->pipe) {
            close(cmd->fd[1]);
            if (!cmd->next)
                close(cmd->fd[0]);
        }
        if (cmd->prev && cmd->prev->pipe)
            close(cmd->prev->fd[0]);
    }
    return (result);
}

// handle cmd

t_cmd   *init_cmd(t_cmd *temp, char **av, int len, int pipe)
{
    t_cmd   *new;

    // cmd alloc
    if (!(new = malloc(sizeof(t_cmd))))
        exit_error();
    if (!(new->args = malloc(sizeof(char *) * (len + 1))))
        exit_error();
    
    // cmd init
    int i = 0;
    while (i < len)
    {
        new->args[i] = ft_strdup(av[i]);
        i++;
    }
    new->args[i] = NULL;
    new->pipe = pipe;
    new->prev = temp;
    new->next = NULL;
    if (temp)
        temp->next = new;

    return (new);
}

int exec_cmd(t_cmd *cmd, char **env)
{
    int result = 0;

    while (cmd)
    {
        if (!strcmp(cmd->args[0], "cd"))
            result = ft_cd(cmd);
        else
            result = ft_program(cmd, env);
        cmd = cmd->next;
    }
    return (result);
}

void    clear_cmd(t_cmd *cmd)
{
    t_cmd   *temp;

    int i;
    while (cmd)
    {
        i = 0;
        while (cmd->args[i])
            free(cmd->args[i++]);
        free(cmd->args);
        temp = cmd;
        cmd = cmd->next;
        free(temp);
    }
}

int main(int ac, char **av, char**env)
{
    // init
    t_cmd   *cmd;
    t_cmd   *temp;

    int begin = 1;
    int end = 1;
    int result = 0;
    int pipe = 0;

    // parse
    while (end < ac)
    {
        if (is_cmd_end(ac, av, end))
        {
            if (!strcmp(av[end], "|"))
                pipe = 1;
            else if (!strcmp(av[end], ";"))
                pipe = 0;
            else {
                pipe = 0;
                end++;
            }
            if (end - begin != 0) {
                temp = init_cmd(temp, &av[begin], end - begin, pipe);
                if (!cmd)
                    cmd = temp;
            }
            begin = end + 1;
        }
        end++;
    }
    result = exec_cmd(cmd, env);
    clear_cmd(cmd);
    return (result);
}
