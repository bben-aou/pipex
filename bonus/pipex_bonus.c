/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:42:26 by virsnp00x         #+#    #+#             */
/*   Updated: 2022/01/07 06:24:05 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	ft_checkherdoc(char *str, t_pipex *my_pipe)
{
	if (!ft_strncmp("here_doc", str, 9) && str)
	{
		my_pipe->status_heredoc = 1;
		return (1);
	}
	else
	{
		my_pipe->status_heredoc = 0;
		return (0);
	}
}

static void	creation(char **argv, t_pipex *pipe, int argc)
{
	if (pipe->status_heredoc == 1)
	{
		pipe->outfile
			= open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	}
	else
		pipe->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
}

static void	get_files(char **argv, t_pipex *pipe, int argc)
{
	int	i;

	i = 1;
	while (i == 1)
	{
		if ((pipe->status_heredoc) == 1)
			here_doc(argv[2], pipe);
		else
		{
			pipe->infile = open(argv[1], O_RDONLY);
			if ((pipe->infile) < 0)
				message_err ("Infile ");
		}
		i = 0;
	}
	while (i == 0)
	{
		creation(argv, pipe, argc);
		if (pipe->outfile < 0)
			message_err ("Outfile ");
		i = 2;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	my_pipe;

	check_sytx(argc, ft_checkherdoc(argv[1], &my_pipe));
	get_files(argv, &my_pipe, argc);
	my_pipe.n_command = argc - 3 - my_pipe.status_heredoc;
	my_pipe.n_pipe = 2 * (my_pipe.n_command - 1);
	my_pipe.pipe = (int *)malloc(sizeof(int) * my_pipe.n_pipe);
	if (!(my_pipe.pipe))
		message_err("ERR Pipe ");
	my_pipe.path = get_path(env);
	my_pipe.command_paths = ft_split(my_pipe.path, ':');
	if (!(my_pipe.command_paths))
		free_pipe(&my_pipe);
	creat_pipes(&my_pipe);
	my_pipe.count_id = -1;
	while (++(my_pipe.count_id) < my_pipe.n_command)
		proc(my_pipe, argv, env);
	close_pipes (&my_pipe);
	waitpid(-1, NULL, 0);
	free_parent(&my_pipe);
	return (0);
}
