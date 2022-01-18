/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:15:40 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/07 19:12:08 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc( size_t num, size_t size )
{
	void	*ptr;
	size_t	s;

	s = num * size;
	ptr = (void *)malloc(s);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, s);
	return (ptr);
}
