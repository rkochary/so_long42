/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:02:06 by rkochary          #+#    #+#             */
/*   Updated: 2022/12/09 14:31:49 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_step	step(int x, int y, t_step step1)
{
	step1.x = x;
	step1.y = y;
	return (step1);
}

t_step	move_vector(int key_code, t_data *map)
{
	t_step	step1;

	step1.x = -1;
	step1.y = -1;
	(void)map;
	if (key_code == KEY_W || key_code == KEY_UP)
		step1 = step(0, -1, step1);
	if (key_code == KEY_S || key_code == KEY_DOWN)
		step1 = step(0, 1, step1);
	if (key_code == KEY_A || key_code == KEY_LEFT)
		step1 = step(-1, 0, step1);
	else if (key_code == KEY_D || key_code == KEY_RIGHT)
		step1 = step(1, 0, step1);
	return (step1);
}

void	move_player(t_data *map, t_step move_step)
{
	if ((map->map[map->gru_y][map->gru_x] == 'E'
		&& map->minion_number != 0)
		|| map->map[map->gru_y][map->gru_x] == '1')
	{
		map->gru_x -= move_step.x;
		map->gru_y -= move_step.y;
		return ;
	}
	map->step_count++;
	step_count(map->step_count);
	if (map->map[map->gru_y][map->gru_x] == 'E'
	&& map->minion_number == 0)
	{
		mlx_destroy_window(map->mlx, map->mlx_win);
		free_map(map);
		exit(0);
	}
	if (map->map[map->gru_y][map->gru_x] == 'C')
		map->minion_number--;
	map->map[map->gru_y][map->gru_x] = 'P';
	map->map[map->gru_y - move_step.y]
	[map->gru_x - move_step.x] = '0';
	mlx_clear_window(map->mlx, map->mlx_win);
	create_the_map(map);
}

int	key_function(int key_code, t_data *map)
{
	t_step	move_step;

	if (key_code == KEY_ESC)
	{
		mlx_destroy_window(map->mlx, map->mlx_win);
		free_map(map);
		exit(0);
	}
	move_step = move_vector(key_code, map);
	if (move_step.x == -1 && move_step.y == -1)
		return (0);
	map->gru_x += move_step.x;
	map->gru_y += move_step.y;
	move_player(map, move_step);
	return (0);
}

void	step_count(int count)
{
	put_char('\r');
	put_number(count);
	put_char(' ');
	put_str(":STEP COUNT\n");
}
