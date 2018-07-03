/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:30:31 by ovirchen          #+#    #+#             */
/*   Updated: 2017/12/02 19:45:35 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

static char	**ft_change_matrix(char **matrix)
{
	int i;
	int j;

	i = -1;
	while (matrix[++i])
	{
		j = -1;
		while (matrix[i][++j])
			if (matrix[i][j] != '.')
				matrix[i][j] = matrix[i][0];
	}
	i = -1;
	while (matrix[++i])
	{
		j = -1;
		while (matrix[i][(++j) + 1])
			matrix[i][j] = matrix[i][j + 1];
		matrix[i][j] = '\0';
	}
	return (matrix);
}

static char	*ft_make_square(char **matrix, int side)
{
	int		i;
	int		j;
	char	*square;

	i = 0;
	square = (char *)malloc(sizeof(char) * (side * side + 1));
	square = matrix[0];
	while (matrix[++i])
	{
		j = -1;
		while (matrix[i][++j])
			if (matrix[i][j] > 64 && matrix[i][j] < 91)
				square[j] = matrix[i][j];
	}
	return (square);
}

void		ft_print_square(char **matrix, int side)
{
	int		i;
	char	*square;

	square = ft_make_square(ft_change_matrix(matrix), side);
	i = -1;
	while (square[++i])
	{
		write(1, &square[i], 1);
		if ((i + 1) % (side) == 0)
			write(1, "\n", 1);
	}
}
