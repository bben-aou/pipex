/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:15:54 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/07 18:49:52 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum( int arg)
{
	if (ft_isalpha(arg) == 1 || ft_isdigit(arg) == 1)
		return (1);
	else
		return (0);
}