/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 15:13:55 by ataftai           #+#    #+#             */
/*   Updated: 2017/02/06 13:40:05 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

void	fb_zero(char str[], int size)
{
	while (--size >= 0)
		str[size] = 0;
}

int		f_read(int opn, char str[], t_flist **list)
{
	int		ret;
	char	c;

	while ((ret = read(opn, str, 20)))
	{
		c = 0;
		ret = read(opn, &c, 1);
		if ((ret && c != '\n') || !isvalid(str, list))
			return (0);
		fb_zero(str, 20);
	}
	if (c)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	char	str[20];
	int		opn;
	t_flist	*list;

	list = 0;
	if (argc != 2 || (opn = open(argv[1], O_RDONLY)) == -1)
	{
		write(1, "usage: ./fillit [Tetriminos-file]\n", 34);
		return (0);
	}
	if (!f_read(opn, str, &list) || !list)
	{
		write(1, "error\n", 6);
		return (0);
	}
	fillit(list, 2);
	destroy(&list);
	return (0);
}
