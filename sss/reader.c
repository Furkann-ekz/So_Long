/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:02:35 by fekiz             #+#    #+#             */
/*   Updated: 2024/01/14 15:50:46 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_edit(t_game *list)
{
	list->map = NULL;
	list->temp = NULL;
	list->mlx = NULL;
	list->win = NULL;
	list->imgs.e = NULL;
	list->imgs.p = NULL;
	list->imgs.c = NULL;
	list->imgs.wall = NULL;
	list->imgs.zero = NULL;
	list->exit = false;
	list->p = 0;
	list->c = 0;
	list->e = 0;
	list->moves = 0;
}

static int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (1);
	}
	return (0);
}

void	arg_control(char *str, t_game *list)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.')
			i++;
		else
			break ;
	}
	if (ft_strcmp(str + i, ".ber") == 1)
		ft_error(list);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i] != 0)
		s3[i] = s1[i];
	j = -1;
	while (s2[++j] != 0)
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	free(s1);
	return (s3);
}

char	*ft_get_read(int fd)
{
	char	*liner;
	char	*str;
	int		rd;

	liner = malloc(BUFFER_SIZE + 1);
	rd = 1;
	if (!liner)
		return (NULL);
	while (rd > 0)
	{
		rd = read(fd, liner, BUFFER_SIZE);
		if (rd < 0)
		{
			free(liner);
			return (NULL);
		}
		liner[rd] = '\0';
		if (rd > 0)
			str = ft_strjoin(str, liner);
	}
	liner[ft_strlen(liner) - 1] = '\0';
	free(liner);
	return (str);
}
