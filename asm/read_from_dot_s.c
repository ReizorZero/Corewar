#include "asm.h"

int		get_file_fd(t_asm *the_asm)
{
	int fd;

	fd = open(the_asm->dot_s_file_name, O_RDONLY);
	if (fd == -1)
		ERROR(ERROR_OPEN_FILE, the_asm->dot_s_file_name);
	return (fd);
}

void	close_file(t_asm *the_asm, int fd)
{
	if (close(fd) == -1)
		ERROR(ERROR_CLOSE_FILE, the_asm->dot_s_file_name);
}

int		read_from_dot_s(t_asm *the_asm)
{
	char	*s;
	int		fd;

	s = NULL;
	fd = get_file_fd(the_asm);
	while (get_next_line(fd, &s) > 0)
	{
		write_line_to_list(the_asm, s);
		free(s);
	}
	close_file(the_asm, fd);
	parse_lines(the_asm);
	return (1);
}
