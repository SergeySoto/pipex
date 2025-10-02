/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:33:56 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/10/02 18:33:56 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipe	pipe_init(int argc)
{
	t_pipe	pipex;

	if (argc != 5)
		printf_error("Lack of arguments\n", 1);
	pipex.infile = -1;
	pipex.outfile = -1;
	pipex.pipefd[0] = -1;
	pipex.pipefd[1] = -1;
	pipex.pid1 = -1;
	pipex.pid2 = -1;
	pipex.cmd1 = NULL;
	pipex.cmd2 = NULL;
	pipex.path1 = NULL;
	pipex.path2 = NULL;
	pipex.env_path = NULL;
	pipex.status_error = 0;
	return (pipex);
}

void	find_paths(char** envp, t_pipe *pipex)
{
	int	i;
	char	*path_found;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_found = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!path_found || !envp[0])
		printf_error("Environment path not found\n", 1);
	else
		pipex->env_path = ft_split(path_found, ':');
	return ;
}

void	set_cmd(char **argv, t_pipe *pipex)
{
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd2 = ft_split(argv[3], ' ');
	pipex->path1 = find_command(pipex->cmd1[0], pipex->env_path);
	pipex->path2 = find_command(pipex->cmd2[0], pipex->env_path);
}

char	*find_command(char *cmd, char **env_path)
{
	int		i;
	char	*aux;
	char	*full_path;

	i = 0;
	full_path = NULL;
	while (env_path[i])
	{
		aux = ft_strjoin(env_path[i], "/");
		full_path = ft_strjoin(aux, cmd);
		free(aux);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free_all(NULL, full_path);
		i++;
	}
	return (NULL);
}

void	set_infile(t_pipe *pipex, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		printf_error("Error: Fail opening infile\n", 1);
	
}

void	set_outfile(t_pipe *pipex, char **argv)
{
	pipex->outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (pipex->outfile < 0)
	{
		close(pipex->infile);
		printf_error("Error: Fail opening outfile\n", 1);
	}
}

void	set_pipe(t_pipe *pipex)
{
	if (pipe(pipex->pipefd) == -1)
	{
		close(pipex->infile);
		close(pipex->outfile);
		printf_error("Error: Construction pipe failed\n", 1);
	}
}
