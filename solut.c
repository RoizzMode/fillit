/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solut.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:41:30 by lschambe          #+#    #+#             */
/*   Updated: 2018/12/24 14:56:15 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_figure(int size, char tab[size][size], t_tetra *tetra, int i, int j)
{
	int h;
	int w;
	int a;
	int b;

	h = 0;
	a = i;
	//printf("%d %d\n", i, j);
	while (h <= (tetra->p[1] - tetra->p[0]))
	{
		w = 0;
		b = j;
		while (w <= (tetra->p[3] - tetra->p[2]))
		{
			if (tetra->figure[h][w] == tetra->symb)
				tab[a][b] = tab[a][b] + tetra->figure[h][w];
			w++;
			b++;
		}
		h++;
		a++;
	}
}

int		check_figure(int size, char tab[size][size])
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i][j] > 'Z')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	remove_figure(int size, char tab[size][size], t_tetra *tetra, int i, int j)
{
	int h;
	int w;
	int a;
	int b;

	h = 0;
	a = i;
	while (h <= (tetra->p[1] - tetra->p[0]))
	{
		w = 0;
		b = j;
		while (w <= (tetra->p[3] - tetra->p[2]))
		{
			if (tab[a][b] > 'Z')
				tab[a][b] = tab[a][b] - tetra->symb;
			if (tab[a][b] == tetra->symb)
				tab[a][b] = 0;
			w++;
			b++;
		}
		h++;
		a++;
	}
}

void	print_map(int size, char tab[size][size])
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i][j] >= 'A' && tab[i][j] <= 'Z')
				printf("%c", tab[i][j]);
			else
				printf(".");
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

int		rec(int size,char tab[size][size], t_tetra *tetra)
{
	int i;
	int j;

	i = 0;
	//j = 0;
	//put_figure(size, tab, tetra, 0, 0);
	while (i < (size - (tetra->p[1] - tetra->p[0])))
	{
		//printf("here");
		j = 0;
		while (j < (size - (tetra->p[3] - tetra->p[2])))
		{
			put_figure(size, tab, tetra, i, j);
			//printf("Put :\n");
			print_map(size, tab);
			//if (!(check_figure(size,tab)))
			remove_figure(size, tab, tetra, i, j);
			//printf("Removed :\n");
			//print_map(size, tab);
			//printf("%c", tab[i][j]);
			j++;
		}
		//printf("\n");
		i++;
	}
	//tab[0][0] = '.';
	return (1);
}

int solut(t_tetra *tetra)
{
	char s[3][3];
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			s[i][j] = 0;
			j++;
		}
		i++;
	}
	//tetra->next = NULL;
	i = rec(3, s, tetra);
	return (1);
}
