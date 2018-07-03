/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfill.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:14:27 by ovirchen          #+#    #+#             */
/*   Updated: 2017/12/09 16:05:37 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFILL_H
# define LIBFILL_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct	s_list
{
	int				number;
	int				figure;
	int				cnt;
	char			**matrix;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

char			*g_str2;
int				g_side;
int				g_first;
int				ft_cntelem(char **mas);
size_t			ft_strlen(const char *s);
int				ft_strcmp(char *s1, char *s2);
int				check_tetriminos(char *tet);
int				ft_number_figures(char *str);
int				ft_side_square(int *mas_figures);
int				*ft_mas_figures(char *str);
int				ft_size_matrix(int figure, int side);
char			**create_part_matrix(int side, int num_fig, int n);
char			**sq(int side, int num_fig);
char			**i_vertic(int side, int num_fig);
char			**i_horiz(int side, int num_fig);
char			**s_horiz(int side, int num_fig);
char			**s_vertic(int side, int num_fig);
char			**t_vertic_right(int side, int num_fig);
char			**t_vertic_left(int side, int num_fig);
char			**t_horiz(int side, int num_fig);
char			**t_revers(int side, int num_fig);
char			**j_revers(int side, int num_fig);
char			**j_horiz(int side, int num_fig);
char			**j_vertic(int side, int num_fig);
char			**j_horiz_revers(int side, int num_fig);
char			**l_revers(int side, int num_fig);
char			**l_horiz_revers(int side, int num_fig);
char			**l_vertic(int side, int num_fig);
char			**l_horiz(int side, int num_fig);
char			**z_horiz(int side, int num_fig);
char			**z_vertic(int side, int num_fig);
void			list_add(t_list **begin, int i, int fig);
char			**new_figure_matrix(int figure, int side, int num_fig);
void			print_list(t_list *begin);
t_list			*ft_make_big_matrix(char *str);
int				count_figures(int *mas_figures);
char			**ft_solve(const t_list *list, int num);
void			ft_print_square(char **matrix, int side);
t_list			*ft_big_matrix(int *mas_figures);
void			ft_clean_arr(char **mas, int num);
int				ft_alg(t_list *list, t_list *head, char **mas, int num);
void			ft_write_first(char **mas, t_list *buf, size_t first);
int				ft_incriment(t_list *head, char **mas, int num, int incside);
int				ft_prev(t_list *list, t_list *head, char **mas, int num);

#endif
