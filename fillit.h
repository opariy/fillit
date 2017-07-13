/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 15:08:29 by ataftai           #+#    #+#             */
/*   Updated: 2017/02/10 14:44:08 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_flist
{
	int				coords[4][2];
	char			letter;
	struct s_flist	*next;
}					t_flist;

void				fb_zero(char str[], int size);
int					f_read(int opn, char str[], t_flist **list);
int					isvalid(char str[], t_flist **termits);
void				change(int mas[]);
int					f_valid(int mas[], t_flist **termits);
int					f_valid_1(int mas[]);
t_flist				*createlem(int data[], char letter);
void				add_elem(t_flist **beg, int data[]);
void				destroy(t_flist **beg);
int					fillit(t_flist *list, int size);
int					check(int size, char map[][size], int ind[], t_flist *list);
void				place_term(int size, char map[][size],
		t_flist *list, int *flag);
void				show_map(int size, char map[][size]);
void				free_map(int size, char map[][size], char letter);
#endif
