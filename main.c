/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:34:11 by ovirchen          #+#    #+#             */
/*   Updated: 2017/12/09 16:03:09 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

static int	ft_error(void)
{
	write(1, "error\n", 6);
	return (1);
}

static int	ft_usage(void)
{
	write(1, "usage: fillit source_file\n", 26);
	return (0);
}

static char	*bigger_str(char *str)
{
	size_t			len;
	size_t			i;
	char			*big_str;

	len = ft_strlen(str);
	big_str = (char*)malloc(sizeof(char) * (len + 21));
	if (big_str)
	{
		i = 0;
		while (i < len)
		{
			big_str[i] = str[i];
			i++;
		}
		free(str);
	}
	return (big_str);
}

static char	*write_str(int fd)
{
	size_t	i;
	int		ret;
	char	buf;
	char	*str;

	str = (char*)malloc(sizeof(char) * 22);
	if (!str)
		return (NULL);
	i = 0;
	while ((ret = read(fd, &buf, 1)))
	{
		if (ret == -1 || i > 546)
			return (NULL);
		str[i] = buf;
		i++;
		if (((i - 22) % 21 == 0 && i > 22) || i == 22)
		{
			str[i] = '\0';
			str = bigger_str(str);
			if (!str)
				return (NULL);
		}
	}
	str[i] = '\0';
	return (str);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_list	*list;
	int		*mas_figures;
	char	**solve;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1 &&
			(g_str2 = write_str(fd)) != NULL)
		{
			if (!ft_strlen(g_str2) || check_tetriminos(g_str2) == 0)
				return (ft_error());
			mas_figures = ft_mas_figures(g_str2);
			g_side = ft_side_square(mas_figures);
			list = ft_make_big_matrix(g_str2);
			solve = ft_solve(list, count_figures(mas_figures));
			ft_print_square(solve, g_side);
			close(fd);
		}
		else
			return (ft_error());
	}
	else
		return (ft_usage());
}
