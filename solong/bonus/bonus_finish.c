/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:36:37 by fekiz             #+#    #+#             */
/*   Updated: 2024/02/10 17:18:01 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	finish_check(t_game *game)
{
	if (game->p_cord.x == game->e_cord.x && game->p_cord.y == game->e_cord.y)
		return (0);
	return (1);
}

void	coin_controls(t_game *game)
{
	int	x;
	int	y;
	int	coin;

	y = 1;
	coin = 0;
	while (game->map[y])
	{
		x = 1;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				coin++;
			x++;
		}
		y++;
	}
	player_x_y(game);
	if (coin == 0 && finish_check(game) == 0)
	{
		write (1, "\n*VALHALLA*\n\n", 13);
		close_game(game);
	}
}
