/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:25:07 by ovirchen          #+#    #+#             */
/*   Updated: 2017/11/14 17:25:08 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

char	**s_vertic(int side, int num_fig)
{
	char	**new_matrix;
	int		n;
	int		i;
	int		poz;

	i = -1;
	poz = 0;
	n = (side - 2) * (side - 1);
	new_matrix = create_part_matrix(side, num_fig, n);
	if (!new_matrix)
		return (NULL);
	while (++i < n)
	{
		poz++;
		if (poz % side == 0)
			poz++;
		new_matrix[i][poz] = '1';
		new_matrix[i][poz + side] = '1';
		new_matrix[i][poz + side + 1] = '1';
		new_matrix[i][poz + 2 * side + 1] = '1';
	}
	return (new_matrix);
}

char	**t_vertic_right(int side, int num_fig)
{
	char	**new_matrix;
	int		n;
	int		i;
	int		poz;

	i = -1;
	poz = 0;
	n = (side - 2) * (side - 1);
	new_matrix = create_part_matrix(side, num_fig, n);
	if (!new_matrix)
		return (NULL);
	while (++i < n)
	{
		poz++;
		if (poz % side == 0)
			poz++;
		new_matrix[i][poz] = '1';
		new_matrix[i][poz + side] = '1';
		new_matrix[i][poz + side + 1] = '1';
		new_matrix[i][poz + 2 * side] = '1';
	}
	return (new_matrix);
}

char	**t_vertic_left(int side, int num_fig)
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
		if (poz % side == 0)
			poz++;
		new_matrix[i][poz] = '1';
		new_matrix[i][poz + 1] = '1';
		new_matrix[i][poz - side + 1] = '1';
		new_matrix[i][poz + side + 1] = '1';
	}
	return (new_matrix);
}

char	**t_horiz(int side, int num_fig)
{
	char	**new_matrix;
	int		n;
	int		i;
	int		poz;

	i = -1;
	poz = 0;
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
		new_matrix[i][poz + 2] = '1';
		new_matrix[i][poz + side + 1] = '1';
	}
	return (new_matrix);
}

char	**t_revers(int side, int num_fig)
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
		new_matrix[i][poz + 2] = '1';
		new_matrix[i][poz - side + 1] = '1';
	}
	return (new_matrix);
}
