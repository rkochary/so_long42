/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:03:44 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/27 13:50:31 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		put_char(str[i]);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void	put_number(int num)
{
	if (num > 9)
		put_number(num / 10);
	put_char(num % 10 + 48);
}

int	comprise_char_in_map(char c, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (c == str[i])
			return (1);
	return (0);
}
