/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:47:59 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/10/01 14:40:59 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipe	pipe_init(int argc)
{
	t_pipe	pipex;

	if (argc != 5)
	{
		ft_printf("caca\n");
	}
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
		return ;
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
	while (env_path[i])
	{
		aux = ft_strjoin(env_path[i], "/");
		full_path = ft_strjoin(aux, cmd);
		free(aux);
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	t_pipe	pipex;
	
	pipex = pipe_init(argc);
	find_paths(envp, &pipex);
	set_cmd(argv, &pipex);

	//prints
	print_array(pipex.env_path);
	ft_pf_putstr("deberia salir el path abajo\n");
	ft_pf_putstr(pipex.path1);
	ft_pf_putstr(pipex.path2);
	//frees
	free_all(pipex.env_path, NULL);
	free_all(pipex.cmd1, NULL);
	free_all(pipex.cmd2, NULL);
	free_all(NULL ,pipex.path1);
	free_all(NULL ,pipex.path2);
	
	return (0);
}
