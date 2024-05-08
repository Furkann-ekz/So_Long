/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:48:44 by fekiz             #+#    #+#             */
/*   Updated: 2024/02/14 12:48:20 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*newstr(int i, char *str, int nbr)
{
	i = i + 8;
	str = (char *)malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	i--;
	str[i] = '\0';
	str[0] = 'm';
	str[1] = 'o';
	str[2] = 'v';
	str[3] = 'e';
	str[4] = 's';
	str[5] = ':';
	str[6] = ' ';
	while (nbr)
	{
		i--;
		str[i] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (str);
}

char	*ft_itoa(int num)
{
	char	*str;
	int		i;
	int		nbr;

	i = 0;
	nbr = num;
	str = NULL;
	while (num)
	{
		num /= 10;
		i++;
	}
	str = newstr(i, str, nbr);
	return (str);
}

void	put_str(t_game *game)
{
	char	*str;

	game->moves++;
	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 64, 64, 0xFFFFFF, str);
	free(str);
}
