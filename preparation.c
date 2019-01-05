/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:21:40 by sgendry           #+#    #+#             */
/*   Updated: 2019/01/05 14:22:05 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					change_figure(t_tetra **tetra)
{
	unsigned char	**tab;
	int				i;
	int				j;

	i = 0;
	if (!(tab = (unsigned char**)malloc(sizeof(unsigned char*) *
			((*tetra)->p[1] - (*tetra)->p[0] + 1))))
		return (0);
	while (i < ((*tetra)->p[1] - (*tetra)->p[0] + 1))
	{
		if (!(tab[i] = (unsigned char*)malloc(sizeof(unsigned char) *
				((*tetra)->p[3] - (*tetra)->p[2] + 1))))
			return (0);
		j = 0;
		while (j < ((*tetra)->p[3] - (*tetra)->p[2] + 1))
		{
			tab[i][j] = (*tetra)->figure[i + (*tetra)->p[0]][j +
				(*tetra)->p[2]];
			j++;
		}
		i++;
	}
	free((*tetra)->figure);
	(*tetra)->figure = tab;
	return (1);
}

void				initialize_points(t_tetra **tetra)
{
	(*tetra)->p[0] = 3;
	(*tetra)->p[1] = 0;
	(*tetra)->p[2] = 3;
	(*tetra)->p[3] = 0;
}

int					points(t_tetra **tetra)
{
	int				i;
	int				j;

	i = -1;
	initialize_points(tetra);
	while (i++ < 3)
	{
		j = -1;
		while (j++ < 3)
			if ((*tetra)->figure[i][j] == (*tetra)->symb)
			{
				if (i < (*tetra)->p[0])
					(*tetra)->p[0] = i;
				if (i > (*tetra)->p[1])
					(*tetra)->p[1] = i;
				if (j < (*tetra)->p[2])
					(*tetra)->p[2] = j;
				if (j > (*tetra)->p[3])
					(*tetra)->p[3] = j;
			}
	}
	if (!(change_figure(tetra)))
		return (0);
	return (1);
}

int					get_figure(char *str, t_tetra **tetra)
{
	int				h;
	int				w;
	int				i;

	h = -1;
	i = -1;
	if (!((*tetra)->figure =
				(unsigned char **)malloc(sizeof(unsigned char *) * 4)))
		return (0);
	while (++h < 4)
	{
		if (!((*tetra)->figure[h] =
					(unsigned char*)malloc(sizeof(unsigned char) * 4)))
			return (0);
		w = -1;
		while (++w < 4)
			if (str[++i] == '#')
				(*tetra)->figure[h][w] = (*tetra)->symb;
			else
				(*tetra)->figure[h][w] = str[i];
		i++;
	}
	if (!(check_sharp((*tetra)->figure, (*tetra)->symb)) || (!(points(tetra))))
		return (0);
	return (1);
}

int					add_node(t_tetra **lst, char *str)
{
	t_tetra			*new_tetra;
	t_tetra			*to_end;
	static int		i;

	if (!(new_tetra = (t_tetra*)malloc(sizeof(t_tetra))))
		return (0);
	new_tetra->symb = 'A' + (i++);
	if (!(get_figure(str, &new_tetra)))
		return (0);
	new_tetra->next = NULL;
	if (!(*lst))
	{
		*lst = new_tetra;
		return (1);
	}
	to_end = *lst;
	while (to_end->next)
		to_end = to_end->next;
	to_end->next = new_tetra;
	if (new_tetra->symb > 'Z')
		return (0);
	return (1);
}
