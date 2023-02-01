/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_scan_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:35:51 by yichan            #+#    #+#             */
/*   Updated: 2023/02/01 14:17:54 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_maplen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	check_valid_path(t_book *record)
{
	char	**tab;
	int		i;

	tab = malloc (sizeof(char *) * record->mapsize.y);
	i = -1;
	while (++i < record->mapsize.y)
		tab[i] = ft_strdup(record->map[i]);
	flood_fill(tab, record->mapsize, record->data.player_co);
	i = -1;
	while (++i < record->mapsize.y)
		free(tab[i]);
	free(tab);
}

void	check_data(t_book *record)
{
	if (record->data.coll == 0)
		ft_error("Error\n No collectible in the map", 1);
	if (record->data.player == 0)
		ft_error("Error\n No player in the map", 1);
	if (record->data.exit == 0)
		ft_error("Error\n No exit in the map", 1);
	if (record->data.enemy > 1)
		ft_error("Error\n More than 1 enemy in the map", 0);
	if (record->data.exit > 1)
		ft_error("Error\n More than 1 exit in the map", 1);
}

void	record_data(t_book *record, int i, int j)
{
	if (record->map[i][j] == '0')
		;
	else if (record->map[i][j] == '1')
		record->data.wall++;
	else if (record->map[i][j] == 'P')
	{
		if (record->data.player_co.x != -1 && record->data.player_co.y != -1)
			ft_error("Error\n More than 1 starting position", 1);
		record->data.player++;
		record->data.player_co = (t_coor){i, j};
	}
	else if (record->map[i][j] == 'E')
	{
		record->data.exit++;
		record->data.exit_co = (t_coor){i, j};
	}
	else if (record->map[i][j] == 'N')
	{
		record->data.enemy++;
		record->data.enemy_co = (t_coor){i, j};
	}
	else if (record->map[i][j] == 'C')
		record->data.coll++;
	else
		ft_error("Error\n Invalid Character in map", 1);
}

void	scan_map(t_book *record)
{
	int		i;
	int		j;

	i = -1;
	while (++i < record->mapsize.y)
	{
		j = -1;
		while (++j < record->mapsize.x)
		{
			record_data(record, i, j);
		}
	}
}
