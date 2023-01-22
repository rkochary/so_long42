/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:03:24 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/27 16:00:10 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SO_LONG_H
# define SO_LONG_H
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define WALL_INDEX 	0
# define BACKGRAUND_INDEX 1
# define CHARACTER_INDEX  2
# define COIN_INDEX 	  3
# define EXIT_INDEX 	  4
# define SIZE 			 62
# define KEY_RIGHT	124
# define KEY_LEFT	123
# define KEY_UP		126
# define KEY_DOWN	125

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line.h"

typedef struct s_step
{
	int	x;
	int	y;	
}		t_step;

typedef struct s_img
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
}			t_img;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	int		mlx_win_width;
	int		mlx_win_height;
	t_img	*img;
	int		line_count;
	char	**map;
	int		gru_x;
	int		gru_y;
	int		minion_number;
	int		step_count;
}			t_data;

void	load_images(t_data *data);
int		free_and_exit(t_data *map);
int		initial_parsing(char *path, t_data *data);
int		key_function(int key_kode, t_data *map);
void	move_function_w(t_data *map);
void	create_the_map(t_data *data);
int		map_validation(t_data *data);
int		str_len(char *str);
int		wall_validation(t_data *data);
int		e_validation(t_data *data);
int		c_validation(t_data *data);
int		comprise_char_in_map(char c, char *str);
void	put_number(int num);
void	put_char(char c);
void	put_str(char *str);
int		valid_input(char *str);
int		p_validation(t_data *data);
void	step_count(int count);
void	print_and_free(t_data *data, char *str);
void	free_map(t_data *data);
void	put_images(t_data *data, int y, int x);
void	put_img_to_window(t_data *data, int x, int y, int img_index);

#endif
