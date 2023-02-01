/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:49:17 by yichan            #+#    #+#             */
/*   Updated: 2023/02/01 14:10:08 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

/* Mac key codes */
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_UP		126
# define KEY_LEFT	123
# define KEY_DOWN	125
# define KEY_RIGHT	124
# define EXIT_EVENT	17
# define EXIT_MASK	0

/* Colors */
# define BLACK		0

/* Player prefs */
# define FPS		60
# define FPH		30
# define PACE		10
# define AN_MOV		100

// height width 64px
# define INTERVAL	64

// y == row && height;
// x == column && width;
typedef struct s_coor
{
	int	y;
	int	x;
}	t_coor;

typedef struct s_graph
{
	void	*img_p_r[6];
	void	*img_p_l[6];
	void	*img_floor;
	void	*img_wall;
	void	*img_enemy_r[6];
	void	*img_enemy_u[6];
	void	*img_enemy_d[6];
	void	*img_enemy_l[6];
	void	*img_exit;
	void	*img_collect;
	t_coor	size;
}	t_graph;

typedef struct s_data
{
	int		wall;
	int		empty;
	int		coll;
	int		exit;
	t_coor	exit_co;
	int		player;
	t_coor	player_co;
	int		player_face;
	int		enemy;
	t_coor	enemy_co;
	int		enemy_face;
}	t_data;

typedef struct s_book
{
	void			*mlx;
	void			*win;
	t_coor			winsize;
	unsigned int	winfps;
	t_coor			mapsize;
	t_data			data;
	char			**map;
	t_graph			pics;
	int				steps;
	int				collected;
}	t_book;

void	check_map(t_book *record, int ac, char **av);
void	scan_map(t_book *record);
void	check_map(t_book *record, int ac, char **av);
void	check_data(t_book *record);
void	check_valid_path(t_book *record);
void	flood_fill(char **tab, t_coor size, t_coor player_co);
void	insert_sprites(t_book *record);
int		shut_exit(void);
int		key_enter(int keycode, t_book *record);
int		image_update(t_book *record);
void	project_image(t_book *record);
void	sl_player_anime(t_book *record);
void	sl_enemy_anime(t_book *record);
size_t	ft_maplen(const char *s);
void	string_put_mod(t_book *record);

#endif