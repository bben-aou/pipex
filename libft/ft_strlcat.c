/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:30:27 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/07 20:09:19 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	j = dest_len;
	if (dstsize <= dest_len)
		return (src_len + dstsize);
	else
	{
		while (src[i] && dest_len + i < dstsize - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
	}
	dst[j] = '\0';
	return (dest_len + src_len);
}
