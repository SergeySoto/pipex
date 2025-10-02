/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:47:59 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/10/02 18:34:40 by ssoto-su         ###   ########.fr       */
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
	//prints
	print_array(pipex.env_path);
	ft_pf_putstr("deberia salir el path abajo\n");
	ft_pf_putstr(pipex.path1);
	ft_pf_putchar('\n');
	ft_pf_putstr(pipex.path2);
	ft_pf_putchar('\n');
	//frees
	free_all(pipex.env_path, NULL);
	free_all(pipex.cmd1, NULL);
	free_all(pipex.cmd2, NULL);
	free_all(NULL ,pipex.path1);
	free_all(NULL ,pipex.path2);
	
	return (0);
}
