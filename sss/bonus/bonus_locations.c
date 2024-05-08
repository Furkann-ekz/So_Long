/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_locations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:48:11 by fekiz             #+#    #+#             */
/*   Updated: 2024/02/15 14:46:36 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	map_character_checker(char *mp)
{
	int	i;

	i = 0;
	while (mp[i] != '\0')
	{
		if (mp[i] == 'E' || mp[i] == 'C' || mp[i] == 'P'
			|| mp[i] == '1' || mp[i] == '0' || mp[i] == '\n')
			i++;
		else
			return (1);
	}
	return (0);
}

void	player_x_y(t_game *list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (list->map[i])
	{
		j = 0;
		while (list->map[i][j])
		{
			if (list->map[i][j] == 'P')
			{
				list->p_cord.y = i;
				list->p_cord.x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	exit_x_y(t_game *list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (list->map[i])
	{
		j = 0;
		while (list->map[i][j])
		{
			if (list->map[i][j] == 'E')
			{
				list->e_cord.y = i;
				list->e_cord.x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	coordinats(t_game *list)
{
	int	x;
	int	y;

	y = 0;
	while (list->map[y] != NULL)
	{
		x = 0;
		while (list->map[y][x] != '\0')
		{
			if (list->map[y][x] == 'N')
			{
				list->en_cord.y = y;
				list->en_cord.x = x;
			}
			x++;
		}
		y++;
	}
	list->map_cord.y = y;
	list->map_cord.x = x;
	player_x_y(list);
	exit_x_y(list);
}

void	ft_error(t_game *list)
{
	get_free(list);
	write (1, "error\n", 6);
	exit (1);
}
