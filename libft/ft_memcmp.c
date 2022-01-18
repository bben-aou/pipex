/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:25:00 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/07 18:56:15 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*tab1;
	unsigned char	*tab2;
	size_t			i;

	if (n == 0)
		return (0);
	tab1 = (unsigned char *)str1;
	tab2 = (unsigned char *)str2;
	i = 0;
	while (i < n - 1 && tab1[i] == tab2[i])
	{
		i++;
	}
	return ((tab1[i] - tab2[i]));
}
