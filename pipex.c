/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:47:59 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/10/04 00:36:15 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipex;
	int		result;

	pipex = pipe_init(argc);
	find_paths(envp, &pipex);
	set_cmd(argv, &pipex);
	//errors control
	if (!pipex.path1)	
		printf_error(pipex.cmd1[0], 126);
	if (!pipex.path2)	
		printf_error(pipex.cmd2[0], 126);
	set_files(&pipex, argv);
	set_pipe(&pipex);
	result = father(&pipex, envp);
	ultimate_free(&pipex);
	return (result);
}
