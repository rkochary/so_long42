/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:04:03 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/27 16:05:43 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	p_validation(t_data *data)
{
	int	i;
	int	j;
	int	p_count;

	i = 0;
	p_count = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
			if (data->map[i][j] == 'P')
				p_count++;
	}
	if (p_count == 1)
		return (1);
	return (0);
}

int	c_validation(t_data *data)
{
	int	i;
	int	j;
	int	c_count;

	c_count = 0;
	i = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
			if (data->map[i][j] == 'C')
				c_count++;
	}
	return (c_count > 0);
}

int	e_validation(t_data *data)
{
	int	i;
	int	j;
	int	e_count;

	i = 0;
	e_count = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'E')
				e_count++;
		}
	}
	return (e_count > 0);
}

int	wall_validation(t_data *data)
{
	int	line_index;
	int	line_len;

	line_index = -1;
	line_len = -1;
	while (data->map[0][++line_len])
		if (data->map[data->line_count -1][line_len] != '1'
			|| data->map[0][line_len] != '1')
			return (0);
	while (++line_index < data->line_count)
		if (data->map[line_index][0] != '1'
			|| data->map[line_index][line_len - 1] != '1')
			return (0);
	return (1);
}

int	map_validation(t_data *data)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	len = 0;
	if (data->map[0])
		len = str_len(data->map[0]);
	data->mlx_win_width = len * SIZE;
	while (data->map[++i])
	{
		j = -1;
		if (str_len(data->map[i]) != len)
			return (0);
		while (data->map[i][++j])
			if (!comprise_char_in_map(data->map[i][j], "PEC01"))
				return (0);
	}
	return (1);
}
