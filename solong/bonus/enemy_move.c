/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:46:38 by fekiz             #+#    #+#             */
/*   Updated: 2024/02/12 20:09:23 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	en_move1(t_game *game)
{
	if (en_move_controler(game->en_cord.x, game->en_cord.y - 1, game))
	{
		game->map[game->en_cord.y][game->en_cord.x] = '0';
		if (game->exit1 == true)
		{
			game->map[game->en_cord.y][game->en_cord.x] = 'E';
			game->exit1 = false;
		}
		game->en_cord.y--;
		lose_control(game);
		game->map[game->en_cord.y][game->en_cord.x] = 'N';
		add_imgs(game);
		if (game->e_cord.x == game->en_cord.x
			&& game->en_cord.y == game->e_cord.y)
			game->exit1 = true;
		coin_controls(game);
		return (0);
	}
	return (1);
}

int	en_move2(t_game *game)
{
	if (en_move_controler(game->en_cord.x, game->en_cord.y + 1, game))
	{
		game->map[game->en_cord.y][game->en_cord.x] = '0';
		if (game->exit1 == true)
		{
			game->map[game->en_cord.y][game->en_cord.x] = 'E';
			game->exit1 = false;
		}
		game->en_cord.y++;
		lose_control(game);
		game->map[game->en_cord.y][game->en_cord.x] = 'N';
		add_imgs(game);
		if (game->e_cord.x == game->en_cord.x
			&& game->en_cord.y == game->e_cord.y)
			game->exit1 = true;
		coin_controls(game);
		return (0);
	}
	return (1);
}

int	en_move3(t_game *game)
{
	if (en_move_controler(game->en_cord.x - 1, game->en_cord.y, game))
	{
		game->map[game->en_cord.y][game->en_cord.x] = '0';
		if (game->exit1 == true)
		{
			game->map[game->en_cord.y][game->en_cord.x] = 'E';
			game->exit1 = false;
		}
		game->en_cord.x--;
		lose_control(game);
		game->map[game->en_cord.y][game->en_cord.x] = 'N';
		add_imgs(game);
		if (game->e_cord.x == game->en_cord.x
			&& game->en_cord.y == game->e_cord.y)
			game->exit1 = true;
		coin_controls(game);
		return (0);
	}
	return (1);
}

int	en_move4(t_game *game)
{
	if (en_move_controler(game->en_cord.x + 1, game->en_cord.y, game))
	{
		game->map[game->en_cord.y][game->en_cord.x] = '0';
		if (game->exit1 == true)
		{
			game->map[game->en_cord.y][game->en_cord.x] = 'E';
			game->exit1 = false;
		}
		game->en_cord.x++;
		lose_control(game);
		game->map[game->en_cord.y][game->en_cord.x] = 'N';
		add_imgs(game);
		if (game->e_cord.x == game->en_cord.x
			&& game->en_cord.y == game->e_cord.y)
			game->exit1 = true;
		coin_controls(game);
		return (0);
	}
	return (1);
}
