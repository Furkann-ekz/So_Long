/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:42:47 by fekiz             #+#    #+#             */
/*   Updated: 2024/02/13 16:50:32 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	coin_check(t_game *game)
{
	int	x;
	int	y;

	y = 1;
	while (game->map[y])
	{
		x = 1;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	add_images_bonus(t_game *game)
{
	int	x;
	int	y;

	game->imgs.e = mlx_xpm_file_to_image(game->mlx, "imgs/nw.xpm", &x, &y);
	if (!game->imgs.e)
		ft_error(game);
	game->imgs.en = mlx_xpm_file_to_image(game->mlx, "imgs/en.xpm", &x, &y);
	if (!game->imgs.en)
		ft_error(game);
	game->imgs.c = mlx_xpm_file_to_image(game->mlx, "imgs/c.xpm", &x, &y);
	if (!game->imgs.c)
		ft_error(game);
	game->imgs.zero = mlx_xpm_file_to_image(game->mlx, "imgs/zero.xpm", &x, &y);
	if (!game->imgs.zero)
		ft_error(game);
	game->imgs.wall = mlx_xpm_file_to_image(game->mlx, "imgs/wall.xpm", &x, &y);
	if (!game->imgs.wall)
		ft_error(game);
}

void	add_images(t_game *game)
{
	int	x;
	int	y;

	game->imgs.p = mlx_xpm_file_to_image(game->mlx, "imgs/p.xpm", &x, &y);
	if (!game->imgs.p)
		ft_error(game);
	game->imgs.en = mlx_xpm_file_to_image(game->mlx, "imgs/en.xpm", &x, &y);
	game->imgs.e = mlx_xpm_file_to_image(game->mlx, "imgs/e.xpm", &x, &y);
	game->imgs.c = mlx_xpm_file_to_image(game->mlx, "imgs/c.xpm", &x, &y);
	game->imgs.zero = mlx_xpm_file_to_image(game->mlx, "imgs/zero.xpm", &x, &y);
	if (!game->imgs.en || !game->imgs.e || !game->imgs.c || !game->imgs.zero)
		ft_error(game);
	game->imgs.wall = mlx_xpm_file_to_image(game->mlx, "imgs/wall.xpm", &x, &y);
	if (!game->imgs.wall)
		ft_error(game);
}

static void	add_image(t_game *game, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.zero, x, y);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.wall, x, y);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.p, x, y);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.c, x, y);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.e, x, y);
	if (c == 'N')
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.en, x, y);
}

void	add_imgs(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_cord.y)
	{
		x = 0;
		while (x < game->map_cord.x)
		{
			add_image(game, game->map[y][x], x * 64, y * 64);
			x++;
		}
		y++;
	}
}
