/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:47:59 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/10/04 00:28:29 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipex;
	
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
	return (father(&pipex, envp));
}
