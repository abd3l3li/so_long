/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:01:30 by abel-baz          #+#    #+#             */
/*   Updated: 2024/03/28 16:01:36 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map(t_data *data, char *file)
{
	data->fd = open(file, O_RDONLY);
	if (data->fd < 0)
		ft_finish(data);
	data->lines = ft_count_lines(data);
	close(data->fd);
	if (data->lines == 0)
		ft_finish(data);
	data->map = calloc(data->lines + 1, sizeof(char *));
	data->fd = open(file, O_RDONLY);
	if (data->fd < 0)
		ft_finish(data);
	ft_fill_map(data);
	close(data->fd);
	data->columns = ft_strlen(data->map[0]);
	ft_rectangle_check(data);
	ft_flood_fill(data);
	data->win = mlx_new_window(data->mlx, data->columns * SIZE, data->lines
			* SIZE, "so_long");
	if (data->win == NULL)
	{
		free(data->win);
		ft_finish(data);
	}
	ft_fill_window(data);
}

void	ft_img2(t_data *data)
{
	data->player = mlx_xpm_file_to_image(data->mlx, PLAYER, &data->x,
			&data->y);
	if (data->player == NULL)
		ft_finish(data);
	data->rplayer = mlx_xpm_file_to_image(data->mlx, RPLAYER, &data->x,
			&data->y);
	if (data->rplayer == NULL)
		ft_finish(data);
	data->lplayer = mlx_xpm_file_to_image(data->mlx, LPLAYER, &data->x,
			&data->y);
	if (data->lplayer == NULL)
		ft_finish(data);
	data->exit = mlx_xpm_file_to_image(data->mlx, EXIT, &data->x, &data->y);
	if (data->exit == NULL)
		ft_finish(data);
	data->noexit = mlx_xpm_file_to_image(data->mlx, NOEXIT, &data->x, &data->y);
	if (data->noexit == NULL)
		ft_finish(data);
}

void	ft_img(t_data *data)
{
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL, &data->x, &data->y);
	if (data->wall == NULL)
		ft_finish(data);
	data->space = mlx_xpm_file_to_image(data->mlx, SPACE, &data->x, &data->y);
	if (data->space == NULL)
		ft_finish(data);
	data->ctbl = mlx_xpm_file_to_image(data->mlx, CTBL, &data->x, &data->y);
	if (data->ctbl == NULL)
		ft_finish(data);
	data->enemy = mlx_xpm_file_to_image(data->mlx, ENEMY, &data->x, &data->y);
	if (data->enemy == NULL)
		ft_finish(data);
	data->enemy_plus = mlx_xpm_file_to_image(data->mlx, ENEMYP,
			&data->x, &data->y);
	if (data->enemy_plus == NULL)
		ft_finish(data);
	ft_img2(data);
}

void	ft_check_file(t_data *data, char *file)
{
	int	len;

	len = ft_strlen(file);
	data->fd = open(file, O_RDONLY);
	if (ft_strncmp(file + (len - 4), ".ber", 4) != 0
		|| len < 10)
	{
		write(2, "Error\nInvalid extension\n", 24);
		close(data->fd);
		exit(1);
	}
	if (data->fd < 0)
	{
		write(2, "Error\nInvalid FD\n", 17);
		close(data->fd);
		exit(1);
	}
	close(data->fd);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		ft_init(&data);
		ft_check_file(&data, av[1]);
		data.mlx = mlx_init();
		if (data.mlx == NULL)
			return (0);
		ft_img(&data);
		ft_map(&data, av[1]);
		mlx_hook(data.win, KeyPress, KeyPressMask, ft_handler, &data);
		mlx_hook(data.win, DestroyNotify, ButtonPressMask, ft_finish, &data);
		mlx_loop_hook(data.mlx, ft_animation, &data);
		mlx_loop(data.mlx);
	}
	else
	{
		write(2, "Error\nProvide the map file\n", 27);
		return (1);
	}
	return (0);
}
