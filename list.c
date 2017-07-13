/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:11:36 by ataftai           #+#    #+#             */
/*   Updated: 2017/02/03 16:27:38 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_flist		*createlem(int data[], char letter)
{
	t_flist *newelem;
	int		i;

	i = -1;
	newelem = (t_flist *)malloc(sizeof(t_flist));
	while (++i < 4)
	{
		newelem->coords[i][0] = data[i] / 5;
		if (data[i] < 4)
			newelem->coords[i][1] = data[i];
		else
			newelem->coords[i][1] = data[i] % 5;
	}
	newelem->letter = letter;
	newelem->next = 0;
	return (newelem);
}

void		add_elem(t_flist **beg, int data[])
{
	char	letter;
	t_flist *head;

	letter = 'B';
	if (!(*beg))
	{
		*beg = createlem(data, 'A');
		return ;
	}
	head = *beg;
	while (head->next)
	{
		head = head->next;
		letter++;
	}
	head->next = createlem(data, letter);
}

void		destroy(t_flist **beg)
{
	t_flist *temp;

	while (*beg)
	{
		temp = (*beg)->next;
		free(*beg);
		*beg = temp;
	}
}
