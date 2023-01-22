/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:48:52 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/27 16:05:59 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data *data)
{
	while (--data->line_count >= 0)
		free(data->map[data->line_count]);
	free(data->map);
	free(data);
	exit(EXIT_FAILURE);
}

int	free_and_exit(t_data *map)
{
	free_map(map);
	return (0);
}

void	print_and_free(t_data *data, char *str)
{
	put_str(str);
	free_map(data);
}
