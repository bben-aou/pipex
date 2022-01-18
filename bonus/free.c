/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:59:13 by virsnp00x         #+#    #+#             */
/*   Updated: 2022/01/07 04:27:39 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_pipe(t_pipex *my_pipe)
{
	close(my_pipe->infile);
	close(my_pipe->outfile);
	if ((my_pipe->status_heredoc) == 1)
		unlink(".heredoc");
	free(my_pipe->pipe);
	message_err("ERR env ");
}

void	free_parent(t_pipex *my_pipe)
{
	int	i;

	i = 0;
	close(my_pipe->infile);
	close(my_pipe->outfile);
	if (my_pipe->status_heredoc)
		unlink(".heredoc_tmp");
	while (my_pipe->command_paths[i])
	{
		free(my_pipe->command_paths[i]);
		i++;
	}
	free(my_pipe->command_paths);
	free(my_pipe->pipe);
}

void	free_proc(t_pipex *my_pipe)
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
