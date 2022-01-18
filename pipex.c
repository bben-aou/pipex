/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:48:10 by bben-aou          #+#    #+#             */
/*   Updated: 2022/01/07 04:40:54 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(char **env)
{
	char	*str;

	while (ft_strncmp("PATH", *env, 4))
		env++;
	str = (*env + 5);
	return (str);
}

static void	end_pipe(t_pipex *pipe)
{
	close(pipe->fd[0]);
	close(pipe->fd[1]);
}

static void	free_pp(t_pipex *my_pipe)
{
	int	i;

	i = 0;
	close(my_pipe->infile);
	close(my_pipe->outfile);
	while (my_pipe->command_paths[i])
	{
		free(my_pipe->command_paths[i]);
		i++;
	}
	free(my_pipe->command_paths);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	my_pipe;

	if (argc != 5)
		return (ft_message("Error Arguments \n"));
	my_pipe.infile = open(argv[1], O_RDONLY);
	my_pipe.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (my_pipe.infile < 0)
		return (ft_merror("Error Infile "));
	if (my_pipe.outfile < 0)
		return (ft_merror("Error Outfile "));
	if (pipe(my_pipe.fd) < 0)
		return (ft_merror("Error pipe "));
	my_pipe.path = get_path(env);
	my_pipe.command_paths = ft_split(my_pipe.path, ':');
	my_pipe.first_pid = fork();
	if (my_pipe.first_pid == 0)
		first_child (my_pipe, argv, env);
	my_pipe.second_pid = fork();
	if (my_pipe.second_pid == 0)
		second_child (my_pipe, argv, env);
	end_pipe(&my_pipe);
	waitpid(my_pipe.first_pid, NULL, 0);
	waitpid(my_pipe.second_pid, NULL, 0);
	free_pp(&my_pipe);
	return (0);
}
