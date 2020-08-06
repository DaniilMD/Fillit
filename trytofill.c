#include "fillit.h"

int		get_gr_size(int tetcode)
{
	if (tetcode == 0)
		return (22);
	else if ((tetcode >= 3 && tetcode <= 6) || (tetcode >= 9 && tetcode <= 12))
		return (23);
	else if ((tetcode >= 7 && tetcode <= 8) || (tetcode >= 13 && tetcode <= 18))
		return (32);
	else if (tetcode == 1)
		return (41);
	else
		return (14);
}

int		check_segf(int sqr, int row, int col, int tetcode)
{
	int gr_s;

	gr_s = get_gr_size(tetcode);
	if (tetcode == 8 || tetcode == 9
	|| tetcode == 12 || tetcode == 13 || tetcode == 17)
	{
		if (col == 0)
			return (0);
		else
			col--;
	}
	if (tetcode == 6)
	{
		if (col <= 1)
			return (0);
		else
			col -= 2;
	}
	if ((row + (gr_s / 10 - 1) >= sqr) || (col + (gr_s % 10 - 1) >= sqr))
		return (0);
	return (1);
}

void	get_rn_cn(int *row_n, int *col_n, int gr_s)
{
	*row_n = gr_s / 10;
	*col_n = gr_s % 10;
}

int		check_possib(int gr_s, int row, int col, int tetcode)
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
			if (g_valids[tetcode][i][j]
			== '#' && g_tetrmp[i + row][j + col] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		try_to_fill(int row, int col, int n, int sqr)
{
	int tetcode;
	int indic;
	int size_group;

	if (g_tetrmp[row][col] != '.')
		return (0);
	indic = 0;
	tetcode = get_code(n);
	size_group = get_gr_size(tetcode);
	if (!check_segf(sqr, row, col, tetcode))
		return (0);
	if (!check_possib(size_group, row, col, tetcode))
		return (0);
	return (1);
}
