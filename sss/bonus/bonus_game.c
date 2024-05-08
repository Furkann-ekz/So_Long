/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:51:11 by fekiz             #+#    #+#             */
/*   Updated: 2024/02/13 16:40:14 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_controler(int x, int y, t_game *game)
{
	if (game->map[y][x] == '1')
		return (0);
	return (1);
}

int	en_move_controler(int x, int y, t_game *game)
{
	if (game->map[y][x] == '1')
		return (0);
	return (1);
}

static int	mover(int key, t_game *game)
{
	en_move1(game);
	if (move1(key, game) == 0)
	{
		en_move2(game);
		return (0);
	}
	else if (move2(key, game) == 0)
	{
		en_move1(game);
		return (0);
	}
	else if (move3(key, game) == 0)
	{
		en_move4(game);
		return (0);
	}
	else if (move4(key, game) == 0)
	{
		en_move3(game);
		return (0);
	}
	en_move3(game);
	return (1);
}

static int	key_control(int key, t_game *game)
{
	en_move4(game);
	if (coin_check(game) == 0)
	{
		game->control = 1;
		add_images_bonus(game);
	}
	else
	{
		game->control = 0;
		add_images(game);
	}
	if (game->control == 1)
		add_imgs(game);
	if (mover(key, game) == 0)
		return (0);
	else if (key == 53)
		close_game(game);
	en_move2(game);
	return (1);
}

void	game_start(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error(game);
	game->win = mlx_new_window(game->mlx, game->map_cord.x * 64,
			game->map_cord.y * 64, "so_long_bonus");
	if (!game->win)
		ft_error(game);
	add_images(game);
	add_imgs(game);
	mlx_key_hook(game->win, key_control, game);
	mlx_hook(game->win, 17, 2, close_game, game);
	mlx_loop(game->mlx);
}
