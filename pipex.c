/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:47:59 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/29 17:48:52 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipe	pipe_init(int argc, char **argv)
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
		if (ft_strncmp(envp[i], "PATH=", 5) == 0);
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipex;
	char	*string;

	
	pipex = pipe_init(argc, argv);
	string = find_paths(envp);
	if (!pipex.env_path || !envp[0])
		return (NULL);
	else
		
	return (0);
}
