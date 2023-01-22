/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:18:27 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/27 16:06:17 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*map;

	if (argc == 2)
	{
		valid_input(argv[1]);
		map = malloc(sizeof (t_data));
		if (initial_parsing(argv[1], map) < 0)
		{
			write(1, "FILE_ERROR\n", 12);
			return (0);
		}
		map->step_count = 0;
		map->mlx = mlx_init();
		load_images(map);
		map->mlx_win = mlx_new_window(map->mlx, map->mlx_win_width,
				map->mlx_win_height, "so_long!");
		create_the_map(map);
		mlx_hook(map->mlx_win, 17, 1L << 17, free_and_exit, map);
		mlx_hook(map->mlx_win, 2, 1L << 0, key_function, map);
		mlx_loop(map->mlx);
	}
	return (0);
}
