/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_put_stringmod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:12:19 by yichan            #+#    #+#             */
/*   Updated: 2023/02/01 14:11:50 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	string_put_mod(t_book *record)
{
	char	*steps;
	char	*str;

	steps = ft_itoa(record->steps);
	str = ft_strjoin("Movement count: ", steps);
	mlx_string_put(record->mlx, record->win, 30, 45, BLACK, str);
	free(steps);
	free(str);
	steps = ft_itoa(record->collected);
	str = ft_strjoin("Collected count: ", steps);
	mlx_string_put(record->mlx, record->win, 10, 15, BLACK, str);
	free(steps);
	free(str);
}
