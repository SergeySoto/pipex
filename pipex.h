/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:59:39 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/27 15:59:39 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
# include <string.h>
# include <sys/wait.h>

typedef struct t_pipe
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd2;
	char	*cmd1;
	char	**path1;
	char	**path2;
	char	**env_path;
	int		status_error;
}			t_pipe;

void	pipe_init(int argc, char **argv);
char	*find_paths(char** envp);


#endif