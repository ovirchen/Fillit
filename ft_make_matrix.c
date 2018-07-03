/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:35:07 by ovirchen          #+#    #+#             */
/*   Updated: 2017/12/09 15:48:49 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

static char		**figure_1_10(int figure, int side, int num_fig)
{
	if (figure == 1)
		return (sq(side, num_fig));
	else if (figure == 2)
		return (i_vertic(side, num_fig));
	else if (figure == 3)
		return (i_horiz(side, num_fig));
	else if (figure == 4)
		return (s_horiz(side, num_fig));
	else if (figure == 5)
		return (s_vertic(side, num_fig));
	else if (figure == 6)
		return (t_vertic_right(side, num_fig));
	else if (figure == 7)
		return (t_vertic_left(side, num_fig));
	else if (figure == 8)
		return (t_horiz(side, num_fig));
	else if (figure == 9)
		return (t_revers(side, num_fig));
	else
		return (j_revers(side, num_fig));
}

static char		**figure_11_19(int figure, int side, int num_fig)
{
	if (figure == 11)
		return (j_horiz(side, num_fig));
	else if (figure == 12)
		return (j_vertic(side, num_fig));
	else if (figure == 13)
		return (j_horiz_revers(side, num_fig));
	else if (figure == 14)
		return (l_revers(side, num_fig));
	else if (figure == 15)
		return (l_horiz_revers(side, num_fig));
	else if (figure == 16)
		return (l_vertic(side, num_fig));
	else if (figure == 17)
		return (l_horiz(side, num_fig));
	else if (figure == 18)
		return (z_horiz(side, num_fig));
	else
		return (z_vertic(side, num_fig));
}

char			**new_figure_matrix(int figure, int side, int num_fig)
{
	if (figure >= 1 && figure <= 10)
		return (figure_1_10(figure, side, num_fig));
	else if (figure <= 19)
		return (figure_11_19(figure, side, num_fig));
	return (NULL);
}

t_list			*ft_big_matrix(int *mas_figures)
{
	int		i;
	t_list	*big_matrix;

	i = -1;
	big_matrix = (t_list*)malloc(sizeof(t_list));
	if (!big_matrix)
		return (NULL);
	big_matrix = NULL;
	while (mas_figures[++i])
		list_add(&big_matrix, i, mas_figures[i]);
	return (big_matrix);
}

t_list			*ft_make_big_matrix(char *str)
{
	int		*mas_figures;

	mas_figures = ft_mas_figures(str);
	return (ft_big_matrix(mas_figures));
}
