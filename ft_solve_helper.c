/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:45:06 by pprivalo          #+#    #+#             */
/*   Updated: 2017/12/09 16:03:53 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

int		ft_cntelem(char **mas)
{
	int		cnt;

	cnt = 0;
	while (mas[cnt])
		cnt++;
	return (cnt);
}

int		ft_prev(t_list *list, t_list *head, char **mas, int num)
{
	list->prev->matrix++;
	mas[ft_cntelem(mas) - 1] = NULL;
	return (ft_alg(list->prev, head, mas, num));
}

void	ft_clean_arr(char **mas, int num)
{
	int		i;

	i = -1;
	while (++i < num)
		mas[i] = NULL;
}

int		ft_incriment(t_list *head, char **mas, int num, int incside)
{
	if (incside)
		g_side++;
	ft_clean_arr(mas, num + 1);
	head = ft_big_matrix(ft_mas_figures(g_str2));
	return (ft_alg(head, head, mas, num));
}
