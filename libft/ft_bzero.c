/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:15:15 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/07 19:11:57 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero( void *str, size_t unt)
{
	unsigned int	i;
	unsigned char	*str2;

	i = 0;
	if (!str)
		return ;
	str2 = (unsigned char *) str;
	while (i < unt)
	{
		str2[i] = '\0';
		i++;
	}
}
