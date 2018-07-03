/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:51:26 by ovirchen          #+#    #+#             */
/*   Updated: 2017/12/09 15:53:44 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

static int	chk_hesh(char *tet, int i, int count_hesh)
{
	int count;
	int j;

	if (count_hesh != 4 || (i != 20))
		return (0);
	count = 0;
	j = i;
	while (i-- >= 0)
		if (tet[i] == '#')
		{
			if (i > 4 && tet[i - 5] == '#')
				count++;
			if (i < j - 4 && tet[i + 5] == '#')
				count++;
			if (i > 0 && tet[i - 1] == '#')
				count++;
			if (i < j && tet[i + 1] == '#')
				count++;
		}
	if (count < 6)
		return (0);
	else
		return (1);
}

int			check_tetriminos(char *tet)
{
	int i;
	int lines;
	int count_hesh;

	while (*tet)
	{
		i = -1;
		lines = 0;
		count_hesh = 0;
		while (tet[++i] && lines != 4)
			if (tet[i] == '#' && count_hesh != 4)
				count_hesh++;
			else if (tet[i] == '\n')
				lines++;
			else if (tet[i] != '.')
				return (0);
		if (chk_hesh(tet, i, count_hesh) == 0 || tet[i] == '.' || tet[i] == '#')
			return (0);
		if (tet[i] == '\0')
			return (1);
		else if (tet[i] == '\n' && (tet += i + 1))
			if (*tet == '\0')
				return (0);
	}
	return (1);
}
