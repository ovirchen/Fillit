/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:42:21 by pprivalo          #+#    #+#             */
/*   Updated: 2017/12/09 16:02:44 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

static int	ft_cmpr_row(char **mas, char *row, size_t cnt)
{
	size_t	i;
	size_t	j;

	j = -1;
	if (!mas[0])
		return (1);
	while (++j < cnt)
	{
		i = -1;
		while (mas[j][++i])
		{
			if (row[i] == 49 && mas[j][i] == 49)
				return (0);
		}
	}
	return (1);
}

static int	ft_check_node(char ***matrix, char **mas, int len)
{
	int		j;
	int		cnt;

	cnt = ft_cntelem(mas);
	j = 0;
	while (**matrix)
	{
		if (ft_cmpr_row(mas, **matrix, cnt))
		{
			mas[cnt] = **matrix;
			return (1);
		}
		(*matrix)++;
	}
	*matrix = (*matrix) - len;
	return (0);
}

void		ft_write_first(char **mas, t_list *buf, size_t first)
{
	t_list	*head;

	head = buf;
	while (first--)
		buf = buf->next;
	mas[0] = buf->matrix[0];
	buf = head;
}

int			ft_alg(t_list *list, t_list *head, char **mas, int num)
{
	if (ft_check_node(&(list->matrix), mas, list->cnt))
	{
		if (list->next)
			return (ft_alg(list->next, head, mas, num));
		else
			return (1);
	}
	else
	{
		if (list->prev && list->figure != list->prev->figure)
			return (ft_prev(list, head, mas, num));
		else
		{
			if (g_first == num - 1)
			{
				g_first = 0;
				return (ft_incriment(head, mas, num, 1));
			}
			else
			{
				g_first++;
				return (ft_incriment(head, mas, num, 0));
			}
		}
	}
}

char		**ft_solve(const t_list *list, int num)
{
	char	**mas;
	t_list	*buf;
	int		i;

	i = -1;
	mas = (char **)malloc(sizeof(char *) * (num + 1));
	ft_clean_arr(mas, num + 1);
	buf = (t_list *)list;
	ft_alg(buf, (t_list *)list, mas, num);
	return (mas);
}
