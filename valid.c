/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:50:59 by ataftai           #+#    #+#             */
/*   Updated: 2017/02/13 15:41:55 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		isvalid(char str[], t_flist **termits)
{
	int i;
	int mas[4];
	int j;

	i = -1;
	j = 0;
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n'
			|| str[19] != '\n')
		return (0);
	while (++i < 19)
	{
		if (str[i] != '#' && (str[i] != '.' && i != 4
					&& i != 9 && i != 14))
			return (0);
		if (str[i] == '#')
		{
			if (j == 4)
				return (0);
			mas[j] = i;
			j++;
		}
	}
	if (j == 4 && f_valid(mas, termits))
		return (1);
	return (0);
}

void	change(int mas[])
{
	int temp;
	int min;
	int i;

	temp = mas[0] / 5;
	min = 5;
	i = -1;
	while (++i < 4)
	{
		mas[i] -= 5 * temp;
		if (mas[i] % 5 <= min)
			min = mas[i] % 5;
	}
	while (--i >= 0)
		mas[i] -= min;
}

int		f_valid(int mas[], t_flist **termits)
{
	int conect;

	conect = 0;
	conect = f_valid_1(mas);
	if (conect != 3 && conect != 4)
		return (0);
	change(mas);
	add_elem(termits, mas);
	return (1);
}

int		f_valid_1(int mas[])
{
	int i;
	int j;
	int sum;

	i = 0;
	sum = 0;
	while (i < 4)
	{
		j = 3;
		while (j > i)
		{
			if (mas[i] + 1 == mas[j] || mas[i] - 1 == mas[j] ||
					mas[i] + 5 == mas[j] || mas[i] - 5 == mas[j])
				sum++;
			j--;
		}
		i++;
	}
	return (sum);
}
