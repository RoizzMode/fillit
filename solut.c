/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solut.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:41:30 by lschambe          #+#    #+#             */
/*   Updated: 2018/12/27 16:22:14 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_figure(int size, unsigned char tab[size][size], t_tetra *tetra, int c[2])
{
	int h;
	int w;
	int a;
	int b;

	h = 0;
	a = c[0];
	while (h <= (tetra->p[1] - tetra->p[0]))
	{
		w = 0;
		b = c[1];
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

void	remove_figure(int size, unsigned char tab[size][size], t_tetra *tetra)
{
	int h;
	int w;

	h = 0;
	while (h < size)
	{
		w = 0;
		while (w < size)
		{
			if (tab[h][w] > 'Z')
				tab[h][w] = tab[h][w] - tetra->symb;
			if (tab[h][w] == tetra->symb)
				tab[h][w] = 0;
			w++;
		}
		h++;
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
				ft_putchar(tab[i][j]);
			else
				ft_putchar('.');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
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

int help_rec(int size, unsigned char tab[size][size], t_tetra *tetra, int *flag)
{
	unsigned char cpy[size][size];

	if (check_figure(size, tab) && !(tetra->next))
	{
		print_map(size,tab);
		*flag = 1;
		return (1);
	}
	if (!check_figure(size, tab))
		remove_figure(size, tab, tetra);
	else if (check_figure(size, tab) && tetra->next)
	{
		cpy_arr(size, tab, cpy);
		if (!(rec(size, cpy, tetra->next, flag)))
		{
			remove_figure(size,tab, tetra);
		}
	}
	return (0);
}

int		rec(int size, unsigned char tab[size][size], t_tetra *tetra, int *flag)
{
	int i;
	int j;
	int c[2];

	i = 0;
	while (i < (size - (tetra->p[1] - tetra->p[0])))
	{
		j = 0;
		while (j < (size - (tetra->p[3] - tetra->p[2])))
		{
			if (*flag == 1)
				return (1);
			if (i == 0 && j == 0 && tetra->symb == 'A')
				zero_map(size, tab);
			c[0] = i;
			c[1] = j;
			put_figure(size, tab, tetra, c);
			if (help_rec(size, tab, tetra, flag))
				return (1);
			j++;
		}
		i++;
	}
	if (tetra->symb == 'A')
		rec(size + 1, tab, tetra, flag);
	return (0);
}

int solut(t_tetra *tetra)
{
	int size = 2;
	unsigned char s[size][size];
	int i;
	int j;
	int flag;
	int *f;

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
	flag = 0;
	f = &flag;
	i = rec(size, s, tetra, f);
	return (1);
}
