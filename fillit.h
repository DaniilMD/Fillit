/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: openelop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:15:06 by openelop          #+#    #+#             */
/*   Updated: 2019/10/10 14:15:09 by openelop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>

char	g_tetrs[26][4][4];
char	**g_tetrmp;
char	g_valids[19][4][4];

void	pull_array(void);
int		get_tetrs(int fd);
int		check_for_next(int k, int i, int j, int *sqrs);
int		valid_check(int tetcnt, int nexts, int sqrs);
void	print_map(int sqr);

int		get_i(int n);
int		left_j(int n);
int		get_j(int n);
int		get_code(int n);
int		sqrt_min(int nb);

int		get_gr_size(int tetcode);
int		check_segf(int sqr, int row, int col, int tetcode);
void	get_rn_cn(int *row_n, int *col_n, int gr_s);
int		check_possib(int gr_s, int row, int col, int tetcode);
int		try_to_fill(int row, int col, int n, int sqr);

void	put_tetr(int tetcode, int row, int col, int n);
void	del_tetr(int tetcode, int gr_s, int row, int col);
void	realloc_tetrmp(int sqr, int indic);
int		tetmap(int n, int tetcnt, int sqr);
void	del_tetr(int tetcode, int gr_s, int row, int col);

int		slash_n(char *name);
int		free_str(char **str);

#endif
