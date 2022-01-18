/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:53:14 by virsnp00x         #+#    #+#             */
/*   Updated: 2022/01/07 06:25:57 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

static void	ft_duplicate(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

static void	error_pipe(char *arg)
{
	write(2, "Command not found", ft_strlen("Command not found"));
	write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
}

void	proc(t_pipex my_pipe, char **argv, char **env)
{
	my_pipe.pid = fork();
	if (!my_pipe.pid)
	{
		if (my_pipe.count_id == 0)
			ft_duplicate(my_pipe.infile, my_pipe.pipe[1]);
		else if (my_pipe.count_id == my_pipe.n_command - 1)
			ft_duplicate(my_pipe.pipe[2 * my_pipe.count_id - 2],
				my_pipe.outfile);
		else
			ft_duplicate(my_pipe.pipe[2 * my_pipe.count_id - 2],
				my_pipe.pipe[2 * my_pipe.count_id + 1]);
		close_pipes(&my_pipe);
		my_pipe.command_args = ft_split(argv
			[2 + my_pipe.status_heredoc + my_pipe.count_id], ' ');
			my_pipe.command = get_command(my_pipe.command_paths,
				my_pipe.command_args[0]);
		if (!my_pipe.command)
		{
			error_pipe(my_pipe.command_args[0]);
			free_proc(&my_pipe);
			exit(1);
		}
		execve(my_pipe.command, my_pipe.command_args, env);
	}
}
