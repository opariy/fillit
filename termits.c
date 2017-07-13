/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:58:23 by ataftai           #+#    #+#             */
/*   Updated: 2017/02/06 13:41:53 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check(int size, char map[][size], int ind[], t_flist *list)
{
	int i;
	int	cd[4][2];

	i = -1;
	while (++i < 4)
	{
		cd[i][0] = ind[0] + list->coords[i][0];
		cd[i][1] = ind[1] + list->coords[i][1];
	}
	i = -1;
	while (++i < 4)
	{
		if (cd[i][0] >= size || cd[i][1] >= size ||
				map[cd[i][0]][cd[i][1]] != '.')
			return (0);
	}
	while (--i >= 0)
		map[cd[i][0]][cd[i][1]] = list->letter;
	return (1);
}

void	place_term(int size, char map[][size], t_flist *list, int *flag)
{
	int i;
	int j;
	int ind[2];

	i = -1;
	if (!list && !*flag)
	{
		*flag = 1;
		show_map(size, map);
	}
	while (++i < size && !*flag)
	{
		j = -1;
		while (++j < size)
		{
			free_map(size, map, list->letter);
			ind[0] = i;
			ind[1] = j;
			if (check(size, map, ind, list))
				place_term(size, map, list->next, flag);
		}
	}
}

void	free_map(int size, char map[][size], char letter)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (map[i][j] == letter)
				map[i][j] = '.';
	}
}

int		fillit(t_flist *list, int size)
{
	char	map[size][size];
	int		i;
	int		j;
	int		flag;

	i = -1;
	flag = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			map[i][j] = '.';
	}
	place_term(size, map, list, &flag);
	if (!flag)
		fillit(list, size + 1);
	return (0);
}

void	show_map(int size, char map[][size])
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			write(1, &map[i][j], 1);
		write(1, "\n", 1);
	}
}
