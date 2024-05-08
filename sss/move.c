/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:24:45 by fekiz             #+#    #+#             */
/*   Updated: 2024/02/08 16:09:29 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move1(int key, t_game *game)
{
	if ((key == 126 || key == 13)
		&& move_controler(game->p_cord.x, game->p_cord.y - 1, game))
	{
		game->map[game->p_cord.y][game->p_cord.x] = '0';
		if (game->exit == true)
		{
			game->map[game->p_cord.y][game->p_cord.x] = 'E';
			game->exit = false;
		}
		game->p_cord.y--;
		game->map[game->p_cord.y][game->p_cord.x] = 'P';
		add_imgs(game);
		if (game->e_cord.x == game->p_cord.x
			&& game->p_cord.y == game->e_cord.y)
			game->exit = true;
		coin_controls(game);
		return (0);
	}
	return (1);
}

int	move2(int key, t_game *game)
{
	if ((key == 125 || key == 1)
		&& move_controler(game->p_cord.x, game->p_cord.y + 1, game))
	{
		game->map[game->p_cord.y][game->p_cord.x] = '0';
		if (game->exit == true)
		{
			game->map[game->p_cord.y][game->p_cord.x] = 'E';
			game->exit = false;
		}
		game->p_cord.y++;
		game->map[game->p_cord.y][game->p_cord.x] = 'P';
		if (game->e_cord.x == game->p_cord.x
			&& game->p_cord.y == game->e_cord.y)
			game->exit = true;
		add_imgs(game);
		coin_controls(game);
		return (0);
	}
	return (1);
}

int	move3(int key, t_game *game)
{
	if ((key == 123 || key == 0)
		&& move_controler(game->p_cord.x - 1, game->p_cord.y, game))
	{
		game->map[game->p_cord.y][game->p_cord.x] = '0';
		if (game->exit == true)
		{
			game->map[game->p_cord.y][game->p_cord.x] = 'E';
			game->exit = false;
		}
		game->p_cord.x--;
		game->map[game->p_cord.y][game->p_cord.x] = 'P';
		if (game->e_cord.x == game->p_cord.x
			&& game->p_cord.y == game->e_cord.y)
			game->exit = true;
		add_imgs(game);
		coin_controls(game);
		return (0);
	}
	return (1);
}

int	move4(int key, t_game *game)
{
	if ((key == 124 || key == 2)
		&& move_controler(game->p_cord.x + 1, game->p_cord.y, game))
	{
		game->map[game->p_cord.y][game->p_cord.x] = '0';
		if (game->exit == true)
		{
			game->map[game->p_cord.y][game->p_cord.x] = 'E';
			game->exit = false;
		}
		game->p_cord.x++;
		game->map[game->p_cord.y][game->p_cord.x] = 'P';
		if (game->e_cord.x == game->p_cord.x
			&& game->p_cord.y == game->e_cord.y)
			game->exit = true;
		add_imgs(game);
		coin_controls(game);
		return (0);
	}
	return (1);
}
