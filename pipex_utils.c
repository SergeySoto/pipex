/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:28:46 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/29 20:28:46 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_array(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		ft_putstr_fd(argv[i], 1);
		ft_printf("\n");
		i++;
	}
}

void	free_all(char **array, char *chr)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
	if (chr)
	{
		free(chr);
	}
}

void	printf_error(char *msg, int num_error)
{
	if (num_error == 1)
	{
		ft_printf("%s", msg);
		exit(num_error);
	}
	else if (num_error == 126)
	{
		ft_printf("Error: '%s' does not have execution permissions", msg);
		exit(num_error);
	}
	else if (num_error == 127)
	{
		ft_printf("Error: Command '%s' not found", msg);
		exit(num_error);
	}
	else
		ft_printf("%s", msg);
}
