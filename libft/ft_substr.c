/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:32:17 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/07 19:09:17 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	last;
	char	*str;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	last = 0;
	if (start < slen)
		last = slen - start ;
	if (last > len)
		last = len;
	str = (char *)malloc(sizeof(char) *(last + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)(s + start), last + 1);
	return (str);
}
