/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:07:03 by yichan            #+#    #+#             */
/*   Updated: 2023/02/01 14:10:30 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_border_ud(t_book *record)
{
	int	i;

	i = 0;
	while (record->map[0][i] != '\0')
	{
		if (record->map[0][i] != '1')
			ft_error ("Error\n Wall UD not complete", 1);
		if (record->map[record->mapsize.y - 1][i] != '1')
			ft_error ("Error\n Wall UD D not complete", 1);
		i++;
	}
}

void	check_border_lr(char *str)
{
	if (str[0] == '1' && str[ft_strlen(str)-2] == '1')
		return ;
	ft_error ("Error\n Wall LR not complete", 1);
}

char	*join_map(t_book *record, char *mapline, char *str, int fd)
{
	record->mapsize.x = record->mapsize.x - 1;
	while (str)
	{
		mapline = ft_strjoinf(mapline, str);
		free (str);
		record->mapsize.y++;
		str = get_next_line(fd);
		if (str != NULL)
		{
			if ((int)ft_maplen(str) != record->mapsize.x)
				ft_error("Error\n it is not a quadrilateral", 1);
			check_border_lr(str);
		}
	}
	return (mapline);
}

void	check_line(char *path, t_book *record)
{
	int		fd;
	char	*str;
	char	*mapline;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error("Error\n file error", 1);
	str = get_next_line(fd);
	if (str == 0)
		ft_error("Error\n empty map was read", 1);
	record->mapsize.x = ft_strlen(str);
	mapline = ft_calloc(1, sizeof(char *));
	mapline = join_map(record, mapline, str, fd);
	record->map = ft_split(mapline, '\n');
	check_border_ud(record);
	free(mapline);
}

void	check_map(t_book *record, int ac, char **av)
{
	if (ac != 2)
		ft_error("Error\n wrong argument", 1);
	if (ft_strcmp(ft_strend(av[1], 4), ".ber") != 0)
		ft_error("Error\n invalid map extension", 1);
	check_line(av[1], record);
	scan_map(record);
	check_data(record);
	check_valid_path(record);
}
