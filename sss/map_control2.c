/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:27:24 by fekiz             #+#    #+#             */
/*   Updated: 2024/02/10 17:22:28 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_free(t_game *list)
{
	int	i;

	i = -1;
	if (list->map)
		while (list->map[++i])
			free(list->map[i]);
	i = -1;
	if (list->temp)
		while (list->temp[++i])
			free(list->temp[i]);
	if (list->map)
		free(list->map);
	if (list->temp)
		free(list->temp);
	list->c = 0;
	list->p = 0;
	list->e = 0;
	list->map = 0;
	list->temp = 0;
	free(list);
	list = NULL;
}

static void	ft_fill_flood(int x, int y, t_game *list)
{
	if (x < 0 || x > list->map_cord.x - 1 || y < 0 || y > list->map_cord.y - 1)
		return ;
	if (list->temp[y][x] != '1' && list->temp[y][x] != 'F')
	{
		list->temp[y][x] = 'F';
		ft_fill_flood(x, y - 1, list);
		ft_fill_flood(x, y + 1, list);
		ft_fill_flood(x - 1, y, list);
		ft_fill_flood(x + 1, y, list);
	}
}

int	move_control(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'E' || str[i][j] == 'C'
				|| str[i][j] == 'P')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	wall_controller_two(t_game *list)
{
	int	i;
	int	j;

	j = 0;
	while (list->map[j])
	{
		i = 0;
		while (list->map[j][i])
			i++;
		if (i != list->map_cord.x)
			ft_error(list);
		j++;
	}
	ft_fill_flood(list->p_cord.x, list->p_cord.y, list);
	if (move_control(list->temp) == 1)
		ft_error(list);
}

void	empty_line_control(char *str, t_game *list)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '\n'
			|| (str[i + 1] && str[i] == '\n' && str[i + 1] == '\n')
			|| (str[i + 1] == '\0' && str[i] == '\n'))
			ft_error(list);
		i++;
	}
}
