/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:29:11 by virsnp00x         #+#    #+#             */
/*   Updated: 2022/01/07 05:13:18 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_path(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

void	message_err(char *str)
{
	perror(str);
	exit(1);
}

void	close_pipes(t_pipex *my_pipe)
{
	int	i;

	i = 0;
	while (i < (my_pipe->n_pipe))
	{
		close(my_pipe->pipe[i]);
		i++;
	}
}

void	creat_pipes(t_pipex *my_pipe)
{
	int	i;

	i = 0;
	while (i < my_pipe->n_command - 1)
	{
		if (pipe(my_pipe->pipe + 2 * i) < 0)
			free_parent(my_pipe);
		i++;
	}
}
