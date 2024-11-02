/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:59:37 by abel-baz          #+#    #+#             */
/*   Updated: 2024/03/28 16:00:08 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_dup(t_data *data)
{
	int	i;

	i = 0;
	data->map2 = ft_calloc(data->lines + 1, sizeof(char *));
	while (i < data->lines)
	{
		data->map2[i] = ft_strdup(data->map[i]);
		i++;
	}
}

int	ft_algo(t_data *data, int x, int y)
{
	static int	c;
	static int	e;

	if (x < 0 || y < 0 || x > data->columns || y > data->lines
		|| data->map2[y][x] == '1' || data->map2[y][x] == 'X')
		return (0);
	if (data->map2[y][x] == 'C')
		c++;
	else if (data->map2[y][x] == 'E')
	{
		e++;
		data->map2[y][x] = 'X';
		return (0);
	}
	else if (data->map2[y][x] == 'M')
		return (0);
	data->map2[y][x] = 'X';
	ft_algo(data, x + 1, y);
	ft_algo(data, x - 1, y);
	ft_algo(data, x, y + 1);
	ft_algo(data, x, y - 1);
	if (e == 1 && c == data->c)
		return (1);
	else
		return (0);
}

void	ft_flood_fill(t_data *data)
{
	ft_map_dup(data);
	if (ft_algo(data, data->x_p, data->y_p) != 1)
	{
		write(2, "Error\nInvalid path in the map!\n", 31);
		ft_free_map2(data);
		ft_finish(data);
	}
	else
		ft_free_map2(data);
}
