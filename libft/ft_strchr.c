/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:29:04 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/07 18:58:59 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char			*ptr;
	int				i;
	unsigned char	a;

	i = 0;
	a = (unsigned char) c;
	ptr = (char *)str;
	if (a == 0)
		return (ptr + ft_strlen(ptr));
	while (ptr[i])
	{
		if (ptr[i] == a)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
