#include "fillit.h"

void	pull_array(void)
{
	int		k;
	int		i;
	int		j;
	char	*line;

	i = 0;
	k = -1;
	line = "##..\n##..\n....\n....\n\n#...\n#...\n#...\n#...\n\n####"
	"\n....\n....\n....\n\n###.\n#...\n....\n....\n\n###.\n..#.\n....\n....\n\n"
	"#...\n###.\n....\n....\n\n..#.\n###.\n....\n....\n\n"
	"#...\n##..\n#...\n....\n\n.#..\n##..\n.#..\n....\n\n"
	".#..\n###.\n....\n....\n\n###.\n.#..\n....\n....\n\n##..\n.##.\n....\n...."
	"\n\n.##.\n##..\n....\n....\n\n.#..\n##..\n#...\n....\n\n"
	"#...\n##..\n.#..\n....\n\n##..\n.#..\n.#..\n....\n\n##..\n#...\n#...\n...."
	"\n\n.#..\n.#..\n##..\n....\n\n#...\n#...\n##..\n....";
	while (++k < 19)
	{
		j = -1;
		while (++j < 4)
		{
			ft_strncpy(g_valids[k][j], line, 4);
			line += 5;
		}
		line++;
	}
}

int		get_tetrs(int fd)
{
	int		k;
	int		i;
	char	*str;

	k = -1;
	str = NULL;
	while (++k < 27)
	{
		i = -1;
		while (++i < 4)
		{
			if (get_next_line(fd, &str) <= 0 || ft_strlen(str) != 4)
				return (free_str(&str));
			ft_strncpy(g_tetrs[k][i], str, 4);
			free_str(&str);
		}
		if ((get_next_line(fd, &str)) == 0)
			break ;
		if (ft_strlen(str) != 0)
			return (free_str(&str));
		free_str(&str);
	}
	return (k + 1);
}

int		check_for_next(int k, int i, int j, int *sqrs)
{
	int counter;

	counter = 0;
	*sqrs += 1;
	if (i < 3 && g_tetrs[k][i + 1][j] == '#')
		counter++;
	if (j < 3 && g_tetrs[k][i][j + 1] == '#')
		counter++;
	if (i > 0 && g_tetrs[k][i - 1][j] == '#')
		counter++;
	if (j > 0 && g_tetrs[k][i][j - 1] == '#')
		counter++;
	return (counter);
}

int		valid_check(int tetcnt, int nexts, int sqrs)
{
	int i;
	int k;
	int j;

	k = -1;
	while (++k < tetcnt)
	{
		nexts = 0;
		sqrs = 0;
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
			{
				if (g_tetrs[k][i][j] != '#' && g_tetrs[k][i][j] != '.')
					return (0);
				if (g_tetrs[k][i][j] == '#')
					nexts += check_for_next(k, i, j, &sqrs);
			}
		}
		if (!(sqrs == 4 && (nexts == 6 || nexts == 8)))
			return (0);
	}
	return (1);
}

void	print_map(int sqr)
{
	int i;
	int j;

	i = 0;
	while (i < sqr)
	{
		j = 0;
		while (j < sqr)
		{
			ft_putchar(g_tetrmp[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
