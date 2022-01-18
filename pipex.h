/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:35:54 by bben-aou          #+#    #+#             */
/*   Updated: 2022/01/07 04:18:22 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>

typedef struct my_pipex
{
	pid_t	first_pid;
	pid_t	second_pid;
	int		infile;
	int		outfile;
	int		fd[2];
	char	*path;
	char	**command_args;
	char	**command_paths;
	char	*command;
}t_pipex;

int		ft_message(char *str);
int		ft_merror(char *str);
void	first_child(t_pipex my_pipe, char **argv, char **env);
void	second_child(t_pipex my_pipe, char **argv, char **env);

#endif