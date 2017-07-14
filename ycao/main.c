#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		{
			fd = open(argv[1], O_RDONLY);
			char c;
			c = '0' + fd;
			//ft_putchar(c);
		}
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{

		ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
}
