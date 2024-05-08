/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:50:27 by fekiz             #+#    #+#             */
/*   Updated: 2024/02/07 19:26:07 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	first_and_last_walls(t_game *list, int i, int j)
{
	while (list->map[0][i])
	{
		if (list->map[0][i] == '1')
			i++;
		else
			ft_error(list);
	}
	i = 0;
	while (list->map[j][i])
	{
		if (list->map[j][i] == '1')
			i++;
		else
			ft_error(list);
	}
}

void	wall_controller(t_game *list)
{
	int	j;
	int	i;
	int	c;

	i = 0;
	c = list->map_cord.x - 1;
	j = list->map_cord.y - 1;
	first_and_last_walls(list, i, j);
	i = 1;
	while (list->map[i] && i < j)
	{
		if (list->map[i][0] == '1' && list->map[i][c] == '1')
			i++;
		else
			ft_error(list);
	}
}

int	map_controller(char *mp, t_game *list)
{
	int	i;

	i = 0;
	while (mp[i] != 0)
	{
		if (mp[i] == 'C')
			list->c++;
		else if (mp[i] == 'P')
			list->p++;
		else if (mp[i] == 'E')
			list->e++;
		i++;
	}
	i = 0;
	while (mp[i])
	{
		if (mp[i] != 'E' && mp[i] != 'C' && mp[i] != 'P'
			&& mp[i] != '1' && mp[i] != '0' && mp[i] != '\n')
			return (1);
		i++;
	}
	if (list->p != 1 || list->c == 0 || list->e != 1)
		return (1);
	return (0);
}

void	map_creator(char *s, t_game *list)
{
	int		fd;
	char	*mp;

	mp = NULL;
	fd = open(s, O_RDONLY, 0777);
	if (fd == -1)
		ft_error(list);
	mp = ft_get_read(fd);
	close(fd);
	if (map_controller(mp, list) == 0)
	{
		empty_line_control(mp, list);
		list->map = ft_split(mp, '\n');
		list->temp = ft_split(mp, '\n');
		free(mp);
		coordinats(list);
		wall_controller(list);
		wall_controller_two(list);
	}
	else
	{
		free(mp);
		ft_error(list);
	}
}
