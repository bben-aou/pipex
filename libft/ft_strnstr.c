/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:55:50 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/07 20:20:12 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char*t_s, size_t n)
{
	size_t	i;
	size_t	j;
	int		temp;

	i = 0;
	j = 0;
	if (t_s[0] == '\0')
		return ((char *)src);
	while (src[i] && i < n)
	{
		if (src[i] == t_s[0])
		{
			temp = i;
			while (src[i + j] == t_s[j] && i + j < n)
			{
				if (t_s[j + 1] == '\0')
					return ((char *)src + temp);
					j++;
			}
			temp = 0;
		}
		i++;
	}
	return (NULL);
}
