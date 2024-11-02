/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:59:07 by abel-baz          #+#    #+#             */
/*   Updated: 2024/03/28 15:59:19 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_animation(t_data *data)
{
	static int	n;

	if (n <= 20)
		mlx_put_image_to_window(data->mlx, data->win, data->enemy,
			data->x_m * SIZE, data->y_m * SIZE);
	else if (n <= 40)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->enemy_plus,
			data->x_m * SIZE, data->y_m * SIZE);
		if (n == 40)
			n = 0;
	}
	n++;
	return (0);
}

void	ft_fill_map(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (i < data->lines)
	{
		str = get_next_line(data->fd);
		if (!str)
		{
			free(str);
			ft_finish(data);
			exit(0);
		}
		data->map[i] = ft_strtrim(str, "\n");
		free(str);
		i++;
	}
}

void	to_be_continue(t_data *data)
{
	if (data->map[data->i][data->j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall,
			data->j * SIZE, data->i * SIZE);
	else if (data->map[data->i][data->j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->space,
			data->j * SIZE, data->i * SIZE);
	else if (data->map[data->i][data->j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->ctbl,
			data->j * SIZE, data->i * SIZE);
	else if (data->map[data->i][data->j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player,
			data->j * SIZE, data->i * SIZE);
	else if (data->map[data->i][data->j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit,
			data->j * SIZE, data->i * SIZE);
}

void	ft_fill_window(t_data *data)
{
	while (data->i < data->lines)
	{
		data->j = 0;
		while (data->map[data->i][data->j] != '\0')
		{
			to_be_continue(data);
			data->j++;
		}
		data->i++;
	}
}
