/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:36:43 by bben-aou          #+#    #+#             */
/*   Updated: 2022/01/07 06:29:30 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_fill_line(int fd, char *svar);
char	*ft_checkline(char *svar);
char	*ft_nextline(char *svar);
char	*ft_strjoing(char *s1, char *s2);
size_t	ft_strleng(char *str);
char	*ft_strchrg(char *s, int c);

#endif
