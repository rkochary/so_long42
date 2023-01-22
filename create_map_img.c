/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:00:01 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/27 16:10:01 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	create_the_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->minion_number = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
			put_images(data, i, j);
	}
}

void	load_images(t_data *data)
{
	data->img = malloc(sizeof(t_img) * 5);
	data->img[WALL_INDEX].img = mlx_xpm_file_to_image(data->mlx, "wall.xpm",
			&data->img[WALL_INDEX].img_width, &data->img[0].img_height);
	data->img[BACKGRAUND_INDEX].img = mlx_xpm_file_to_image(
			data->mlx, "backgraund.xpm",
			&data->img[BACKGRAUND_INDEX].img_width, &data->img[1].img_height);
	data->img[CHARACTER_INDEX].img = mlx_xpm_file_to_image(
			data->mlx, "character.xpm",
			&data->img[CHARACTER_INDEX].img_width, &data->img[2].img_height);
	data->img[COIN_INDEX].img = mlx_xpm_file_to_image(
			data->mlx, "minion.xpm",
			&data->img[COIN_INDEX].img_width, &data->img[0].img_height);
	data->img[EXIT_INDEX].img = mlx_xpm_file_to_image(data->mlx, "exit.xpm",
			&data->img[EXIT_INDEX].img_width, &data->img[0].img_height);
}

void	put_img_to_window(t_data *data, int x, int y, int img_index)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->img[img_index].img, x * SIZE, y * SIZE);
}

void	put_images(t_data *data, int y, int x)
{
	put_img_to_window(data, x, y, BACKGRAUND_INDEX);
	if (data->map[y][x] == '1')
		put_img_to_window(data, x, y, WALL_INDEX);
	else if (data->map[y][x] == '0')
		put_img_to_window(data, x, y, BACKGRAUND_INDEX);
	else if (data->map[y][x] == 'P')
	{
		data->gru_x = x;
		data->gru_y = y;
		put_img_to_window(data, x, y, CHARACTER_INDEX);
	}
	else if (data->map[y][x] == 'C')
	{
		data->minion_number++;
		put_img_to_window(data, x, y, COIN_INDEX);
	}
	else if (data->map[y][x] == 'E')
		put_img_to_window(data, x, y, EXIT_INDEX);
}
