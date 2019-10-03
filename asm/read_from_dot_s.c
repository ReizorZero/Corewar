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

void	write_line_to_list(t_asm *the_asm, char *s)
{
	if (!the_asm->lines)
		the_asm->lines = new_line(s);
	else
	{
		the_asm->lines->next = new_line(s);
		the_asm->lines = the_asm->lines->next;
	}
	if (!the_asm->lines_top)
		the_asm->lines_top = the_asm->lines;
}

int		read_from_dot_s(t_asm *the_asm)
{
	char	*s;
	int		fd;

	s = NULL;
	fd = get_file_fd(the_asm);//RANDOM ERROR OCUURES FROM TIME TO TIME: UNABLE TO OPEN FILE 0
	//RANDOM SEGV FROM TIME TO TIME -- WHYYYYYYYY THE FUUUUUCK?
	while (get_next_line(fd, &s) > 0)
	{
		write_line_to_list(the_asm, s);
		//free(s);
	}
	close_file(the_asm, fd);
	parse_lines(the_asm);
	return (1);
}