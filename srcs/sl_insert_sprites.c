/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_insert_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:48:30 by yichan            #+#    #+#             */
/*   Updated: 2023/01/31 17:50:13 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*mlx_xpm_ftm_mod(void *mlx_ptr, char *filename, int *width, int *height)
{
	void	*ret;

	ret = mlx_xpm_file_to_image(mlx_ptr, filename, width, height);
	if (ret == NULL)
	{
		ft_putendl_fd(filename, 1);
		ft_error(" Img Files Missing", 1);
	}
	return (ret);
}

void	insert_dorae(t_book *record)
{
	record->pics.img_p_l[0] = mlx_xpm_ftm_mod(record->mlx,
			"img/left_2.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_p_l[1] = mlx_xpm_ftm_mod(record->mlx,
			"img/left_3.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_p_l[2] = mlx_xpm_ftm_mod(record->mlx,
			"img/left_4.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_p_l[3] = mlx_xpm_ftm_mod(record->mlx,
			"img/left_5.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_p_l[4] = mlx_xpm_ftm_mod(record->mlx,
			"img/left_6.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_p_l[5] = mlx_xpm_ftm_mod(record->mlx,
			"img/left_7.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_p_r[0] = mlx_xpm_ftm_mod(record->mlx,
			"img/right_2.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_p_r[1] = mlx_xpm_ftm_mod(record->mlx,
			"img/right_3.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_p_r[2] = mlx_xpm_ftm_mod(record->mlx,
			"img/right_4.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_p_r[3] = mlx_xpm_ftm_mod(record->mlx,
			"img/right_5.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_p_r[4] = mlx_xpm_ftm_mod(record->mlx,
			"img/right_6.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_p_r[5] = mlx_xpm_ftm_mod(record->mlx,
			"img/right_7.xpm", &record->pics.size.x, &record->pics.size.y);
}

void	insert_sprites(t_book *record)
{
	insert_dorae(record);
	record->pics.img_collect = mlx_xpm_ftm_mod(record->mlx,
			"img/collect.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_exit = mlx_xpm_ftm_mod(record->mlx,
			"img/exit.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_wall = mlx_xpm_ftm_mod(record->mlx,
			"img/wall.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_floor = mlx_xpm_ftm_mod(record->mlx,
			"img/floor.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_enemy_d[0] = mlx_xpm_ftm_mod(record->mlx,
			"img/mouse_1.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_enemy_d[1] = mlx_xpm_ftm_mod(record->mlx,
			"img/mouse_2.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_enemy_l[0] = mlx_xpm_ftm_mod(record->mlx,
			"img/mouse_3.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_enemy_l[1] = mlx_xpm_ftm_mod(record->mlx,
			"img/mouse_4.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_enemy_r[0] = mlx_xpm_ftm_mod(record->mlx,
			"img/mouse_5.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_enemy_r[1] = mlx_xpm_ftm_mod(record->mlx,
			"img/mouse_6.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_enemy_u[0] = mlx_xpm_ftm_mod(record->mlx,
			"img/mouse_7.xpm", &record->pics.size.x, &record->pics.size.y);
	record->pics.img_enemy_u[1] = mlx_xpm_ftm_mod(record->mlx,
			"img/mouse_8.xpm", &record->pics.size.x, &record->pics.size.y);
}
