/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:25:31 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/07 18:56:38 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dest1;
	unsigned char	*src2;

	i = 0;
	dest1 = (unsigned char *) dest;
	src2 = (unsigned char *) src;
	if (dest == src || src == 0)
		return (dest);
	while (i < n)
	{
		dest1[i] = src2[i];
		i++;
	}
	dest = (void *) dest1;
	return (dest);
}
