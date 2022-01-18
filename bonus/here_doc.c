/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:55:38 by virsnp00x         #+#    #+#             */
/*   Updated: 2022/01/07 07:06:53 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	print(int temp, char *line)
{
	write(temp, line, ft_strlen(line));
	write(1, "\n", 1);
}

void	here_doc(char *argv, t_pipex *my_pipe)
{
	char	*line;
	int		temp ;

	temp = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (temp < 0)
		message_err("ERR Here_doc ");
	while (1)
	{
		write(1, "here_doc >", 10);
		line = get_next_line(0);
		if (line == NULL)
			exit(1);
		if (ft_strncmp(argv, line, ft_strlen(line) - 1) == 0)
			break ;
		print(temp, line);
		free(line);
	}
	free(line);
	close(temp);
	my_pipe->infile = open(".heredoc", O_RDONLY);
	if ((my_pipe->infile) < 0)
	{
		unlink(".heredoc");
		message_err("ERR Here_doc");
	}
}
