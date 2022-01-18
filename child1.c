/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:59:08 by virsnp00x         #+#    #+#             */
/*   Updated: 2022/01/07 04:40:26 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_proc(t_pipex *my_pipe)
{
	int	i;

	i = 0;
	while (my_pipe->command_args[i])
	{
		free(my_pipe->command_args[i]);
		i++;
	}
	free(my_pipe->command_args);
	free(my_pipe->command);
}

static char	*get_command(char **path, char *command_arg)
{
	char	*command;
	char	*temp_path;
	int		status;

	while (*path != NULL)
	{
		temp_path = ft_strjoin(*path, "/");
		command = ft_strjoin(temp_path, command_arg);
		free(temp_path);
		status = access(command, 0);
		if (status == 0)
			return (command);
		free (command);
		path++;
	}
	return (NULL);
}

void	first_child(t_pipex pipe, char **argv, char **env)
{
	dup2(pipe.fd[1], 1);
	close(pipe.fd[0]);
	dup2(pipe.infile, 0);
	pipe.command_args = ft_split(argv[2], ' ');
	pipe.command = get_command(pipe.command_paths, pipe.command_args[0]);
	if (!(pipe.command))
	{
		free_proc(&pipe);
		ft_merror("ERR Command ");
	}
	execve(pipe.command, pipe.command_args, env);
}
