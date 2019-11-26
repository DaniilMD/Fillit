/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kostil.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: openelop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:09:03 by openelop          #+#    #+#             */
/*   Updated: 2019/10/17 15:09:05 by openelop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		slash_n(char *name)
{
	char	a;
	int		fd;
	int		i;

	fd = open(name, O_RDONLY);
	while ((i = read(fd, &a, 1)))
		if (i == -1)
			return (0);
	if (a != '\n')
		return (0);
	return (1);
}

int		free_str(char **str)
{
	ft_strdel(str);
	return (0);
}
