#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd_1;
	int 	fd_2;
	char	*line;

	if (argc == 1)
	{
		fd_1 = 0;
		fd_2 = 0;
	}
	else if (argc == 3)
	{
		fd_1 = open(argv[1], O_RDONLY);
		fd_2 = open(argv[2], O_RDONLY);
	}
	else
		return (2);
	while (get_next_line(fd_1, &line) == 1)
	{
		ft_putendl("int the main, line is ");
		ft_putendl(line);
		free(line);
		if (get_next_line(fd_2, &line) == 1)
		{
			ft_putendl(line);
			free(line);
		}
	}
	return (0);
}
