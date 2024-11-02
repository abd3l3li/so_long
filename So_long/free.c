/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:00:25 by abel-baz          #+#    #+#             */
/*   Updated: 2024/03/28 16:00:29 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	ft_free_map2(t_data *data)
{
	int	i;

	i = 0;
	while (data->map2[i])
	{
		free(data->map2[i]);
		i++;
	}
	free(data->map2);
}

void	ft_free_player(t_data *data)
{
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->rplayer)
		mlx_destroy_image(data->mlx, data->rplayer);
	if (data->lplayer)
		mlx_destroy_image(data->mlx, data->lplayer);
}

int	ft_finish(t_data *data)
{
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->space)
		mlx_destroy_image(data->mlx, data->space);
	ft_free_player(data);
	if (data->ctbl)
		mlx_destroy_image(data->mlx, data->ctbl);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->noexit)
		mlx_destroy_image(data->mlx, data->noexit);
	if (data->enemy)
		mlx_destroy_image(data->mlx, data->enemy);
	if (data->enemy_plus)
		mlx_destroy_image(data->mlx, data->enemy_plus);
	if (data->map)
		ft_free_map(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
