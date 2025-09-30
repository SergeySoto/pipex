/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:47:59 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/30 18:14:52 by ssoto-su         ###   ########.fr       */
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

char	*find_paths(char** envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0) //linux: "PATH=", 5, windows: "Path", 4
			return (envp[i] + 5); //linux: + 5, windows: + 4
		i++;
	}
	return (NULL);
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
		if (access(full_path, F_OK | R_OK | W_OK | X_OK) == 0)
			return (full_path);
		free(full_path);
		free(aux);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	t_pipe	pipex;
	char	*path_found;
	
	pipex = pipe_init(argc);
	path_found = find_paths(envp);
	if (!path_found || !envp[0])
		return (0);
	else
		pipex.env_path = ft_split(path_found, ':'); //en linux el separador es ':' y en windows es ';'
	set_cmd(argv, &pipex);
	//prints
	print_array(pipex.env_path);
	print_array(pipex.cmd1);
	print_array(pipex.cmd2);
	//frees
	free_array(pipex.env_path);
	free_array(pipex.cmd1);
	free_array(pipex.cmd2);

	return (0);
}
