/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:42:46 by virsnp00x         #+#    #+#             */
/*   Updated: 2022/01/07 06:21:29 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct my_bonuspipex
{
	char	*path;
	char	**command_paths;
	char	**command_args;
	char	*command;
	int		n_command;
	int		infile;
	int		outfile;
	int		pid;
	int		*pipe;
	int		n_pipe;
	int		status_heredoc;
	int		count_id;
}t_pipex;

void	check_sytx(int n, int statusHD);
void	message_err(char *str);
void	here_doc(char *argv, t_pipex *my_pipex);
char	*get_path(char **env);
void	proc(t_pipex my_pipe, char **argv, char **env);
void	creat_pipes(t_pipex *my_pipe);
void	close_pipes(t_pipex *my_pipe);
void	free_pipe(t_pipex *my_pipe);
void	free_parent(t_pipex *my_pipe);
void	free_proc(t_pipex *my_pipe);

#endif