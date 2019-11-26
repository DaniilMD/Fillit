/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: openelop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:28:13 by openelop          #+#    #+#             */
/*   Updated: 2019/10/10 13:43:49 by openelop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_tetr(int tetcode, int row, int col, int n)
{
	int row_n;
	int col_n;
	int i;
	int j;

	get_rn_cn(&row_n, &col_n, get_gr_size(tetcode));
	i = 0;
	if (tetcode == 8 || tetcode == 9
	|| tetcode == 12 || tetcode == 13 || tetcode == 17)
		col--;
	if (tetcode == 6)
		col -= 2;
	while (i + row < row + row_n)
	{
		j = 0;
		while (j + col < col + col_n)
		{
			if (g_valids[tetcode][i][j] == '#')
				g_tetrmp[i + row][j + col] = n + 'A';
			j++;
		}
		i++;
	}
}

void	del_tetr(int tetcode, int gr_s, int row, int col)
{
	int row_n;
	int col_n;
	int i;
	int j;

	get_rn_cn(&row_n, &col_n, gr_s);
	i = 0;
	if (tetcode == 8 || tetcode == 9
	|| tetcode == 12 || tetcode == 13 || tetcode == 17)
		col--;
	if (tetcode == 6)
		col -= 2;
	while (i + row < row + row_n)
	{
		j = 0;
		while (j + col < col + col_n)
		{
			if (g_valids[tetcode][i][j] == '#')
				g_tetrmp[i + row][j + col] = '.';
			j++;
		}
		i++;
	}
}

void	realloc_tetrmp(int sqr, int indic)
{
	int		i;
	int		j;

	i = -1;
	if (!indic)
	{
		while (++i < sqr)
			ft_strdel(g_tetrmp + i);
		free(g_tetrmp);
	}
	i = -1;
	g_tetrmp = (char**)malloc(sizeof(char*) * (sqr + 1));
	while (++i < sqr + 1)
		g_tetrmp[i] = (char*)malloc(sizeof(char) * (sqr + 1));
	i = 0;
	while (i < sqr + 1)
	{
		j = 0;
		while (j < sqr + 1)
		{
			g_tetrmp[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		tetmap(int n, int tetcnt, int sqr)
{
	int row;
	int col;

	row = 0;
	if (n == tetcnt)
		return (1);
	while (row < sqr)
	{
		col = 0;
		while (col < sqr)
		{
			if (try_to_fill(row, col, n, sqr))
			{
				put_tetr(get_code(n), row, col, n);
				if (tetmap(n + 1, tetcnt, sqr))
					return (1);
				del_tetr(get_code(n), get_gr_size(get_code(n)), row, col);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int fd;
	int tetcnt;
	int sqr;

	if (argc == 2)
	{
		sqr = 1;
		fd = open(argv[1], O_RDONLY);
		pull_array();
		tetcnt = get_tetrs(fd);
		if (tetcnt == 0 || !slash_n(argv[1]) ||
		tetcnt > 26 || !valid_check(tetcnt, 0, 0))
		{
			ft_putstr("error\n");
			return (0);
		}
		sqr = sqrt_min(tetcnt);
		realloc_tetrmp(sqr - 1, 1);
		while (!(tetmap(0, tetcnt, sqr)))
			realloc_tetrmp(sqr++, 0);
		print_map(sqr);
	}
	else
		ft_putstr("usage: fillit target_file\n");
	return (0);
}
