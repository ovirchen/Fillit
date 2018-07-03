/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:06:51 by ovirchen          #+#    #+#             */
/*   Updated: 2017/12/09 15:53:23 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

int		count_figures(int *mas_figures)
{
	int i;

	i = 0;
	while (mas_figures[i])
		i++;
	return (i);
}

void	list_add(t_list **begin, int i, int fig)
{
	t_list	*elem;
	t_list	*list;

	elem = (t_list*)malloc(sizeof(t_list));
	elem->matrix = (char**)malloc(sizeof(char*)
						* (ft_size_matrix(fig, g_side) + 1));
	if (!elem || !elem->matrix)
		return ;
	elem->matrix = new_figure_matrix(fig, g_side, i + 1);
	elem->cnt = ft_cntelem(elem->matrix);
	elem->number = i + 1;
	elem->figure = fig;
	elem->next = NULL;
	elem->prev = NULL;
	if (*begin == NULL)
		*begin = elem;
	else
	{
		list = *begin;
		while (list->next)
			list = list->next;
		list->next = elem;
		list->next->prev = list;
	}
}

void	print_list(t_list *begin)
{
	int i;
	int j;

	while (begin)
	{
		i = -1;
		while (begin->matrix[++i])
		{
			j = -1;
			while (begin->matrix[i][++j])
				write(1, &begin->matrix[i][j], 1);
			write(1, "\n", 1);
		}
		begin = begin->next;
	}
}
