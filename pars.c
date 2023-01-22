/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:02:31 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/27 15:47:57 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	parse_map(t_data *data, char *read_line, int fd)
{
	if (!read_line)
		print_and_free(data, "MAP_ERROR\n");
	while (read_line)
	{
		data->line_count++;
		free(read_line);
		read_line = get_next_line(fd);
	}
}

int	valid_input(char *str)
{
	int	len;

	len = str_len(str) - 1;
	if (str[len] != 'r' || str[len - 1] != 'e' || str[len - 2] != 'b')
		return (0);
	return (1);
}

void	validate_all(t_data *data, char *path)
{
	if (!map_validation(data))
		print_and_free(data, "MAP_ERROR\n");
	if (!p_validation(data))
		print_and_free(data, "P_ERROR\n");
	if (!e_validation(data))
		print_and_free(data, "E_ERROR\n");
	if (!c_validation(data))
		print_and_free(data, "C_ERROR\n");
	if (!wall_validation(data))
		print_and_free(data, "WALL_ERROR\n");
	if (!valid_input(path))
		print_and_free(data, "FILE_ERROR\n");
}

int	initial_parsing(char *path, t_data *data)
{
	int		fd;
	char	*read_line;
	int		i;

	i = -1;
	read_line = NULL;
	fd = open(path, O_RDONLY);
	if (read(fd, read_line, 0) == -1)
		return (-1);
	data->line_count = 0;
	read_line = get_next_line(fd);
	parse_map(data, read_line, fd);
	close(fd);
	fd = open(path, O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->line_count) + 1);
	while (++i < data->line_count)
		data->map[i] = get_next_line(fd);
	data->mlx_win_height = data->line_count * SIZE;
	data->map[i] = NULL;
	validate_all(data, path);
	return (0);
}
