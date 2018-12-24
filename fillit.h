/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:20:17 by lschambe          #+#    #+#             */
/*   Updated: 2018/12/24 17:14:13 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# define BUFF_SIZE 21
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_tetra
{
	unsigned char **figure;
	unsigned char symb;
	int p[4];
	//int height;
	//int width;
	struct s_tetra *next;
}				t_tetra;

int			valid(char *file, t_tetra **tetra);
int			check_map(char *s, int *flag);
int			check_sharps(char *s);
int			add_node(t_tetra **lst, char *s);
void		get_figure(char *s, t_tetra **tetra);
void		print_figures(t_tetra *lst);
void		points(t_tetra **tetra);
void		change_figure(t_tetra **tetra);
int			solut(t_tetra *tetra);
int			rec(int size,unsigned char tab[size][size], t_tetra *tetra);
void	printf_map(int size, unsigned char tab[size][size]);


#endif
