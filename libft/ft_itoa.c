/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:24:21 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/07 19:14:40 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*ptr;

	i = ft_len(n);
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	ptr[i--] = '\0';
	if (n == 0)
	{
		ptr[0] = '0';
		return (ptr);
	}
	if (n < 0)
		ptr[0] = '-';
	while (n != 0)
	{
		if (ptr[0] == '-')
			ptr[i--] = '0' + -(n % 10);
		else
			ptr[i--] = '0' + (n % 10);
		n = n / 10;
	}
	return (ptr);
}
