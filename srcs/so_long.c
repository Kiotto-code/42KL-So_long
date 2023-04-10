/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:37:21 by yichan            #+#    #+#             */
/*   Updated: 2023/04/10 22:35:04 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief initialize struct
 * 
 * @param record variable of the book
 */

void	init_data(t_book *record)
{
	record->data.wall = 0;
	record->data.empty = 0;
	record->data.coll = 0;
	record->data.exit = 0;
	record->data.exit_co = (t_coor){0, 0};
	record->data.player = 0;
	record->data.player_co = (t_coor){-1, -1};
	record->data.player_face = KEY_D;
	record->data.enemy = 0;
	record->data.enemy_co = (t_coor){0, 0};
	record->data.enemy_face = KEY_LEFT;
}

void	init_pics(t_book *record)
{
	record->pics.size = (t_coor){0, 0};
}

void	init_record(t_book *record)
{
	record->mlx = mlx_init();
	record->win = 0;
	record->winsize = (t_coor){0, 0};
	record->winfps = 0;
	record->mapsize = (t_coor){0, 0};
	init_data(record);
	init_pics(record);
	record->steps = 0;
	record->collected = 0;
}

/* 2 -> ON_KEYDOWN mlx_key_hook*/
/* 17 -> ON_DESTROY */
/* (1L<<0)	KeyPressMask*/

void	open_image(t_book *record)
{
	record->win = mlx_new_window(record->mlx, record->mapsize.x * INTERVAL,
			record->mapsize.y * INTERVAL, "So_long!");
	if (record->win == NULL)
	{
		free(record->win);
		ft_error("win not open", 1);
	}
	insert_sprites(record);
	mlx_hook(record->win, 17, 0, &shut_exit, record);
	mlx_hook(record->win, 2, 1L << 0, &key_enter, record);
	if (record->data.enemy_co.x < record->data.player_co.x
		&& record->data.enemy > 0 && record->data.player > 0)
	{
		record->data.enemy_face = KEY_RIGHT;
		record->data.player_face = KEY_A;
	}
	mlx_loop_hook(record->mlx, &image_update, record);
	mlx_loop(record->mlx);
}

int	main(int ac, char **av)
{
	t_book	record;

	init_record(&record);
	check_map(&record, ac, av);
	open_image(&record);
	return (ft_error("Thanks for playing", 0), 0);
}
