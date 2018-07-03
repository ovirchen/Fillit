/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_1_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:33:13 by ovirchen          #+#    #+#             */
/*   Updated: 2017/12/09 15:46:59 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

char	**create_part_matrix(int side, int num_fig, int n)
{
	char	**part_matrix;
	int		i;
	int		j;

	i = -1;
	part_matrix = (char**)malloc(sizeof(char*) * (n + 1));
	if (!part_matrix)
		return (NULL);
	part_matrix[n] = 0;
	while (++i < n)
	{
		j = 0;
		part_matrix[i] = (char*)malloc(sizeof(char) * (side * side + 2));
		if (!part_matrix[i])
			return (NULL);
		part_matrix[i][j] = 64 + num_fig;
		while (++j < side * side + 1)
			part_matrix[i][j] = '.';
		part_matrix[i][j] = '\0';
	}
	part_matrix[i] = 0;
	return (part_matrix);
}

char	**sq(int side, int num_fig)
{
	char	**new_matrix;
	int		n;
	int		i;
	int		poz;

	i = -1;
	poz = 0;
	n = (side - 1) * (side - 1);
	new_matrix = create_part_matrix(side, num_fig, n);
	if (!new_matrix)
		return (NULL);
	while (++i < n)
	{
		poz++;
		if ((poz % side == 0) && poz + side < side * side)
			poz++;
		new_matrix[i][poz] = '1';
		new_matrix[i][poz + 1] = '1';
		new_matrix[i][poz + side] = '1';
		new_matrix[i][poz + side + 1] = '1';
	}
	return (new_matrix);
}

char	**i_vertic(int side, int num_fig)
{
	char	**new_matrix;
	int		n;
	int		i;
	int		poz;

	i = -1;
	poz = 0;
	n = (side - 3) * side;
	new_matrix = create_part_matrix(side, num_fig, n);
	if (!new_matrix)
		return (NULL);
	while (++i < n)
	{
		poz++;
		new_matrix[i][poz] = '1';
		new_matrix[i][poz + side] = '1';
		new_matrix[i][poz + 2 * side] = '1';
		new_matrix[i][poz + 3 * side] = '1';
	}
	return (new_matrix);
}

char	**i_horiz(int side, int num_fig)
{
	char	**new_matrix;
	int		n;
	int		i;
	int		poz;

	i = -1;
	poz = 0;
	n = (side - 3) * side;
	new_matrix = create_part_matrix(side, num_fig, n);
	if (!new_matrix)
		return (NULL);
	while (++i < n)
	{
		poz++;
		if (((poz + 2) % side == 0) && poz + 3 < side * side)
			poz += 3;
		new_matrix[i][poz] = '1';
		new_matrix[i][poz + 1] = '1';
		new_matrix[i][poz + 2] = '1';
		new_matrix[i][poz + 3] = '1';
	}
	return (new_matrix);
}

char	**s_horiz(int side, int num_fig)
{
	char	**new_matrix;
	int		n;
	int		i;
	int		poz;

	i = -1;
	poz = side;
	n = (side - 2) * (side - 1);
	new_matrix = create_part_matrix(side, num_fig, n);
	if (!new_matrix)
		return (NULL);
	while (++i < n)
	{
		poz++;
		if ((poz + 1) % side == 0)
			poz += 2;
		new_matrix[i][poz] = '1';
		new_matrix[i][poz + 1] = '1';
		new_matrix[i][poz - side + 1] = '1';
		new_matrix[i][poz - side + 2] = '1';
	}
	return (new_matrix);
}
