/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:31:30 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/07 20:10:36 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*tab1;
	unsigned char	*tab2;

	tab1 = (unsigned char *) str1;
	tab2 = (unsigned char *) str2;
	i = 0;
	if (n == 0)
		return (0);
	while (tab1[i] && tab2[i] && (i < n - 1) && (tab1[i] == tab2[i]))
	{
			i++;
	}
	return (tab1[i] - tab2[i]);
}
