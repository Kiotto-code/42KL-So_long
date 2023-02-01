/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:09:52 by yichan            #+#    #+#             */
/*   Updated: 2023/02/01 14:21:12 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, t_coor size, t_coor cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		||ft_strchr("PEC0N", tab[cur.y][cur.x]) == 0)
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_coor){cur.y - 1, cur.x});
	fill(tab, size, (t_coor){cur.y + 1, cur.x});
	fill(tab, size, (t_coor){cur.y, cur.x - 1});
	fill(tab, size, (t_coor){cur.y, cur.x + 1});
}

void	flood_fill(char **tab, t_coor size, t_coor player_co)
{
	int	i;
	int	j;

	fill(tab, size, player_co);
	i = -1;
	while (++i < size.y)
	{
		j = -1;
		while (++j < size.x)
		{
			if (ft_strchr("PECN", tab[i][j]))
				ft_error("Error: No Valid Path", 1);
		}
	}
}
