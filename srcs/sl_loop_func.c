/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_loop_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:59:42 by yichan            #+#    #+#             */
/*   Updated: 2023/02/01 14:11:14 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_move(int keycode, t_book *record)
{
	int	*y;
	int	*x;

	y = &record->data.enemy_co.y;
	x = &record->data.enemy_co.x;
	if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		record->data.enemy_face = keycode;
	if (keycode == KEY_UP && record->map[*y -1][*x] != '1')
		record->data.enemy_co.y--;
	if (keycode == KEY_DOWN && record->map[*y +1][*x] != '1')
		record->data.enemy_co.y++;
	if (keycode == KEY_LEFT && record->map[*y][*x -1] != '1')
		record->data.enemy_co.x--;
	if (keycode == KEY_RIGHT && record->map[*y][*x +1] != '1')
		record->data.enemy_co.x++;
}

void	player_move(int keycode, t_book *record)
{
	int	*y;
	int	*x;

	y = &record->data.player_co.y;
	x = &record->data.player_co.x;
	if (keycode == KEY_A || keycode == KEY_D)
		record->data.player_face = keycode;
	if (keycode == KEY_ESC)
		shut_exit();
	else if (keycode == KEY_W && (record->map[*y -1][*x] != '1'))
		record->data.player_co.y--;
	else if (keycode == KEY_A && record->map[*y][*x -1] != '1')
		record->data.player_co.x--;
	else if (keycode == KEY_S && record->map[*y +1][*x] != '1')
		record->data.player_co.y++;
	else if (keycode == KEY_D && record->map[*y][*x +1] != '1')
		record->data.player_co.x++;
	else
		return ;
	record->steps++;
	ft_putstr_fd("Movement count: ", 1);
	ft_putnbr_fd(record->steps, 1);
	ft_putstr_fd("\n", 1);
}

int	key_enter(int keycode, t_book *record)
{
	if (record->data.player == 1)
		player_move(keycode, record);
	if (record->data.enemy == 1)
		enemy_move(keycode, record);
	if (record->data.enemy_co.x == record->data.player_co.x
		&& record->data.enemy_co.y == record->data.player_co.y)
		ft_error("GAME OVER!\nTry Again Next Time!", 1);
	return (0);
}

void	data_update(t_book *record)
{
	char	*found;

	found = &(record->map[record->data.player_co.y][record->data.player_co.x]);
	if (*found == 'C')
	{
		*found = 'F';
		record->collected++;
	}
	if (*found == 'E' && record->collected == record->data.coll)
	{
		ft_putendl_fd("GAME CLEAR!", 1);
		ft_error("Thanks for Playing!", 0);
	}
}

int	image_update(t_book *record)
{
	record->winfps++;
	mlx_clear_window(record->mlx, record->win);
	project_image(record);
	sl_player_anime(record);
	if (record->data.enemy > 0)
		sl_enemy_anime(record);
	string_put_mod(record);
	if (record->winfps >= FPS)
		record->winfps = 0;
	data_update(record);
	return (0);
}
