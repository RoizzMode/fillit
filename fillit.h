/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:20:17 by lschambe          #+#    #+#             */
/*   Updated: 2019/01/05 14:22:29 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# define BUFF_SIZE 21
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_tetra
{
	unsigned char	**figure;
	unsigned char	symb;
	int				p[4];
	struct s_tetra	*next;
}					t_tetra;

int					valid(char *file, t_tetra **tetra);
int					check_map(char *s, int *flag);
int					check_sharp(unsigned char **tetra, char c);
int					add_node(t_tetra **lst, char *s);
int					get_figure(char *s, t_tetra **tetra);
void				print_figures(t_tetra *lst);
int					points(t_tetra **tetra);
int					change_figure(t_tetra **tetra);
int					solut(t_tetra *tetra, int size);
int					rec(int size, unsigned char tab[size][size], t_tetra *tetra,
					int *flag);
void				printf_map(int size, unsigned char tab[size][size]);
void				zero_map(int size, unsigned char tab[size][size]);
void				put_figure(int size, unsigned char tab[size][size],
					t_tetra *tetra, int coor[2]);
int					check_figure(int size, unsigned char tab[size][size]);
void				remove_figure(int size, unsigned char tab[size][size],
					t_tetra *tetra);
void				cpy_arr(int size, unsigned char tab[size][size],
					unsigned char cpy[size][size]);
void				print_map(int size, unsigned char tab[size][size]);
void				initialize_points(t_tetra **tetra);

#endif
