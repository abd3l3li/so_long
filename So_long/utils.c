/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:02:05 by abel-baz          #+#    #+#             */
/*   Updated: 2024/03/28 16:02:07 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_extracoor(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'M')
	{
		data->x_m = x;
		data->y_m = y;
		data->m++;
	}
	else if (data->map[y][x] == 'E')
	{
		data->x_e = x;
		data->y_e = y;
		data->e++;
	}
}

void	ft_coordinates_and_count(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->lines)
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->x_p = x;
				data->y_p = y;
				data->p++;
			}
			else if (data->map[y][x] == 'C')
				data->c++;
			else if (data->map[y][x] == 'E')
				ft_extracoor(data, x, y);
			else if (data->map[y][x] == 'M')
				ft_extracoor(data, x, y);
			x++;
		}
		y++;
	}
}

void	ft_init2(t_data *data)
{
	data->map = 0;
	data->map2 = 0;
	data->fd = 0;
	data->columns = 0;
	data->i = 0;
	data->j = 0;
	data->x_p = 0;
	data->y_p = 0;
	data->x_m = 0;
	data->y_m = 0;
	data->c = 0;
	data->e = 0;
	data->p = 0;
	data->m = 0;
	data->moves = 0;
	data->x = 0;
	data->y = 0;
}

void	ft_init(t_data *data)
{
	data->mlx = 0;
	data->win = 0;
	data->player = 0;
	data->rplayer = 0;
	data->lplayer = 0;
	data->wall = 0;
	data->space = 0;
	data->ctbl = 0;
	data->exit = 0;
	data->noexit = 0;
	data->enemy = 0;
	data->enemy_plus = 0;
	data->lines = 0;
	data->x_e = 0;
	data->y_e = 0;
	ft_init2(data);
}

int	ft_count_lines(t_data *data)
{
	int		count;
	char	*str;

	count = 0;
	while (1)
	{
		str = get_next_line(data->fd);
		if (!str)
			break ;
		count++;
		free(str);
	}
	free(str);
	return (count);
}
