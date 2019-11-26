/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: openelop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:55:07 by openelop          #+#    #+#             */
/*   Updated: 2019/10/10 13:55:09 by openelop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_i(int n)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (g_tetrs[n][i][j] == '#')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int		left_j(int n)
{
	int i;
	int j;
	int left_j;

	i = 0;
	left_j = 4;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (g_tetrs[n][i][j] == '#')
				if (j < left_j)
					left_j = j;
			j++;
		}
		i++;
	}
	return (left_j);
}

int		get_j(int n)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (g_tetrs[n][i][j] == '#')
			{
				if (left_j(n) < j)
				{
					if (j - left_j(n) == 2)
						return (j - 2);
					else
						return (j - 1);
				}
				else
					return (j);
			}
			j++;
		}
	}
	return (-1);
}

int		get_code(int n)
{
	int i;
	int j;
	int counter;
	int indic;

	counter = 0;
	while (counter < 19)
	{
		i = -1;
		indic = 0;
		while (++i + get_i(n) < 4)
		{
			j = -1;
			while (++j + get_j(n) < 4)
				if (g_tetrs[n][i + get_i(n)][j + get_j(n)]
				== g_valids[counter][i][j] && g_valids[counter][i][j] == '#')
					indic++;
		}
		if (indic == 4)
			break ;
		counter++;
	}
	return (counter);
}

int		sqrt_min(int nb)
{
	int i;

	i = 0;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (i <= nb / 2)
	{
		if (i == 46340)
			return (0);
		if (i * i > nb)
			return (i - 1);
		else if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
