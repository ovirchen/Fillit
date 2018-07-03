/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mas_figures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:29:28 by ovirchen          #+#    #+#             */
/*   Updated: 2017/12/04 10:11:13 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

static int	check_fig_1(char *str)
{
	if (str[6] == '#')
		if (str[4] == '#')
			return (9);
		else if (str[7] == '#')
			return (13);
		else if (str[10] == '#')
			return (6);
		else
			return (5);
	else if (str[4] == '#')
		if (str[3] == '#')
			return (17);
		else if (str[10] == '#')
			return (7);
		else
			return (19);
	else if (str[9] == '#')
		return (12);
	else if (str[11] == '#')
		return (16);
	else
		return (2);
}

static int	check_fig_2(char *str)
{
	if (str[5] == '#')
		if (str[6] == '#')
			return (1);
		else if (str[4] == '#')
			return (4);
		else
			return (10);
	else if (str[7] == '#')
		return (18);
	return (14);
}

static int	check_fig_3(char *str)
{
	if (str[5] == '#')
		return (15);
	else if (str[6] == '#')
		return (8);
	else
		return (11);
}

static int	ft_element_mas_figures(char *str)
{
	if (str[1] == '#' && str[2] == '#')
	{
		if (str[3] == '#')
			return (3);
		else
			return (check_fig_3(str));
	}
	else if (str[1] == '#')
		return (check_fig_2(str));
	else
		return (check_fig_1(str));
}

int			*ft_mas_figures(char *str)
{
	int *mas;
	int i;
	int count;

	if (!(mas = (int*)malloc(sizeof(int) * (ft_number_figures(str) + 1))))
		return (NULL);
	i = -1;
	count = 0;
	while (*str)
	{
		while (*str && str[0] != '#')
			if (*str++ == '\n')
				count++;
		if (str[0] == '#' && (mas[++i] = ft_element_mas_figures(str)))
		{
			while (*str && count != 4)
				if (*(str++) == '\n')
					count++;
			count = 0;
		}
		if (*str == '\n')
			str++;
	}
	mas[++i] = 0;
	return (mas);
}
