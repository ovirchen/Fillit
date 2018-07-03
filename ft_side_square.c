/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_side_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:38:39 by ovirchen          #+#    #+#             */
/*   Updated: 2017/12/09 15:56:07 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int		ft_number_figures(char *str)
{
	return ((ft_strlen(str) - 20) / 21 + 1);
}

int		ft_side_square(int *mas_figures)
{
	int		side;
	int		f;
	int		i;

	side = 2;
	i = -1;
	while (mas_figures[++i])
	{
		if (mas_figures[i] != 1)
			side = 3;
		if (mas_figures[i] == 2 || mas_figures[i] == 3)
		{
			side = 4;
			break ;
		}
	}
	f = ft_number_figures(g_str2);
	while (side * side < f * 4)
		side++;
	return (side);
}

int		ft_size_matrix(int figure, int side)
{
	if (figure == 1)
		return ((side - 1) * (side - 1));
	else if (figure == 2 || figure == 3)
		return ((side - 3) * side);
	else
		return ((side - 2) * (side - 1));
}
