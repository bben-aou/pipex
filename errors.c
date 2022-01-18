/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:16:43 by bben-aou          #+#    #+#             */
/*   Updated: 2022/01/07 04:12:48 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_message(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

int	ft_merror(char *str)
{
	perror(str);
	exit(1);
}
