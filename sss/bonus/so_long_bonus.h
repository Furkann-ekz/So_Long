/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:48:51 by fekiz             #+#    #+#             */
/*   Updated: 2024/02/13 16:40:21 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../mlx/mlx.h"

typedef struct coordinats
{
	int	x;
	int	y;
}				t_cord;

typedef struct images
{
	void	*e;
	void	*p;
	void	*wall;
	void	*zero;
	void	*c;
	void	*en;
}			t_images;

typedef struct game_list
{
	void		*mlx;
	void		*win;
	char		**map;
	char		**temp;
	int			control;
	int			p;
	int			e;
	int			c;
	int			en;
	int			moves;
	bool		exit;
	bool		exit1;
	t_cord		map_cord;
	t_cord		p_cord;
	t_cord		e_cord;
	t_cord		en_cord;
	t_images	imgs;
}				t_game;

void	put_str(t_game *game);
void	add_images_bonus(t_game *game);
int		coin_check(t_game *game);
size_t	ft_strlen(char *str);
char	**ft_split(char *s, char c);
void	coordinats(t_game *list);
void	map_creator(char *s, t_game *list);
int		map_controller(char *mp, t_game *list);
void	wall_controller(t_game *list);
void	first_and_last_walls(t_game *list, int i, int j);
void	get_free(t_game *list);
void	ft_error(t_game *list);
int		move_control(char **str);
void	wall_controller_two(t_game *list);
void	empty_line_control(char *str, t_game *list);
char	*ft_get_read(int fd);
void	arg_control(char *str, t_game *list);
void	game_edit(t_game *list);
int		map_character_checker(char *mp);
void	player_x_y(t_game *list);
void	game_start(t_game *game);
int		close_game(t_game *list);
void	ft_putnbr(int n);
void	add_imgs(t_game *game);
void	add_images(t_game *game);
int		move_controler(int x, int y, t_game *game);
int		move1(int key, t_game *game);
int		move2(int key, t_game *game);
int		move3(int key, t_game *game);
int		move4(int key, t_game *game);
void	coin_controls(t_game *game);
int		en_move1(t_game *game);
int		en_move2(t_game *game);
int		en_move3(t_game *game);
int		en_move4(t_game *game);
int		en_move_controler(int x, int y, t_game *game);
void	lose_control(t_game *game);
char	*ft_itoa(int num);

#endif
