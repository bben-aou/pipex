/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:31:41 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/07 19:08:10 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	int				j;
	char			*ptr;
	unsigned char	a;

	i = 0;
	j = -1;
	if (!str)
		return (NULL);
	a = (unsigned char) c;
	ptr = (char *)str;
	if (c == 0)
		return (ptr + ft_strlen(str));
	while (ptr[i])
	{
		if (ptr[i] == a)
			j = i;
		i++;
	}
	if (j != -1)
		return ((char *)(ptr + j));
	else
		return (NULL);
}
