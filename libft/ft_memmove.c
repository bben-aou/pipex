/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:25:45 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/07 18:57:31 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dest1;
	unsigned char	*src2;

	i = 0;
	dest1 = (unsigned char *) dest;
	src2 = (unsigned char *) src;
	if (dest > src)
	{
		while (n > 0)
		{
			dest1[n - 1] = src2[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			dest1[i] = src2[i];
			i++;
		}
	}
	return (dest);
}
