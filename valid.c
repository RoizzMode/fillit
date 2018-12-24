/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:43:27 by lschambe          #+#    #+#             */
/*   Updated: 2018/12/24 17:13:06 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	change_figure(t_tetra **tetra)
{
	unsigned char **tab;
	int i;
	int j;

	i = 0;
	tab = (unsigned char**)malloc(sizeof(unsigned char*) * ((*tetra)->p[1] - (*tetra)->p[0] + 1));
	while (i < ((*tetra)->p[1] - (*tetra)->p[0] + 1))
	{
		tab[i] = (unsigned char*)malloc(sizeof(unsigned char) * ((*tetra)->p[3] - (*tetra)->p[2] + 1));
		j = 0;
		while (j < ((*tetra)->p[3] - (*tetra)->p[2] + 1))
		{
			tab[i][j] = (*tetra)->figure[i + (*tetra)->p[0]][j + (*tetra)->p[2]];
			j++;
		}
		i++;
	}
	free((*tetra)->figure);
	(*tetra)->figure = tab;
}

void	points(t_tetra **tetra)
{
	int i;
	int j;

	i = -1;
	(*tetra)->p[0] = 3;
	(*tetra)->p[1] = 0;
	(*tetra)->p[2] = 3;
	(*tetra)->p[3] = 0;
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
	change_figure(tetra);
}

void		print_figures(t_tetra *lst)
{
	int i;
	int j;

	while (lst)
	{
		i = 0;
		while (i < (lst->p[1] - lst->p[0] + 1))
		{
			j = 0;
			while (j < (lst->p[3] - lst->p[2] + 1))
			{
				printf("%c", lst->figure[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
		printf("\n");
		/*i = 0;
		while (i < 4)
		{
			printf("%d ", lst->p[i]);
			i++;
		}
		printf("\n");*/
		lst = lst->next;
	}
}

void	get_figure(char *s, t_tetra **tetra)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	(*tetra)->figure = (unsigned char **)malloc(sizeof(unsigned char *) * 4);
	while (i < 4)
	{
		(*tetra)->figure[i] = (unsigned char*)malloc(sizeof(unsigned char) * 4);
		j = 0;
		while (j < 4)
		{
			if (s[k] == '#')
				(*tetra)->figure[i][j] = (*tetra)->symb;
			else
				(*tetra)->figure[i][j] = (unsigned char)s[k];
			j++;
			k++;
		}
		k++;
		i++;
	}
	points(tetra);
}

int			add_node(t_tetra **lst, char *s)
{
	t_tetra		*new_tetra;
	t_tetra		*to_end;
	static int	i;

	new_tetra = (t_tetra*)malloc(sizeof(t_tetra));
	new_tetra->symb = 'A' + (i++);
	get_figure(s, &new_tetra);
	new_tetra->next = NULL;
	if (!(*lst))
	{
		*lst = new_tetra;
		return (1);
	}
	if ((*lst)->next == NULL)
	{
		(*lst)->next = new_tetra;
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

int			check_sharps(char *s)
{
	int i;

	i = 2;
	if (s[0] == '#' && (!(s[1] == '#' || s[5] == '#')))
		return (0);
	if (s[1] == '#' && (!(s[2] == '#' || s[6] == '#' || s[0] == '#')))
		return (0);
	while (i++ < 5)
		if (s[i] == '#' && (!(s[i + 1] == '#'
						|| s[i + 5] == '#' || s[i - 1] == '#')))
			return (0);
	while (i++ < 15)
		if (s[i] == '#' && (!(s[i - 5] == '#' || s[i + 1] == '#'
						|| s[i + 5] == '#' || s[i - 1] == '#')))
			return (0);
	while (i++ < 5)
		if (s[i] == '#' && (!(s[i + 1] == '#'
						|| s[i - 5] == '#' || s[i - 1] == '#')))
			return (0);
	if (s[17] == '#' && (!(s[18] == '#' || s[16] == '#' || s[12] == '#')))
		return (0);
	if (s[18] == '#' && (!(s[17] == '#' || s[13] == '#')))
		return (0);
	return (1);
}

int			check_map(char *s, int *flag)
{
	int i;
	int j;

	if (!s)
		return (0);
	if (ft_strlen(s) < 20)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (((i + 1) % 5 == 0) && s[i] != '\n')
			return (0);
		if (((i + 1) % 5 != 0) && (!(s[i] != '.' || s[i] != '#')))
			return (0);
		if (s[i] == '#')
			j++;
		i++;
	}
	if (!(s[20] == '\n' || s[20] == '\0') || j != 4)
		return (0);
	if (s[20] == '\0')
		*flag = 0;
	return (1);
}
