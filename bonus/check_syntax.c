/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:15:47 by virsnp00x         #+#    #+#             */
/*   Updated: 2022/01/07 04:25:57 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_sytx(int n, int statusHD)
{
	if (statusHD == 1)
	{
		if (n < 6)
		{
			write(2, "ERR Syntax\n", 12);
			exit (1);
		}
	}
	if (statusHD == 0)
	{
		if (n < 5)
		{
			write(2, "ERR Syntax\n", 12);
			exit (2);
		}
	}
}
