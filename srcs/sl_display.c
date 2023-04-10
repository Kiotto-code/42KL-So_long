/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:35:34 by yichan            #+#    #+#             */
/*   Updated: 2023/04/10 22:35:02 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	shut_exit(void)
{
	ft_putendl_fd("THANK YOU FOR PLAYING THIS GAME !", 1);
	exit(0);
	return (0);
}

void	project_image(t_book *record)
{
	int	i;
	int	j;

	j = -1;
	while (++j < record->mapsize.y)
	{
		i = -1;
		while (++i < record->mapsize.x)
		{
			mlx_put_image_to_window(record->mlx, record->win,
				record->pics.img_floor, i * INTERVAL, j * INTERVAL);
			if (record->map[j][i] == '1')
				mlx_put_image_to_window(record->mlx, record->win,
					record->pics.img_wall, i * INTERVAL, j * INTERVAL);
			if (record->map[j][i] == 'C')
				mlx_put_image_to_window(record->mlx, record->win,
					record->pics.img_collect, i * INTERVAL +20 + record->winfps
					/ FPH, j * INTERVAL +20 + record->winfps / FPH);
			if (record->map[j][i] == 'E')
				mlx_put_image_to_window(record->mlx, record->win,
					record->pics.img_exit, i * INTERVAL, j * INTERVAL);
		}
	}
}

void	sl_player_anime(t_book *record)
{
	int	i;

	i = record->winfps / PACE;
	if (i >= 6)
		i = 5;
	if (record->data.player_face == KEY_A)
	{
		mlx_put_image_to_window(record->mlx, record->win,
			record->pics.img_p_l[i], record->data.player_co.x * INTERVAL,
			record->data.player_co.y * INTERVAL);
	}
	else if (record->data.player_face == KEY_D)
	{
		mlx_put_image_to_window(record->mlx, record->win,
			record->pics.img_p_r[i], record->data.player_co.x * INTERVAL,
			record->data.player_co.y * INTERVAL);
	}
}

void	sl_enemy_anime_ud(t_book *record, int i)
{
	if (record->data.enemy_face == KEY_UP)
	{
		mlx_put_image_to_window(record->mlx, record->win,
			record->pics.img_enemy_u[i], record->data.enemy_co.x * INTERVAL +10,
			record->data.enemy_co.y * INTERVAL +10);
	}
	if (record->data.enemy_face == KEY_DOWN)
	{
		mlx_put_image_to_window(record->mlx, record->win,
			record->pics.img_enemy_d[i], record->data.enemy_co.x * INTERVAL +10,
			record->data.enemy_co.y * INTERVAL +10);
	}
}

void	sl_enemy_anime(t_book *record)
{
	int	i;

	i = record->winfps / FPH;
	if (i >= 2)
		i = 1;
	if (record->data.enemy_face == KEY_LEFT)
	{
		mlx_put_image_to_window(record->mlx, record->win,
			record->pics.img_enemy_l[i], record->data.enemy_co.x * INTERVAL +10,
			record->data.enemy_co.y * INTERVAL +10);
	}
	if (record->data.enemy_face == KEY_RIGHT)
	{
		mlx_put_image_to_window(record->mlx, record->win,
			record->pics.img_enemy_r[i], record->data.enemy_co.x * INTERVAL +10,
			record->data.enemy_co.y * INTERVAL +10);
	}
	sl_enemy_anime_ud(record, i);
}
