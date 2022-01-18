/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:32:03 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/07 19:09:06 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		debut;
	int		fin;
	int		i;

	i = 0;
	debut = 0;
	if (!s1 || !set)
		return (NULL);
	fin = (int)ft_strlen(s1);
	while (s1[debut] && ft_strchr(set, (int ) s1[debut]) != NULL)
		debut++;
	while (fin > debut && ft_strchr(set, (int ) s1[fin - 1]) != NULL)
		fin--;
	str = (char *)malloc(sizeof(char) * (fin - debut + 1));
	if (!str)
		return (0);
	while (debut < fin)
	{
		str[i] = s1[debut];
		i++;
		debut++;
	}
	str[i] = '\0';
	return (str);
}
