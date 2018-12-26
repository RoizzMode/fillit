/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solut.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:41:30 by lschambe          #+#    #+#             */
/*   Updated: 2018/12/26 14:54:19 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_figure(int size, unsigned char tab[size][size], t_tetra *tetra, int i, int j)
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
			if (tetra->figure[h][w] == tetra->symb)
				tab[a][b] = tab[a][b] + tetra->symb;
			w++;
			b++;
		}
		h++;
		a++;
	}
}

int		check_figure(int size, unsigned char tab[size][size])
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

void	remove_figure(int size, unsigned char tab[size][size], t_tetra *tetra, int i, int j)
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

void	print_map(int size, unsigned char tab[size][size])
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
				printf("%c ", tab[i][j]);
			else
				printf("%d ", (int)tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void	cpy_arr(int size, unsigned char tab[size][size], unsigned char cpy[size][size])
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			cpy[i][j] = tab[i][j];
			j++;
		}
		i++;
	}
}

void zero_map(int size, unsigned char tab[size][size])
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		rec(int size, unsigned char tab[size][size], t_tetra *tetra, int *flag)
{
	int i;
	int j;
	unsigned char cpy[size][size];

	i = 0;
	while (i < (size - (tetra->p[1] - tetra->p[0])))
	{
		//printf("here");
		j = 0;
		while (j < (size - (tetra->p[3] - tetra->p[2])))
		{
			//printf("here\n");
			if (*flag == 1)
				return (1);
			if (i == 0 && j == 0 && tetra->symb == 'A')
				zero_map(size, tab);
			put_figure(size, tab, tetra, i, j);
			printf("Put: %c\n", tetra->symb);
			print_map(size, tab);
			if (check_figure(size, tab) && !(tetra->next))
			{
				printf("Found: \n");
				print_map(size,tab);
				//printf("here\n");
				*flag = 1;
				return (1);
			}
			if (!check_figure(size, tab))
			{
				printf("Remove %c\n", tetra->symb);
				remove_figure(size, tab, tetra, i, j);
				print_map(size, tab);
				//return (0);
			}
			else if (check_figure(size, tab) && tetra->next)
			{
				cpy_arr(size, tab, cpy);
				if (!(rec(size, cpy, tetra->next, flag)))
				{
					remove_figure(size,tab, tetra, i, j);
				}
			}
			//if (*flag == 1)
			//	return (1);
			//remove_figure(size,tab, tetra, i, j);
			j++;
		}
		i++;
	}
	//print_map(size,tab);
	//if (*flag == 1)
	//	return (1);
	if (tetra->symb == 'A')
	{
		//printf("here\n");
		//print_map(size, tab);
		rec(size + 1, tab, tetra, flag);
	}
	return (0);
}

int solut(t_tetra *tetra)
{
	int size = 3;
	unsigned char s[size][size];
	int i;
	int j;
	int flag;
	int *f;

	//tetra->next = NULL;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			s[i][j] = 0;
			j++;
		}
		i++;
	}
	//print_map(size, s);
	//tetra->next = NULL;
	//print_map(size + 1, s);
	flag = 0;
	f = &flag;
	i = rec(size, s, tetra, f);
	return (1);
}
