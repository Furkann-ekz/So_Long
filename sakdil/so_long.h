#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include <stdbool.h>
# include <stdlib.h>

# include "stdio.h" // pushlamadan önce silinecek

# define BUFFER_SIZE 42

typedef	struct sude
{
	char	**map;
	int		height;
	int		lenght;
	int		c_count;
}t_list;

#endif