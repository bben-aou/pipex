/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:25:57 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/07 18:57:46 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset( void *str, int rb, size_t unt)
{
	unsigned int	i;
	unsigned char	*str2;

	i = 0;
	str2 = (unsigned char *) str;
	while (i < unt)
	{
		str2[i] = (unsigned char) rb;
		i++;
	}
	str = (void *)str2;
	return (str);
}
