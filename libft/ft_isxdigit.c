/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:44:47 by sgendry           #+#    #+#             */
/*   Updated: 2018/12/04 21:21:22 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isxdigit(int ch)
{
	if ((ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f') ||
(ch >= '0' && ch <= '9'))
		return (1);
	else
		return (0);
}
