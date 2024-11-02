/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:01:46 by abel-baz          #+#    #+#             */
/*   Updated: 2024/03/28 16:01:48 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_counter(t_data *data)
{
	char	*moves;

	moves = ft_itoa(data->moves);
	mlx_put_image_to_window(data->mlx, data->win, data->wall, SIZE, 0);
	mlx_string_put(data->mlx, data->win, 54, 25, 0xFF0000, moves);
	free(moves);
}

void	exiting_message(t_data *data, int x, int y)
{
	ft_putnbr(data->moves + 1);
	if (data->map[y][x] == 'M')
		write(1, "CATCHU BUDDY! 👾\n", 19);
	ft_finish(data);
}

void	ft_player(t_data *data, int x, int y, char c)
{
	if (c == 'D')
		mlx_put_image_to_window(data->mlx, data->win, data->rplayer,
			x * SIZE, y * SIZE);
	else if (c == 'A')
		mlx_put_image_to_window(data->mlx, data->win, data->lplayer,
			x * SIZE, y * SIZE);
	else if (c == 'W')
		mlx_put_image_to_window(data->mlx, data->win, data->player,
			x * SIZE, y * SIZE);
	else if (c == 'S')
		mlx_put_image_to_window(data->mlx, data->win, data->player,
			x * SIZE, y * SIZE);
}

void	ft_move(t_data *data, int x, int y, char c)
{
	if (data->map[y][x] == '0' || data->map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->space,
			data->x_p * SIZE, data->y_p * SIZE);
		ft_player(data, x, y, c);
		if (data->map[y][x] == 'C')
			data->c -= 1;
		data->map[data->y_p][data->x_p] = '0';
		data->x_p = x;
		data->y_p = y;
		data->moves++;
		ft_counter(data);
		ft_putnbr(data->moves);
		ft_putchar('\n');
	}
	if (data->c == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->noexit,
			data->x_e * SIZE, data->y_e * SIZE);
	if (data->map[y][x] == 'M')
		exiting_message(data, x, y);
	if (data->map[y][x] == 'E' && data->c == 0)
		exiting_message(data, x, y);
}

int	ft_handler(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_finish(data);
	if (keycode == W)
		ft_move(data, data->x_p, data->y_p - 1, 'W');
	if (keycode == S)
		ft_move(data, data->x_p, data->y_p + 1, 'S');
	if (keycode == A)
		ft_move(data, data->x_p - 1, data->y_p, 'A');
	if (keycode == D)
		ft_move(data, data->x_p + 1, data->y_p, 'D');
	return (0);
}
