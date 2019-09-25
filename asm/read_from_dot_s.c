#include "asm.h"

int		get_file_fd(t_asm *the_asm)
{
	int fd;

	fd = open(the_asm->dot_s_file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("Error. Unable to open file %s\n", the_asm->dot_s_file_name);
		exit(0);
	}
	return (fd);
}

void	close_file(t_asm *the_asm, int fd)
{
	if (close(fd) == -1)
	{
		printf("Error. Unable to close file %s\n", the_asm->dot_s_file_name);
		exit(0);
	}
}

int		read_from_dot_s(t_asm *the_asm)
{
	char	*s;
	int		fd;

	s = NULL;
	fd = get_file_fd(the_asm);//RANDOM ERROR OCUURES FROM TIME TO TIME: UNABLE TO OPEN FILE 0
	while (get_next_line(fd, &s) > 0)
		parse_line(the_asm, s);
	close_file(the_asm, fd);
	return (1);
}