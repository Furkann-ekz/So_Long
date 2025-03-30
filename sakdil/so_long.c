#include "so_long.h"
#include "stdio.h"
// 21 satır 40 genişlik (64 pikselli kareler için)
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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

char *ft_get_read(int fd)
{
    char *liner;
    char *str = NULL;
    int rd;

    liner = malloc(BUFFER_SIZE + 1);
    if (!liner)
        return (NULL);
    while ((rd = read(fd, liner, BUFFER_SIZE)) > 0)
    {
        liner[rd] = '\0';
        str = ft_strjoin(str, liner);
    }
    free(liner);
    return (str);
}
void	free_exit(char **str, bool x)
{
	int i;

	i = 0;
	while(str[i] && x == true)
	{
		free(str[i]);
		i++;
	}
	free(str);
	exit(1);
}
void find_length_height(char *str, t_list *list)
{
	int i;

	i = 0;
	list->height = 0;
	list->lenght = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (list->height == 0)
				list->lenght = i;
			list->height++;
		}
		i++;
	}
}

void	read_map(char *argv, t_list *list)
{
	int fd;
	int i;
	char *map;
	bool x;
	int p_count = 0;
	int e_count = 0;

	i = -1;
	fd = open(argv, O_RDONLY);
	if(fd < 0)
	{
        printf("Error: Cannot open file\n");
        exit(1);
    }
	map = ft_get_read(fd);
	close(fd);
	if (!map)
        free_exit(NULL, false);
	list->c_count = 0;
	while (map[++i])
	{
		if ((map[i] == '\n' && map[i + 1] && map[i+1] == '\n') || (map[i] == '\n' && map[i + 1] && map[i + 1] == '\0'))
			free_exit(&map, false);
		else if (map[i] == 'P')
			p_count++;
		else if (map[i] == 'E')
			e_count++;
		else if (map[i] == 'C')
			list->c_count++;
		else if (map[i] != '1' && map[i] != '0' && map[i] != '\n')
			free_exit(&map, false);
	}
	if (p_count != 1 || e_count != 1 || list->c_count < 1)
	{
		printf("Error\n");
		free_exit(&map, false);
	}
	
}

bool	name(char *str)
{
	int	i;
	i = 0;
	if (str[0] == '.')
		return (true);
	while (str[i] != '.')
		i++;
	if (ft_strcmp(str + i, ".ber"))
		return (true);
	return (false);
}

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc != 2 || (argv[1] && !argv[1][4]))
	{
		printf("Error: Bad inputs\n");
		return (0);
	}
	if (name(argv[1]) == true)
		return (1);
	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (1);
	read_map(argv[1], list);
	// edit_list(list);

}
