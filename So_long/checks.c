/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:58:19 by abel-baz          #+#    #+#             */
/*   Updated: 2024/03/28 15:58:30 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_elements_number_check(t_data *data)
{
	if (data->p != 1)
	{
		write(2, "Error\nThe map must contain 1 player!\n", 37);
		ft_finish(data);
	}
	if (data->e != 1)
	{
		write(2, "Error\nThe map must contain 1 exit!\n", 35);
		ft_finish(data);
	}
	if (data->c < 1)
	{
		write(2, "Error\nThe map must contain at least 1 collectible!\n", 51);
		ft_finish(data);
	}
	if (data->m != 1)
	{
		write(2, "Error\nThe map must contain 1 enemy!\n", 36);
		ft_finish(data);
	}
}

void	ft_lines_and_columns(t_data *data)
{
	if (data->lines < 3 || data->lines * SIZE > 1080)
	{
		write(2, "Error\nInvalid lines length!\n", 28);
		ft_finish(data);
	}
	if (data->columns < 3 || data->columns * SIZE > 1920)
	{
		write(2, "Error\nInvalid columns length!\n", 28);
		ft_finish(data);
	}
	ft_coordinates_and_count(data);
	ft_elements_number_check(data);
}

void	ft_elements_check(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->lines)
	{
		x = 0;
		while (x < data->columns)
		{
			if (data->map[y][x] == '1' || data->map[y][x] == '0'
				|| data->map[y][x] == 'P' || data->map[y][x] == 'C'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'M')
			{
				x++;
			}
			else
			{
				write(2, "Error\nInvalid elements!\n", 24);
				ft_finish(data);
			}
		}
		y++;
	}
	ft_lines_and_columns(data);
}

void	ft_check_walls(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->columns)
	{
		if (data->map[0][x] != '1' || data->map[data->lines - 1][x] != '1')
		{
			write(2, "Error\nMap is not surrounded by walls\n", 37);
			ft_finish(data);
		}
		x++;
	}
	while (y < data->lines)
	{
		if (data->map[y][0] != '1' || data->map[y][data->columns - 1] != '1')
		{
			write(2, "Error\nMap is not surrounded by walls\n", 37);
			ft_finish(data);
		}
		y++;
	}
}

void	ft_rectangle_check(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->lines)
	{
		x = 0;
		while (data->map[y][x] != '\0')
			x++;
		if (x != data->columns)
		{
			write(2, "Error\nThis map is not a rectangle!\n", 35);
			exit (1);
		}
		y++;
	}
	ft_check_walls(data);
	ft_elements_check(data);
}
